#ifndef GFX_STD_TTT_BOARD
#define GFX_STD_TTT_BOARD

#include "TicTacToeBoard.h"
#include <string>

class StandardTicTacToeBoard : public TicTacToeBoard<char>
{
    public:
        StandardTicTacToeBoard()
        :
            TicTacToeBoard(3)
        {
            reset();
        }
        StandardTicTacToeBoard(const StandardTicTacToeBoard&) = delete;
        StandardTicTacToeBoard& operator=(const StandardTicTacToeBoard&) = delete;
        virtual ~StandardTicTacToeBoard() = default;

        void reset() override;
    private:
        void placeToken() override;
};

#endif