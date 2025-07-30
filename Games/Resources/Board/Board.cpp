#include "Board.h"
#include <string>
#include <sstream>
#include <cassert>

template<typename T>
void Board<T>::setRow(int r)
{
    assert(r > 0);
    row = r;
}

template<typename T>
int Board<T>::getRow()
{
    return row;
}

template<typename T>
void Board<T>::setCol(int c)
{
    assert(c > 0);
    col = c;
}

template<typename T>
int Board<T>::getCol()
{
    return col;
}

template<typename T>
void Board<T>::clear()
{
    delete[] board;
    board = nullptr;
}

template<typename T>
std::string Board<T>::toString()
{
    std::ostringstream out;
    
    for(int r = 0, r < row; r++)
    {
        for(int c = 0; c < col; c++)
        {
            out << board[r][c];
        }
        out << '\n';
    }

    return out.str();
}