#include "model.h"
#include <catch.h>

struct Test_access
{
    Model& m_;

    bool zeros_present_()
    {
        return m_.zeros_present_;
    }

    bool moves_left_()
    {
        return m_.moves_left();
    }

    bool present_2048_()
    {
        return m_.present_2048();
    }

    void new_tile_()
    {
        m_.new_tile();
    }
};

TEST_CASE("NxN Board")
{
    Model m;

    CHECK(m.get_tiles_()[0][0].tile_no == 0);

    CHECK(m.get_tiles_()[0][m.get_n() - 1].tile_no == 0);

    CHECK(m.get_tiles_()[m.get_n() - 1][0].tile_no == 0);

    for(int i = 0; i < m.get_n(); i++)
        for(int j = 0; j < m.get_n(); j++)
        {
            CHECK(m.get_tiles_()[m.get_n() - 1][m.get_n() - 1].tile_no == 0);
        }

   // Any elements between 0 and (n_ - 1) exist
   // Tile number defaults to zero.

}

TEST_CASE("Starting Board")
{

    Model m;

    int count = 0;

    for(int i = 0; i < m.get_n(); i++)
        for(int j = 0; j < m.get_n(); j++)
        {
            if(m.get_tiles_()[i][j].tile_no == 0)
            {
                count++;
            }
        }

    CHECK(count == (m.get_n() * m.get_n() - 2));
        // Model starts with 2 tiles

    for(int i = 0; i < m.get_n(); i++)
        for(int j = 0; j < m.get_n(); j++)
        {
            CHECK((m.get_tiles_()[m.get_n() - 1][m.get_n() - 1].tile_no != 8));
        }

}


TEST_CASE("Combine")
{
    Model m;

    Test_access t{m};

    m.get_tiles_()[0][0].tile_no = 2;
    m.get_tiles_()[0][1].tile_no = 2;

    m.Swipe_left(m.get_tiles_());

    CHECK(m.get_tiles_()[0][0].tile_no == 4);

    CHECK(m.get_tiles_()[0][1].tile_no == 0);

}

TEST_CASE("Position Unchanged") {
    Model m;

    Test_access t{m};

    m.get_tiles_()[0][0].tile_no = 16;
    m.get_tiles_()[0][1].tile_no = 8;

    m.Swipe_left(m.get_tiles_());

    CHECK(m.get_tiles_()[0][0].tile_no == 16);

    CHECK(m.get_tiles_()[0][1].tile_no == 8);

}



TEST_CASE("Win 2048")
{

    Model m;

    Test_access t{m};

    m.get_tiles_()[0][0].tile_no = 1024;
    m.get_tiles_()[0][1].tile_no = 1024;

    CHECK(!t.present_2048_());

    m.Swipe_left(m.get_tiles_());

    CHECK(t.present_2048_());


}

TEST_CASE("New Tile")
{
    Model m;

    int count0 = 0;
    int count2 = 0;
    int count4 = 0;
    int countb = 0;

    for(int i = 0; i < m.get_n(); i++)
        for(int j = 0; j < m.get_n(); j++)
        {
            if(m.get_tiles_()[i][j].tile_no == 0)
            {
                count0++;
            }

            if(m.get_tiles_()[i][j].tile_no == 2)
            {
                count2++;
            }

            if(m.get_tiles_()[i][j].tile_no == 4)
            {
                count4++;
            }
            if(m.get_tiles_()[i][j].tile_no == -1)
            {
                countb++;
            }


        }

    CHECK(count0 != 0);

    m.new_tile();


    int count_0 = 0;
    int count_2 = 0;
    int count_4 = 0;
    int count_b = 0;

    for(int i = 0; i < m.get_n(); i++)
        for(int j = 0; j < m.get_n(); j++)
        {
            if(m.get_tiles_()[i][j].tile_no == 0)
            {
                count_0++;
            }

            if(m.get_tiles_()[i][j].tile_no == 2)
            {
                count_2++;
            }

            if(m.get_tiles_()[i][j].tile_no == 4)
            {
                count_4++;
            }
            if(m.get_tiles_()[i][j].tile_no == 4)
            {
                count_b++;
            }


        }

    CHECK(count0 == count_0 + 1);
        // One fewer '0' tile after new_tile()

    CHECK(count2 + count4 + count_b ==
    count_2 + count_4 + count_b - 1);

}

TEST_CASE("Block Tile")
{
    Model m;

    m.get_tiles_()[0][0].tile_no = -1;

    m.get_tiles_()[0][1].tile_no = 2;

    m.Swipe_left(m.get_tiles_());

    CHECK(m.get_tiles_()[0][0].tile_no == -1);
}

TEST_CASE("Block Elimination")
{
    Model m;

    for(int i = 0; i < m.get_n(); i++)
        for(int j = 0; j < m.get_n(); j++)
        {
            m.get_tiles_()[i][j].tile_no = 0;
        }

    m.get_tiles_()[0][0].tile_no = -1;

    m.get_tiles_()[0][1].tile_no = -1;

    m.Swipe_left(m.get_tiles_());

    CHECK(m.get_tiles_()[0][0].tile_no == 0);
    CHECK(m.get_tiles_()[0][1].tile_no == 0);

}

//
//
// These tests should demonstrate at least six of the functional
// requirements.
//