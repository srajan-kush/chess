# Chess Game in C++

This is a simple chess game developed in C++, featuring various functionalities such as castling, check, checkmate, pawn promotion, moving of pieces, and fifty-move draw.

## How to Run

1. Clone this repository to your local machine.
2. Navigate to the directory containing the source code.
3. Compile the `main.cpp` file using your preferred C++ compiler. For example:
    ```bash
    g++ main.cpp -o chess
    ```
4. Run the compiled executable:
    ```bash
    ./chess
    ```
5. Follow the instructions on the terminal to play the game. You will be prompted to enter the row and column numbers for selecting the piece to move. After that, you'll be asked to enter the location where you want to move it.

## Features

### 1. Castling
Castling is a special move in chess involving the king and one of the player's rooks. It allows both pieces to move simultaneously under certain conditions, typically to improve the king's safety and activate the rook for potential endgame strategies.

### 2. Check and Checkmate
In chess, "check" occurs when a player's king is under immediate threat of capture by an opponent's piece. If a player's king is in check and there are no legal moves to remove the threat, it results in "checkmate," which ends the game with a win for the opposing player.

### 3. Pawn Promotion
Pawn promotion occurs when a pawn reaches the opponent's back rank (the opposite end of the board). The player can then choose to promote the pawn to any other piece (usually a queen, rook, bishop, or knight), enhancing its power and strategic potential.

### 4. Moving Pieces
Players can move their pieces across the chessboard according to the specific movement rules of each piece type. These rules include how pieces like pawns, knights, bishops, rooks, queens, and kings can move and capture other pieces, creating diverse tactical possibilities.

### 5. Fifty-Move Draw
The fifty-move draw rule states that if both players make 50 consecutive moves without making a pawn move or capturing any pieces, either player can claim a draw. This rule prevents overly prolonged games and encourages players to make progress towards victory.

## Screenshots

Attach a screenshot of the game board frame here.
<img src="https://github.com/srajan-kush/chess/blob/main/screenshots/board.png"></img>
