#include "tile.hh"



namespace Djikstra
{
 /*   Case::Case(int position_x, int position_y) : x_(position_x),
    y_(position_y)
    {
        if (x_ < 0)
            throw std::out_of_range("X is lower than 0");
        if (y_ < 0)
            throw std::out_of_range("Y is lower than 0");
    }

*/

    bool Tile::operator == (Tile& tile)
    {
        if (tile.x_ == x_ && tile.y_ == y_ &&
            tile.is_listed_ == is_listed_ &&
            tile.weight_ == weight_ &&
            tile.is_start_ == is_start_ &&
            tile.is_arrival_ == is_arrival_ &&
            tile.type_ == type_)
            return true;
        return false;
    }
}
