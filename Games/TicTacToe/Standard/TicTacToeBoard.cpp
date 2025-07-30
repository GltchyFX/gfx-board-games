#include "TicTacToeBoard.h"
#include "../../Resources/Board/Board.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <limits>

int TicTacToeBoard::game()
{
    for(int t = 0; t < 9; t++)
    {
        play();
        if(checkWin())
            return ( (turn) ? 2 : 1 );
        turnFlip();
    }
    return 0;
}

void TicTacToeBoard::play()
{
    userInput();
    placeToken();
}

void TicTacToeBoard::reset()
{
    for(int r = 0; r < row; r++)
    {
        for(int c = 0; c < col; c++)
        {
            board[r][c] = SIZE * r + c + 1;
        }
    }
}

std::string TicTacToeBoard::toString()
{
    std::ostringstream out;

    out << Board::toString();

    out << "Player " << ( (turn) ? 2 : 1 ) << " Go!";

    return out.str();
}

void TicTacToeBoard::printBoard()
{
    std::cout << toString() << std::endl;
}

void TicTacToeBoard::revertCell(unsigned int& r, unsigned int& c)
{
    r = (userCell - 1) / SIZE;
    c = (userCell - 1) % SIZE;
}

void TicTacToeBoard::placeToken()
{
    unsigned int r, c;
    revertCell(r, c);
    board[r][c] = (turn) ? 'O' : 'X';
}

void TicTacToeBoard::turnFlip()
{
    turn = !turn;
}

bool TicTacToeBoard::checkWin()
{
    return ( checkRows() || checkCols() || checkDiags() );
}

bool TicTacToeBoard::checkDraw()
{
    std::exit(1); //checkDraw() is unnecessary for this game
}

bool TicTacToeBoard::checkRows()
{
    char token;
    for(int r = 0; r < row; r++)
    {
        if(board[r][0] != 'X' && board[r][0] != 'O')
            continue;
        token = board[r][0];
        for(int c = 1; c < col; c++)
        {
            if(board[r][c] != token)
                break;
            if(c == col - 1)
                return true;
        }
    }
    return false;
}

bool TicTacToeBoard::checkCols()
{
    char token;
    for(int c = 0; c < col; c++)
    {
        if(board[0][c] != 'X' && board[0][c] != 'O')
            continue;
        token = board[0][c];
        for(int r = 1; r < row; r++)
        {
            if(board[r][c] != token)
                break;
            if(r == row - 1)
                return true;
        }
    }
    return false;
}

bool TicTacToeBoard::checkDiags()
{
    char token;
    //top-left to bottom-right
    if(board[0][0] != 'X' && board[0][0] != 'O')
        goto bottomtop;
    token = board[0][0];
    for(int rc = 1; rc < SIZE; rc++)
    {
        if(board[rc][rc] != token)
            break;
        if(rc == SIZE - 1)
            return true;
    }
    //bottom-left to top-right
    bottomtop:
    if(board[SIZE - 1][0] != 'X' && board[SIZE - 1][0] != 'O')
        return false;
    token = board[SIZE - 1][0];
    for(int r = SIZE - 2; r >= 0; r--)
    {
        if(board[r][SIZE - 1 - r] != token)
            return false;
        if(r == 0)
            return true;
    }
}

void TicTacToeBoard::userInput()
{
    do
    {
        clearConsole();
        printBoard();
        std::cout << "Enter an available cell: ";
        std::cin >> userCell;
    } while (!validInput());
}

bool TicTacToeBoard::validInput()
{
    unsigned int r, c;
    revertCell(r, c);

    if(checkFail())
        return false;

    ignoreLine();

    if(userCell > pow(SIZE, 2) || userCell < 0)
    {
        std::cout << "Please enter a cell within bounds!" << std::endl;
        return false;
    }

    if(board[r][c] == 'X' || board[r][c] == 'O')
    {
        std::cout << "Please enter an available cell!" << std::endl;
        return false;
    }

    return true;
}

bool TicTacToeBoard::checkFail()
{
    if(!std::cin)
    {
        if(std::cin.eof())
        {
            std::exit(0);
        }
        std::cin.clear();
        ignoreLine();
        std::cout << "Please enter a positive integer!" << std::endl;
        return true;
    }
    return false;
}

void TicTacToeBoard::ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void TicTacToeBoard::clearConsole()
{
    system("clear");
}