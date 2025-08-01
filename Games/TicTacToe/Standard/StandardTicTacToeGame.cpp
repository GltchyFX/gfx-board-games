#include "StandardTicTacToeBoard.h"
#include <iostream>

void play();

int main(){
    char playAgain;
    do
    {
        system("clear");
        play();
        std::cout << "Play again? (Y/N) ";
        std::cin >> playAgain;
    } while ((char)std::tolower(playAgain) == 'y');
    
    std::cout << "Thank you for playing!" << std::endl;

    return 0;
}

void play()
{
    StandardTicTacToeBoard game;

    int result = game.game();

    system("clear");

    std::cout << game.toString() << std::endl;

    if(!result)//result is equal to 0 if the game was a draw
    {
        std::cout << "The game was a draw!" << std::endl;
    }else
    {
        std::cout << "Player " << result << " Wins!" << std::endl;
    }
}