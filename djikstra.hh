#pragma once

#include <vector>

#include "map.hh"

namespace Djikstra
{

    class Djikstra
    {

        public :


        Djikstra(Map* map, Tile&& start, Tile&& end);

        Djikstra(Map* map, Tile& start, Tile& end);
        
        Tile* search();
        private:

            /* contain that have been visited and that
               are not in closed */


            /* Closed vector contain the whole of cases that
               corespond to the path  */

            std::vector<Tile*> path_;

            /*map that contains all the Tile and information about the node*/

            Map* map_ = nullptr;

            Tile start_;

            Tile end_;
    };
}
