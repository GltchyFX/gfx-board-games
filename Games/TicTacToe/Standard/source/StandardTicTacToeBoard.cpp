#include "StandardTicTacToeBoard.h"

void StandardTicTacToeBoard::reset()
{
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            board[r][c] = (rows * r + c + 1) + 48;
        }
    }
}

void StandardTicTacToeBoard::placeToken()
{
    board[r][c] = (turn) ? 'O' : 'X';
}