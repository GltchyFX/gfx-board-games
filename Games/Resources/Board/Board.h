#ifndef GFX_BOARD_H
#define GFX_BOARD_H

#include <string>

template<typename T>
class Board 
{
    public:
        Board(int r = 3, int c = 3)
        {
            setRow(r);
            setCol(c);
            board = new T[row][col];
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
        unsigned int row, col;
        T** board;

        virtual bool checkWin() = 0;

        virtual bool checkDraw() = 0;
};

#endif