#include "CustomTicTacToeBoard.h"
#include <string>
#include <sstream>

void CustomTicTacToeBoard::reset()
{
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            board[r][c] = rows * r + c + 1;
        }
    }
}

std::string CustomTicTacToeBoard::toString()
{
    std::ostringstream out;

    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            switch(board[r][c])
            {
                case -1: //-1 is the token for player 1
                    out << 'X';
                    break;
                case 0: //0 is the token for player 2
                    out << 'O';
                    break;
                default:
                    out << board[r][c];
            }
            out << " | ";
        }
        out << '\n';
    }

    return out.str();
}

void CustomTicTacToeBoard::placeToken()
{
    board[r][c] = (turn) ? 0 : -1;
}