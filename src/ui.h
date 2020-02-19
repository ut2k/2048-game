#pragma once

#include "model.h"
#include <ge211.h>

/// Ui Struct


struct Ui : ge211::Abstract_game
{

    explicit Ui(Model&);

    ge211::Dimensions initial_window_dimensions() const override;

    std::string initial_window_title() const override;

    void draw(ge211::Sprite_set&) override;

    void on_key(ge211::Key) override;


    Model& model_;

    int tile_length;
    int buffer;
    int game_state;

    ge211::Color const zero_color;
    ge211::Color const one_color;
    ge211::Color const two_color;
    ge211::Color const three_color;
    ge211::Color const four_color;
    ge211::Color const five_color;
    ge211::Color const six_color;
    ge211::Color const seven_color;
    ge211::Color const eight_color;
    ge211::Color const nine_color;
    ge211::Color const ten_color;
    ge211::Color const eleven_color;
    ge211::Color const block_color;

    ge211::Text_sprite win_sprite =
            ge211::Text_sprite::Builder({"sans.ttf", 100})
            .message("You Win!")
            .color(ge211::Color::white())
            .build();

    ge211::Text_sprite lose_sprite =
    ge211::Text_sprite::Builder({"sans.ttf", 100})
            .message("Game Over!")
            .color(ge211::Color::white())
            .build();

    ge211::Text_sprite n2t_sprite =
            ge211::Text_sprite::Builder({"sans.ttf", 400/(model_.get_n())})
                    .message("2")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite n4t_sprite =
            ge211::Text_sprite::Builder({"sans.ttf", 400/(model_.get_n())})
                    .message("4")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite n8t_sprite =
            ge211::Text_sprite::Builder({"sans.ttf", 400/(model_.get_n())})
                    .message("8")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite n16t_sprite =
            ge211::Text_sprite::Builder({"sans.ttf", 320/(model_.get_n())})
                    .message("16")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite n32t_sprite =
            ge211::Text_sprite::Builder({"sans.ttf", 320/(model_.get_n())})
                    .message("32")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite n64t_sprite =
            ge211::Text_sprite::Builder({"sans.ttf", 320/(model_.get_n())})
                    .message("64")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite n128t_sprite =
            ge211::Text_sprite::Builder({"sans.ttf", 280/(model_.get_n())})
                    .message("128")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite n256t_sprite =
            ge211::Text_sprite::Builder({"sans.ttf", 280/(model_.get_n())})
                    .message("256")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite n512t_sprite =
            ge211::Text_sprite::Builder({"sans.ttf", 280/(model_.get_n())})
                    .message("512")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite n1024t_sprite =
            ge211::Text_sprite::Builder({"sans.ttf", 240/(model_.get_n())})
                    .message("1024")
                    .color(ge211::Color::black())
                    .build();

    ge211::Text_sprite n2048t_sprite =
            ge211::Text_sprite::Builder({"sans.ttf", 240/(model_.get_n())})
                    .message("2048")
                    .color(ge211::Color::black())
                    .build();

    ge211::Rectangle_sprite const
            background_sprite  {{tile_length, tile_length}, zero_color};

    ge211::Rectangle_sprite const
            n2_sprite  {{tile_length, tile_length}, one_color};

    ge211::Rectangle_sprite const
            n4_sprite  {{tile_length, tile_length}, two_color};

    ge211::Rectangle_sprite const
            n8_sprite  {{tile_length, tile_length}, three_color};

    ge211::Rectangle_sprite const
            n16_sprite  {{tile_length, tile_length}, four_color};

    ge211::Rectangle_sprite const
            n32_sprite  {{tile_length, tile_length}, five_color};

    ge211::Rectangle_sprite const
            n64_sprite  {{tile_length, tile_length}, six_color};

    ge211::Rectangle_sprite const
            n128_sprite  {{tile_length, tile_length}, seven_color};

    ge211::Rectangle_sprite const
            n256_sprite  {{tile_length, tile_length}, eight_color};

    ge211::Rectangle_sprite const
            n512_sprite  {{tile_length, tile_length}, nine_color};

    ge211::Rectangle_sprite const
            n1024_sprite  {{tile_length, tile_length}, ten_color};

    ge211::Rectangle_sprite const
            n2048_sprite  {{tile_length, tile_length}, eleven_color};

    ge211::Rectangle_sprite const
            block_sprite  {{tile_length, tile_length}, block_color};

};
