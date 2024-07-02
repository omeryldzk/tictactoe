# Tic Tac Toe Game

This is a simple command-line implementation of the classic Tic Tac Toe game in C++.

## Features

- Allows two players to play Tic Tac Toe.
- Displays the current state of the board after each move.
- Determines and displays the winner or if the game ends in a draw.

## Prerequisites

- C++ compiler (supporting C++11)
- Terminal or command prompt

## How to Use

1. **Clone the repository:**
   ```bash
   git clone <repository_url>
   ```
2. **Compile the code:**
```bash
   g++ main.cpp tictactoe.cpp -o tictactoe
   ```
3. **Run the game:**
```bash
   ./tictactoe
   ```
4.**Follow the prompts:**
- Player 1 (X) and Player 2 (O) take turns entering their moves.
- Enter a number (1-9) to place your symbol on the corresponding cell of the board.
- 
5.**Winning conditions:**

- The game ends when a player achieves three symbols in a row (horizontally, vertically, or diagonally).
- If all cells are filled without a winner, the game declares a draw.

**Example**
```bash
$ ./tictactoe

    Tic Tac Toe

Player 1 (X)  -  Player 2 (O)

     |     |     
  1  |  2  |  3  
_____|_____|_____
     |     |     
  4  |  5  |  6  
_____|_____|_____
     |     |     
  7  |  8  |  9  
     |     |     

Player 1 [X] turn: 5

     |     |     
  X  |  2  |  3  
_____|_____|_____
     |     |     
  O  |  X  |  O  
_____|_____|_____
     |     |     
  7  |  8  |  X  
     |     |     

...

Congratulations! Player with 'X' has won the game.
```
