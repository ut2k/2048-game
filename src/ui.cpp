#include "ui.h"
#include <iostream>


Ui::Ui(Model& model)
        : model_(model)
        , zero_color({169,169,169})
        , one_color({255,102,102})
        , two_color({255,178,102})
        , three_color({255,255,102})
        , four_color({178,255,102})
        , five_color({102,255,102})
        , six_color({102,255,178})
        , seven_color({102,255,255})
        , eight_color({102,178,255})
        , nine_color({102,102,255})
        , ten_color({178,102,255})
        , eleven_color({255,102,255})
        , block_color({0,0,0})
        , tile_length(600/model_.get_n())
        , buffer(1)
        , game_state(0)

{ }



/// View


ge211::Dimensions Ui::initial_window_dimensions() const
{


    return {800,800};
}

std::string Ui::initial_window_title() const
{
    return "2048";
}

void Ui::draw(ge211::Sprite_set& sprites)
{



    if (game_state != -1) {

        for (int i = 0; i < model_.get_n(); i++) {
            for (int j = 0; j < model_.get_n(); j++) {


                ge211::Position spritepos =
                        {((tile_length + buffer) * (i + 1)) - tile_length + 100,
                         ((tile_length + buffer) * (j + 1)) - tile_length + 100};


                ge211::Position textpos =
                        {((tile_length + buffer) * (i + 1)) - tile_length + 100,
                         ((tile_length + buffer) * (j + 1)) - tile_length + 100
                                           + (tile_length / 4)};


                ge211::Position d4pos = {textpos.x + (tile_length / 16),
                                         textpos.y - (tile_length / 10)};

                ge211::Position d3pos = {textpos.x + (tile_length / 11),
                                         textpos.y - (tile_length / 6)};

                ge211::Position d2pos = {textpos.x + (2 * tile_length / 9),
                                         textpos.y - (tile_length / 5)};

                ge211::Position d1pos = {textpos.x + (2 * tile_length / 7),
                                         textpos.y - (tile_length / 3)};

                sprites.add_sprite(background_sprite, spritepos, -999);


                // Sprites based on number //

                if (model_.get_tiles_()[i][j].tile_no == 2) {

                    sprites.add_sprite(n2t_sprite, d1pos, 999);
                    sprites.add_sprite(n2_sprite, spritepos, 0);
                } else if (model_.get_tiles_()[i][j].tile_no == 4) {
                    sprites.add_sprite(n4t_sprite, d1pos, 999);
                    sprites.add_sprite(n4_sprite, spritepos, 0);
                } else if (model_.get_tiles_()[i][j].tile_no == 8) {
                    sprites.add_sprite(n8t_sprite, d1pos, 999);
                    sprites.add_sprite(n8_sprite, spritepos, 0);
                } else if (model_.get_tiles_()[i][j].tile_no == 16) {
                    sprites.add_sprite(n16t_sprite,
                                       {d2pos.x - (tile_length / 16), d2pos.y}, 999);
                    sprites.add_sprite(n16_sprite, spritepos, 0);



                    /// FOR GRADING ///

                    /// UNCOMMENT V TO CHEAT ///

                    // game_state = 1;

                    /// UNCOMMENT ^ TO CHEAT ///


                    /*

                    Line above has the View display what you
                    would see if you win on 16 instead of 2048.

                    Testing losing interactively should be easy.
                    To do so quickly, we recommend changing the
                    board size to 2, and intentionally losing.

                    To change the size of the board, go to the
                    designated section of model.h in the private
                    data members.

                    */


                } else if (model_.get_tiles_()[i][j].tile_no == 32) {
                    sprites.add_sprite(n32t_sprite, d2pos, 999);
                    sprites.add_sprite(n32_sprite, spritepos, 0);
                } else if (model_.get_tiles_()[i][j].tile_no == 64) {
                    sprites.add_sprite(n64t_sprite, d2pos, 999);
                    sprites.add_sprite(n64_sprite, spritepos, 0);
                } else if (model_.get_tiles_()[i][j].tile_no == 128) {
                    sprites.add_sprite(n128t_sprite, d3pos, 999);
                    sprites.add_sprite(n128_sprite, spritepos, 0);
                } else if (model_.get_tiles_()[i][j].tile_no == 256) {
                    sprites.add_sprite(n256t_sprite, d3pos, 999);
                    sprites.add_sprite(n256_sprite, spritepos, 0);
                } else if (model_.get_tiles_()[i][j].tile_no == 512) {
                    sprites.add_sprite(n512t_sprite, d3pos, 999);
                    sprites.add_sprite(n512_sprite, spritepos, 0);
                } else if (model_.get_tiles_()[i][j].tile_no == 1024) {
                    sprites.add_sprite(n1024t_sprite, d4pos, 999);
                    sprites.add_sprite(n1024_sprite, spritepos, 0);
                } else if (model_.get_tiles_()[i][j].tile_no == 2048) {
                    game_state = 1;
                    sprites.add_sprite(n2048t_sprite, d4pos, 999);
                    sprites.add_sprite(n2048_sprite, spritepos, 0);
                } else if (model_.get_tiles_()[i][j].tile_no == -1) {
                    sprites.add_sprite(block_sprite, spritepos, 0);
                }


            }
        }
    }

if (!model_.moves_left() && game_state != 1) {
    game_state = -1;
}


if (game_state == 1) {
    sprites.add_sprite(win_sprite, {200,200}, 9999);
}

if (game_state == -1) {
    sprites.add_sprite(lose_sprite, {120,200}, 9999);}

}



/// Controller


void Ui::on_key(ge211::Key key)
{

    if (key == ge211::Key::up())
    {
        model_.update_left_pos();
        model_.zeros_present_check();

        if(model_.moves_left())
        {
            model_.Swipe_left(model_.get_tiles_());
            model_.update_left_pos();
            model_.zeros_present_check();
            if(model_.zeros_present_return())
            {
                model_.new_tile();
            }
        }
    }

    if (key == ge211::Key::down())
    {
        model_.update_left_pos();
        model_.zeros_present_check();
        if(model_.moves_left())
        {
            model_.Swipe_right(model_.get_tiles_());
            model_.update_left_pos();
            model_.zeros_present_check();
            if(model_.zeros_present_return())
            {
                model_.new_tile();
            }
        }
    }

    if (key == ge211::Key::left())
    {
        model_.update_left_pos();
        model_.zeros_present_check();
        if(model_.moves_left())
        {
            model_.Swipe_up(model_.get_tiles_());
            model_.update_left_pos();
            model_.zeros_present_check();
            if(model_.zeros_present_return())
            {
                model_.new_tile();
            }
        }
    }

    if (key == ge211::Key::right())
    {
        model_.update_left_pos();
        model_.zeros_present_check();

        if(model_.moves_left())
        {
            model_.Swipe_down(model_.get_tiles_());
            model_.update_left_pos();
            model_.zeros_present_check();
            if(model_.zeros_present_return())
            {
                model_.new_tile();
            }
        }
    }

}




