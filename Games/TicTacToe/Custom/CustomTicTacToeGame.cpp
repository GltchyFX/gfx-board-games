#include "CustomTicTacToeBoard.h"
#include <iostream>

void play(int);

int main()
{
    char playAgain;
    int size;

    do
    {
        system("clear");
        std::cout << "What size board (Enter one number): ";
        std::cin >> size;
        play(size);
        std::cout << "Play again? (Y/N) ";
        std::cin >> playAgain;
    } while ((char)std::tolower(playAgain) == 'y');
    
    std::cout << "Thank you for playing!" << std::endl;

    return 0;
}

void play(int size)
{
    CustomTicTacToeBoard game(size);

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