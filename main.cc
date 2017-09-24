#include "djikstra.hh"
#include <iostream>

int main ()
{
    Djikstra::Map map_(std::string("map.txt"));
    Djikstra::Djikstra find(&map_, Djikstra::Tile(0, 0, true, false), 
    Djikstra::Tile(2, 4, false, true));
    find.search();
}
