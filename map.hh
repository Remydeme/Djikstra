#pragma once 
#include <vector>

#include "case.hh"


namespace Djikstra
{

    class Map
    {
        public:
           using map = std::vector<std::vector<Case>>; 
       

        public :
            
            Map(int heigh = 0, int width = 0);
            Map(Map& ) = default;
            Map(Map&& ) = default;
            Map& operator = (Map& ) = delete;
            Map& operator = (Map&& ) = default;

        public :

            Case* operator ()(int, int)  noexcept;

        private:

        map map_;
        int h_;
        int w_;
    };
}
