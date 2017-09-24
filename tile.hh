#pragma once

#include <cstdint>

namespace Djikstra
{

    class Tile
    {

        public :

     
     constexpr Tile (int x = 0, int y = 0, bool is_start = false, bool is_arrival = false);

     Tile (Tile&& ) = default;
     Tile (Tile& ) = default;
     Tile& operator =  (Tile&& ) = default;
     Tile& operator = (Tile& ) = default;

        /*getter and setter */
        public:

            enum Type
            {
                GRASS = 'G',
                ROAD = 'R',
                WALL = 'W',
                WATER = 'A' /* as agua*/
            };

        using Type = enum Type;

        public :
            void weight_set(int) noexcept;

            void listed_set() noexcept; 
            
            void father_set(Tile* const) noexcept;

            void cood_set(int, int) noexcept;

            void start_set() noexcept;

            void arrival_set() noexcept;

            bool is_listed() const noexcept;

            void type_set(char tile) noexcept;

            int weight_get() const noexcept;

            int x_get() const noexcept;

            int y_get() const noexcept;

            Tile* father_get() const noexcept;

            bool is_arrival() const noexcept;

            bool is_start() const noexcept;

            bool is_road() const noexcept;

            constexpr operator int () const;

            bool operator == (Tile& );

            Type type_get() const noexcept ;
        private :

            /*mean that we have already visited this node*/
            bool is_listed_ = false; 

            /* weight of the node */ 
            uint32_t weight_ = 0; 

            /* father is the node from wich we compute this 
               new cas_s */
            Tile* father_ = nullptr;

            bool is_arrival_ = false;

            bool is_start_ = false;

            Type type_ = WALL;

            int x_;
            int y_;

    };

}
 
 #include "tile.hxx"
