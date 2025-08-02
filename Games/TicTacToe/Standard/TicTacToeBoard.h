#ifndef GFX_TTT_BOARD
#define GFX_TTT_BOARD

#include "Board.h"
#include <string>

class TicTacToeBoard : public Board<char>
{
    public:
        TicTacToeBoard()
        :
            Board(3, 3),
            turn{false}
        {
            reset();
        }
        TicTacToeBoard(const TicTacToeBoard&) = delete;
        TicTacToeBoard& operator=(const TicTacToeBoard&) = delete;
        virtual ~TicTacToeBoard() = default;

        int game();

        void play() override;

        void reset() override;

        std::string toString() override;
    protected:
        unsigned int userCell, r, c;
        const unsigned int SIZE = 3;
        //turn == true is Player 2; turn == false is Player 1
        bool turn;

        void printBoard();

        void revertCell();

        void placeToken();

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

#endif