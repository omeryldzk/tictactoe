#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include "tictactoe.h"
#include <stack>
using namespace std;

int main()
{
    system("clear");
    TicTacToe* new_game = new TicTacToe();
    new_game->startGame();
    delete new_game;
    return EXIT_SUCCESS;
}