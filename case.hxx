#pragma once

#include <stdexcept>

#include "case.hh"

namespace Djikstra
{

    inline constexpr Case::Case(int x, int y) : x_(x), y_(y)
    {
        if (x_ < 0)
            throw std::out_of_range("X is lower than 0");
        if (y_ < 0)
            throw std::out_of_range("Y is lower than 0");
    }
   
   inline void Case::cood_set(int x, int y) noexcept
   {
       x_ = x;
       y_ = y;
   }

  
   inline constexpr Case::operator int () const
    {
      return x_; 
    }

    inline void Case::weight_set(int weight) noexcept
    {
        weight_ = weight;
    }

    inline void Case::is_listed_set(bool listed) noexcept
    {
        is_listed_ = listed;
    }

    inline void Case::father_set(Case * const father) noexcept
    {
        father_ = father;
    }


    inline bool Case::is_listed() const noexcept
    {
        return is_listed_;
    }

    inline int Case::weight_get() const noexcept
    {
        return  weight_;
    }

    inline int Case::x_get() const noexcept
    {
        return x_;
    }

    inline int Case::y_get() const noexcept
    {
        return y_;
    }

}
