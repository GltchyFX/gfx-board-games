#ifndef GFX_CUSTOM_TTT_BOARD
#define GFX_CUSTOM_TTT_BOARD

#include "TicTacToeBoard.h"
#include <string>

class CustomTicTacToeBoard : public TicTacToeBoard<int>
{
    public:
        CustomTicTacToeBoard(int rc = 3)
        :
            TicTacToeBoard(rc)
        {
            reset();
        }
        CustomTicTacToeBoard(const CustomTicTacToeBoard&) = delete;
        CustomTicTacToeBoard& operator=(const CustomTicTacToeBoard&) = delete;
        virtual ~CustomTicTacToeBoard() = default;

        void reset() override;

        std::string toString() override;
    private:
        void placeToken() override;
};

#endif