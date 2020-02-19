#include "model.h"

Model::Model()
   :block_present_(false)
   ,zeros_present_(true)
   ,tiles_(new tile*[n_])
   ,left_pos_()


{
    for (int i = 0; i < n_; i++) {
        tiles_[i] = new tile[n_];
    }

    for(int i = 0; i < n_; i++)
    {
        for (int j = 0; j < n_; j++)
        {
            tiles_[i][j].tile_no = 0;
            tiles_[i][j].top_left = {i, j};
            if (tiles_[i][j].tile_no == 0)
            {
                left_pos_.push_back(tiles_[i][j].top_left);
            }
        }
    }
    new_tile();
    new_tile();
}

Model::~Model()
{
    for (int i = 0; i < n_; i++)
    {
        delete[] tiles_[i];
    }

    delete[] tiles_;

}

int Model::get_n()
{
    return n_;
}

bool Model::get_block_present() const
{
    return block_present_;
}

tile** Model::get_tiles_() const
{
    return tiles_;
}

bool Model::zeros_present_return() const
{
    return zeros_present_;
}

void Model::update_left_pos()
{
    left_pos_.clear();
    for(int i = 0; i < n_; i++)
    {
        for (int j = 0; j < n_; j++)
        {
            if (tiles_[i][j].tile_no == 0)
            {
                left_pos_.push_back(tiles_[i][j].top_left);
            }
        }
    }
}

bool Model::Compare(tile** const&a, tile** const&b) const
{
    int ctr = 0;
    for(int i = 0; i < n_; i++)
        for(int j = 0; j < n_; j++)
        {
            if(a[i][j].tile_no == b[i][j].tile_no &&
            a[i][j].top_left.x == b[i][j].top_left.x &&
            a[i][j].top_left.y == b[i][j].top_left.y)
            {
                ctr++;
            }

        }
    if(ctr == (n_ * n_))
    {
        return true;
    }
    return false;
}

//Pre-condition dir must only have values 1 2 3 4 and no other.
bool Model::check_tile(ge211::Position const& from, int const& dir) const
{
    if(dir == 1)//checking with the tile right to the current tile
    {
        if(from.y == n_ - 1){return false;}
        return (tiles_[from.x][from.y].tile_no == tiles_[from.x][from.y + 1].tile_no);
    }
    else if(dir == 2)//checking with the tile left to the current tile
    {
        if(from.y == 0){return false;}
        return (tiles_[from.x][from.y].tile_no == tiles_[from.x][from.y - 1].tile_no);
    }
    else if(dir == 3)//checking with the tile top to the current tile
    {
        if(from.x == 0){return false;}
        return (tiles_[from.x][from.y].tile_no == tiles_[from.x - 1][from.y].tile_no);
    }
    else if(dir == 4)//checking with the tile bottom to the current tile
    {
        if (from.x == n_ - 1) {return false;}
        return (tiles_[from.x][from.y].tile_no == tiles_[from.x + 1][from.y].tile_no);
    }
    else
        return false;
}


ge211::Position Model::generate_rand()
{
    size_t Rand_index1 = rand() % left_pos_.size();
    update_left_pos();
    return {left_pos_[Rand_index1]};
}


