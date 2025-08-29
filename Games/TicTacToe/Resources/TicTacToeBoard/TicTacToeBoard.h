#ifndef GFX_TTT_BOARD
#define GFX_TTT_BOARD

#include "Board.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <limits>

template<typename T>
class TicTacToeBoard : public Board<T>
{
    public:
        TicTacToeBoard(int rc)
        :
            Board<T>(rc, rc),
            turn{false}
        {
        }
        TicTacToeBoard(const TicTacToeBoard&) = delete;
        TicTacToeBoard& operator=(const TicTacToeBoard&) = delete;
        virtual ~TicTacToeBoard() = default;

        int game();

        void play() override;

        virtual void reset() = 0;

        virtual std::string toString();
    protected:
        unsigned int userCell, r, c;
        //turn == true is Player 2; turn == false is Player 1
        bool turn;

        void printBoard();

        void revertCell();

        virtual void placeToken() = 0;

        bool verifyToken();

        bool verifyToken(int, int);

        void turnFlip();

        bool checkWin() override;

        bool checkDraw() override;

        bool checkRows();

        bool checkCols();

        bool checkDiags();

        void userInput();

        bool validInput();

        bool checkFail();

        void ignoreLine();

        void clearConsole();
};

//rows is used to represent both rows and columns since each board will be a perfect square

template<typename T>
int TicTacToeBoard<T>::game()
{
    for(int t = 0; t < pow(Board<T>::rows, 2); t++)
    {
        play();
        if(checkWin())
            return ( (turn) ? 2 : 1 );
        turnFlip();
    }
    return 0;
}

template<typename T>
void TicTacToeBoard<T>::play()
{
    userInput();
    placeToken();
}

template<typename T>
void TicTacToeBoard<T>::printBoard()
{
    std::cout << toString() << std::endl;
    std::cout << "Player " << ( (turn) ? 2 : 1) << " Go!" << std::endl;
}

template<typename T>
void TicTacToeBoard<T>::revertCell()
{
    r = (userCell - 1) / Board<T>::rows;
    c = (userCell - 1) % Board<T>::rows;
}

template<typename T>
std::string TicTacToeBoard<T>::toString()
{
    std::ostringstream out;

    for(int r = 0; r  < Board<T>::rows; r++)
    {
        for(int c = 0; c < Board<T>::cols; c++)
        {
            out << Board<T>::board[r][c] << " | ";
        }
        out << '\n';
    }

    return out.str();
}

template<typename T>
bool TicTacToeBoard<T>::verifyToken()
{
    return verifyToken(r, c);
}

template<typename T>
bool TicTacToeBoard<T>::verifyToken(int row, int col)
{
    T token = Board<T>::board[row][col];
    switch(token)
    {
        case 'X':
        case 'O':
        case -1:
        case 0:
            return true;
        default:
            return false;
    }
}

template<typename T>
void TicTacToeBoard<T>::turnFlip()
{
    turn = !turn;
}

template<typename T>
bool TicTacToeBoard<T>::checkWin()
{
    return ( checkRows() || checkCols() || checkDiags() );
}

template<typename T>
bool TicTacToeBoard<T>::checkDraw()
{
    std::exit(1); //checkDraw() is unnecessary for this game
}

template<typename T>
bool TicTacToeBoard<T>::checkRows()
{
    T token;
    for(int r = 0; r < Board<T>::rows; r++)
    {
        if( !verifyToken(r, 0)/*(Board<T>::board[r][0] != 'X' && Board<T>::board[r][0] != -1) && (Board<T>::board[r][0] != 'O' && Board<T>::board[r][0] != 0)*/ )
            continue;
        token = Board<T>::board[r][0];
        for(int c = 1; c < Board<T>::cols; c++)
        {
            if(Board<T>::board[r][c] != token)
                break;
            if(c == Board<T>::cols - 1)
                return true;
        }
    }
    return false;
}

template<typename T>
bool TicTacToeBoard<T>::checkCols()
{
    T token;
    for(int c = 0; c < Board<T>::cols; c++)
    {
        if( !verifyToken(0, c)/*(Board<T>::board[0][c] != 'X' && Board<T>::board[0][c] != -1) && (Board<T>::board[0][c] != 'O' && Board<T>::board[0][c] != 0)*/ )
            continue;
        token = Board<T>::board[0][c];
        for(int r = 1; r < Board<T>::rows; r++)
        {
            if(Board<T>::board[r][c] != token)
                break;
            if(r == Board<T>::rows - 1)
                return true;
        }
    }
    return false;
}

template<typename T>
bool TicTacToeBoard<T>::checkDiags()
{
    T token;
    //top-left to bottom-right
    if( !verifyToken(0, 0)/*(Board<T>::board[0][0] != 'X' && Board<T>::board[0][0] != -1) && (Board<T>::board[0][0] != 'O' && Board<T>::board[0][0] != 0)*/ )
        goto bottomtop;
    token = Board<T>::board[0][0];
    for(int rc = 1; rc < Board<T>::rows; rc++)
    {
        if(Board<T>::board[rc][rc] != token)
            break;
        if(rc == Board<T>::rows - 1)
            return true;
    }
    //bottom-left to top-right
    bottomtop:
    if( !verifyToken(Board<T>::rows - 1, 0)/*(Board<T>::board[Board<T>::rows - 1][0] != 'X' && Board<T>::board[Board<T>::rows - 1][0] != -1) && (Board<T>::board[Board<T>::rows - 1][0] != 'O' && Board<T>::board[Board<T>::rows - 1][0] != 0)*/ )
        return false;
    token = Board<T>::board[Board<T>::rows - 1][0];
    for(int r = Board<T>::rows - 2; r >= 0; r--)
    {
        if(Board<T>::board[r][Board<T>::rows - 1 - r] != token)
            break;
        if(r == 0)
            return true;
    }
    return false;
}

template<typename T>
void TicTacToeBoard<T>::userInput()
{
    do
    {
        clearConsole();
        printBoard();
        std::cout << "Enter an available cell: ";
        std::cin >> userCell;
        revertCell();
    } while (!validInput());
}

template<typename T>
bool TicTacToeBoard<T>::validInput()
{
    if(checkFail())
        return false;

    ignoreLine();

    if(userCell > pow(Board<T>::rows, 2) || userCell <= 0)
    {
        std::cout << "Please enter a cell within bounds!" << std::endl;
        return false;
    }

    if(verifyToken())
    {
        std::cout << "Please enter an available cell!" << std::endl;
        return false;
    }

    return true;
}

template<typename T>
bool TicTacToeBoard<T>::checkFail()
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

template<typename T>
void TicTacToeBoard<T>::ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template<typename T>
void TicTacToeBoard<T>::clearConsole()
{
    system("clear");
}

#endif