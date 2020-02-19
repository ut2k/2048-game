#pragma once

#include <ge211.h>

struct tile
{
    ge211::Position top_left = {0, 0};
    int tile_no = 0;
};


class Model
{
public:

    //
    // CONSTRUCTOR
    //
    Model();


    //
    //DESTRUCTOR
    //
    ~Model();


    //
    // PUBLIC FUNCTIONS
    //

    // Returns the tile number of each of the tiles in the tiles vector.

    int get_n();

    bool get_block_present() const;

    // Gets the positions of the tiles and stores them in a 1D vector.
    void update_left_pos();

    //Returns tiles_.
    tile** get_tiles_() const;

    // Compares two 2D tile** arrays and returns true if they're the same.
    bool Compare(tile** const&, tile** const&) const;

    // Check if there are moves left.
    bool moves_left();

    // Swiping the 2D array.
    tile** Swipe_right(tile** a);
    tile** Swipe_left(tile** a);
    tile** Swipe_up(tile** a);
    tile** Swipe_down(tile** a);

    void zeros_present_check();


    void new_tile();

    bool zeros_present_return() const;

private:

    //
    // PRIVATE DATA MEMBERS
    //



    /// CHANGE SIZE OF BOARD HERE ///

    // An n_ x n_ game of "2048"

    int static const n_ = 4;

    // The game works for 2 <= n_ < ~80

    /// CHANGE SIZE OF BOARD HERE ///


    // A 2D vector with the top left coordinates of all the tiles.
    tile** tiles_;

    std::vector<ge211::Position> left_pos_;

    // True when a block is present on the board.
    bool block_present_;

    // True when at least one tile_no is 0.
    bool zeros_present_;

    // Determines whether the tile next to a given tile has the same tile_no as
    // The second argument is of type int which specifies the direction to check in
    bool check_tile(ge211::Position const&, int const&) const;

    // Randomly generates a position in the 2D array to which the tiles_ points to.
    ge211::Position generate_rand();

    // Checks whether the any tile_no = 204.
    bool present_2048() const;

    // Test access
    friend class Test_access;
};