void Model::new_tile()
{

    /// CHANGE RANDOM TILES HERE ///

    int arrayNum[25] = {4, 4, -1, 2, 2, 2, 2, 2, 2,
                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

    // Changing the -1 to say, a 2 or 4 will disable block tiles.
    // Do this if the game is too difficult while testing.

    /// CHANGE RANDOM TILES HERE ///

    int RandIndex = rand() % 25; //generates a random number between 0 and 25.
    auto const twoOrFour = arrayNum[RandIndex];

    ge211::Position s = generate_rand();
    tiles_[s.x][s.y].tile_no = twoOrFour;
    update_left_pos();
}

bool Model::present_2048() const
{
    for(int i = 0; i < n_; i++)
        for(int j = 0; j < n_; j++)
        {
           if(tiles_[i][j].tile_no == 2048)
           {
               return true;
           }
        }
    return false;
}

bool Model::moves_left()
{
    int ctr1 = 0;
    int ctr2 = 0;
    int ctr3 = 0;
    int ctr4 = 0;

    if(present_2048()){return false;}
    else if(!zeros_present_)
    {
        tile** a = new tile*[n_];
        for (int i = 0; i < n_; i++) {
            a[i] = new tile[n_];
        }

        for(int i = 0; i < n_; i++)
        {
            for (int j = 0; j < n_; j++)
            {
                a[i][j].tile_no = tiles_[i][j].tile_no;
                a[i][j].top_left = tiles_[i][j].top_left;
            }
        }

        if (Compare(tiles_, Swipe_right(a)))
        {
            ctr1 = 1;
        }

        for (int i = 0; i < n_; i++)
        {
            delete[] a[i];
        }
        delete[] a;

        tile** b = new tile*[n_];
        for (int i = 0; i < n_; i++) {
            b[i] = new tile[n_];
        }
        for(int i = 0; i < n_; i++)
        {
            for (int j = 0; j < n_; j++)
            {
                b[i][j].tile_no = tiles_[i][j].tile_no;
                b[i][j].top_left = tiles_[i][j].top_left;
            }
        }


        if(Compare(tiles_, Swipe_left(b)))
        {
            ctr2 = 1;
        }

        for (int i = 0; i < n_; i++)
        {
            delete[] b[i];
        }
        delete[] b;

        tile** c = new tile*[n_];
        for (int i = 0; i < n_; i++) {
            c[i] = new tile[n_];
        }

        for(int i = 0; i < n_; i++)
        {
            for (int j = 0; j < n_; j++)
            {
                c[i][j].tile_no = tiles_[i][j].tile_no;
                c[i][j].top_left = tiles_[i][j].top_left;
            }
        }

        if(Compare(tiles_, Swipe_up(c)))
        {
            ctr3 = 1;
        }
        for (int i = 0; i < n_; i++)
        {
            delete[] c[i];
        }
        delete[] c;

        tile** d = new tile*[n_];
        for (int i = 0; i < n_; i++) {
            d[i] = new tile[n_];
        }

        for(int i = 0; i < n_; i++)
        {
            for (int j = 0; j < n_; j++)
            {
                d[i][j].tile_no = tiles_[i][j].tile_no;
                d[i][j].top_left = tiles_[i][j].top_left;
            }
        }

        if(Compare(tiles_, Swipe_down(d)))
        {
            ctr4 = 1;
        }

        for (int i = 0; i < n_; i++)
        {
            delete[] d[i];
        }
        delete[] d;

        if(ctr1 == 1 && ctr2 == 1 && ctr3 == 1 && ctr4 == 1)
        {
            return false;
        }

    }
    return true;
}

tile** Model::Swipe_right(tile** a)
{
    for(int i = 0; i < n_; i++)
    {
        for (int j = n_ - 1; j >= 0 ; j--)
        {
            int c = j;
            while(a[i][j].tile_no == 0 && c>0)
            {
                for(int k = j - 1; k >= 0 ; k--)
                {
                    int temp = a[i][k].tile_no;
                    a[i][k].tile_no = a[i][k+1].tile_no;
                    a[i][k+1].tile_no = temp;
                }
                c--;
            }
            if(j != n_ - 1)
            {
                if(check_tile({i,j}, 1))
                {
                    if (a[i][j+1].tile_no != -1) {
                        a[i][j + 1].tile_no = a[i][j + 1].tile_no * 2;
                    }
                    else a[i][j + 1].tile_no = 0;
                    a[i][j].tile_no = 0;

                    for(int k = j - 1; k >= 0 ; k--)
                    {
                        int temp = a[i][k].tile_no;
                        a[i][k].tile_no = a[i][k+1].tile_no;
                        a[i][k+1].tile_no = temp;
                    }
                }
            }

        }
    }
    return a;
}


tile** Model::Swipe_left(tile** a)
{
    for(int i = 0; i < n_; i++)
    {
        for (int j = 0; j < n_ ; j++)
        {
            int c = j;
            while(a[i][j].tile_no == 0 && j!= n_- 1 && c < n_ - 1)
            {
                for(int k = j; k < n_ - 1; k++)
                {
                    int temp = a[i][k].tile_no;
                    a[i][k].tile_no = a[i][k+1].tile_no;
                    a[i][k+1].tile_no = temp;
                }
                c++;
            }
            if(j != 0)
            {
                if(check_tile({i,j}, 2))
                {
                    if (a[i][j-1].tile_no != -1) {
                        a[i][j - 1].tile_no = a[i][j - 1].tile_no * 2;//check
                    }
                    else a[i][j-1].tile_no = 0;
                    a[i][j].tile_no = 0;

                    for(int k = j; k < n_ - 1; k++)
                    {
                        int temp = a[i][k].tile_no;
                        a[i][k].tile_no = a[i][k+1].tile_no;
                        a[i][k+1].tile_no = temp;
                    }
                }
            }

        }
    }
    return a;
}


tile** Model::Swipe_up(tile** a)
{
    for(int j = 0; j < n_; j++)
    {
        for (int i = 0; i < n_ ; i++)
        {
            int c = i;
            while(a[i][j].tile_no == 0 && c < n_ - 1)
            {
                for(int k = i; k < n_ - 1; k++)
                {
                    int temp = a[k][j].tile_no;
                    a[k][j].tile_no = a[k+1][j].tile_no;
                    a[k+1][j].tile_no = temp;
                }
                c++;
            }
            if(i != 0)
            {
                if(check_tile({i,j}, 3))
                {
                    if (a[i-1][j].tile_no != -1) {
                        a[i - 1][j].tile_no = a[i - 1][j].tile_no * 2;
                    }
                    else a[i-1][j].tile_no = 0;
                    a[i][j].tile_no = 0;

                    for(int k = i; k < n_ - 1; k++)
                    {
                        int temp = a[k][j].tile_no;
                        a[k][j].tile_no = a[k+1][j].tile_no;
                        a[k+1][j].tile_no = temp;
                    }
                }
            }

        }
    }
    return a;
}

tile** Model::Swipe_down(tile** a)
{
    for(int j = 0; j < n_; j++)
    {
        for (int i = n_ - 1; i >= 0 ; i--)
        {
            int c = i;
            while(a[i][j].tile_no == 0 && c>0)
            {
                for(int k = i - 1; k >= 0; k--)
                {
                    int temp = a[k][j].tile_no;
                    a[k][j].tile_no = a[k+1][j].tile_no;
                    a[k+1][j].tile_no = temp;
                }
                c--;
            }
            if(i != n_ - 1)
            {
                if(check_tile({i,j}, 4))
                {
                    if (a[i+1][j].tile_no != -1) {
                        a[i + 1][j].tile_no = a[i + 1][j].tile_no * 2;
                    }
                    else a[i+1][j].tile_no = 0;
                    a[i][j].tile_no = 0;

                    for(int k = i - 1; k >= 0; k--)
                    {
                        int temp = a[k][j].tile_no;
                        a[k][j].tile_no = a[k+1][j].tile_no;
                        a[k+1][j].tile_no = temp;
                    }
                }
            }

        }
    }
    return a;
}

void Model::zeros_present_check()
{
    if (left_pos_.empty())
    {
        zeros_present_ = false;
    }
    else
    {
        zeros_present_ = true;
    }
}






