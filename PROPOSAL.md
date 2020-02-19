# Proposal: 2048



## Synopsis

### Our game will have two main screens- MENU and GAME:

GAME:  The game screen has four main elements:

- A stationary board that marks the boundaries of the tile objects

- A 2d NxN array of up to N^2 square tile objects. The player can change
 the tile numbers by swiping to the top, bottom, left, or right of the board by
 pressing the respective arrow key.

- A background displaying the player's current score, top score, and a
 button to start a new game (abandoning the current game in the process)

- A button to start a new game


MENU:  The menu screen has three main elements:

(REACH FEATURES)

- A button to start a new game

- A box displaying the top 3 high scores and the names of the players
 who earned them.

- A field where the player can enter their name before starting a game,
 defaults to 'Anonymous' if nothing is entered.


### Goal:

Combine tiles by shifting them until you win by having a tile with
'2048', or lose when there are no such tiles, but the tiles will not
move when shifted (this only happens when the board is full).




## Functional requirements


GAME:

01. The board has space for a square NxN grid of tiles.
Note that N = 4 in the regular version of the game, but
should work with other feasible N.

02. Each tile is represented by a unique sprite depending on
its number. A '2' tile will have a different sprite than
a '4'. The sprite displays the number and each sprite is a
different color.

03. A tile can "combine" with at most one other tile each
time the player shifts, and that tile must have the same
number to combine.

04. When shifting, a tile will appear to move until it
reaches the inner edge of the box or collides with another
tile. Its position is not actually changing, only the numbers
for each tile in the vector. Each tile's position remains
constant.

05. When two tiles would collide, if their numbers are equal,
they will combine. This doubles the
number of the tile that was hit, and setting the number
of the tile that hit it to zero. E.g, two '2' tiles
colliding due to a shift to the left results in one '4'
tile in the leftmost of the two tiles and one zero tile.

06. The player wins when a '2048' tile is created, and
 loses when the board becomes full and no
tiles can be combined by shifting.

07. The player's score is displayed on the game screen.
Their score starts at zero, and whenever two tiles are
combined, the score is incremented by the number of the
combined tile.

08. Each time the player shifts the tiles, a zero tile
on the grid will be changed to be either a '2', a '4',
or 'block' a special case.

09. A 'block' tile (one that displays the string 'block')
cannot combine with any other tiles, and is as such purely
a nuisance to the player.

10. No more than one block tile may be on the bord at a time:
none will randomly spawn if one already exists.

11. A 'block' tile will stay on the board for 2-10 shifts
(determined at random), then be destroyed.

12. Tiles shift from the direction they are being shifted
towards. When shifting to the left, the leftmost tiles will
go first.






## Open questions


How will the elements of the game be laid out?

Should we use a 2D array or a 1D array for holding the tiles as specified in model.h <line28>.

How, specifically will random numbers be generated? Should we have a vector of booleans and we select an element
randomly from that vector in order to find the probability with which we spawn a 2 or a 4? For example, to give the
probability of 0.9 to 2 and 0.1 to 4 we'd have a a vector of 10 elements with 1 false and 9 true elements.


