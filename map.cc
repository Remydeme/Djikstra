#include <stdexcept>

#include "map.hh"

namespace Djikstra
{
    Map::Map(int heigh, int width) : h_(heigh), w_(width)
    {
      if (heigh < 0)
          throw std::out_of_range("heigh is lower than 0");
      if (width < 0)
          throw std::out_of_range("Width is lower than 0");
      for (int i = 0; i < h_; i++)
      {
          map_.push_back(std::vector<Case>(w_));
          for (int j = 0; j < w_; j++)
              map_[i][j].cood_set(i, j);
      }
    }

    Case* Map::operator ()(int x, int y) noexcept
    {
        return &map_[x][y];
    }
}
