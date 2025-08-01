#ifndef GFX_BOARD_H
#define GFX_BOARD_H

#include <string>
#include <sstream>
#include <cassert>

template<typename T>
class Board
{
    public:
        Board(int r = 3, int c = 3)
        {
            setRow(r);
            setCol(c);
            board = new T*[rows];
            for(int i = 0; i < rows; i++)
            {
                board[i] = new T[cols];
            }
        }
        Board(const Board&) = delete;
        Board& operator=(const Board&) = delete;
        ~Board()
        {
            delete[] board;
        }

        void setRow(int);
        int getRow();

        void setCol(int);
        int getCol();

        virtual void play() = 0;

        void clear();

        virtual void reset() = 0;

        virtual std::string toString();
    protected:
        unsigned int rows, cols;
        T** board;

        virtual bool checkWin() = 0;

        virtual bool checkDraw() = 0;
};

template<typename T>
void Board<T>::setRow(int r)
{
    assert(r > 0);
    rows = r;
}

template<typename T>
int Board<T>::getRow()
{
    return rows;
}

template<typename T>
void Board<T>::setCol(int c)
{
    assert(c > 0);
    cols = c;
}

template<typename T>
int Board<T>::getCol()
{
    return cols;
}

template<typename T>
void Board<T>::clear()
{
    delete[] board;
    board = nullptr;
    rows = 0;
    cols = 0;
}

template<typename T>
std::string Board<T>::toString()
{
    std::ostringstream out;
    
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            out << board[r][c];
        }
        out << '\n';
    }

    return out.str();
}

#endif