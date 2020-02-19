# 2048

## Instructions

To play the game, use the arrow keys to shift the tiles.
Match tiles to combine them (adding their numbers).
Tiles can only be combined if their numbers are equal.

You win if you reach the 2048 tile. You lose if you
run out of playable moves (only happens when the board is full).
The game is strangely addictive. Enjoy!

## Changes from proposal

We changed a few things from our proposal.
The block tile can be removed by combining
them with another block tile. We did not
implement a score system.

## Evaluation guide

Play the game by running main. If you want to change the board size,
change n_ in model.h. If you want to cheat, two methods for doing so
are commented in model.cpp (removing blocks) and ui.cpp (winning with
only a 16 tile). 

## Answers to open questions

The board is always 600x600, the window always 800x800.
The board is centered with 100px on each side. Win/loss
text is displayed in the center, hiding the board on loss.

We ended up using a 2D Array of tile objects.

For random numbers, we have an array of integers. For some
random int RandIndex, we select nth element,
n being RandIndex % 25, 25 being the
number of integers in the array.

