#pragma once

#include <cstdint>

namespace Djikstra
{

    class Case
    {

        public :

     
     constexpr Case(int x = 0, int y = 0);

        /*getter and setter */

        public :
            void weight_set(int) noexcept;

            void is_listed_set(bool) noexcept; 
            
            void father_set(Case* const) noexcept;

            void cood_set(int, int) noexcept;

            bool is_listed() const noexcept;

            int weight_get() const noexcept;

            int x_get() const noexcept;

            int y_get() const noexcept;

            constexpr operator int () const;
        private :

            /*mean that we have already visited this node*/
            bool is_listed_ = false; 

            /* weight of the node */ 
            uint32_t weight_ = 0; 

            /* father is the node from wich we compute this 
               new cas_s */
            Case* father_ = nullptr; 

            int x_;
            int y_;

    };

}
 
 #include "case.hxx"
