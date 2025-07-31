#include "TicTacToeBoard.h"
#include <iostream>

int main(){
    TicTacToeBoard game;

    int result = game.game();

    system("clear");

    std::cout << game.toString() << std::endl;

    if(!result)
    {
        std::cout << "The game was a draw!" << std::endl;
    }else
    {
        std::cout << "Player " << result << " Wins!" << std::endl;
    }

    return 0;
}