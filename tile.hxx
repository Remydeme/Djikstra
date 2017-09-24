#pragma once

#include <stdexcept>

#include "tile.hh"

namespace Djikstra
{

    inline constexpr Tile::Tile(int x, int y, bool is_start, bool is_arrival) :
        is_arrival_(is_arrival),
        is_start_(is_start),
        x_(x),
        y_(y)
        {  
            if (x_ < 0)
                throw std::out_of_range("X is lower than 0");
            if (y_ < 0)
                throw std::out_of_range("Y is lower than 0");

        }

    inline void Tile::start_set() noexcept
    {
        is_start_ = true; 
    }

    inline void Tile::arrival_set() noexcept 
    {
        is_arrival_ = true;
    }

    inline Tile* Tile::father_get() const noexcept
    {
        return father_;
    }

    inline bool Tile::is_arrival() const noexcept
    {
        return is_arrival_;
    }

    inline void Tile::type_set(char tile) noexcept
    {
        switch (tile)
        {
            case Type::GRASS:
                type_ = Type::GRASS;
                break;

            case Type::WALL:
                type_ = Type::WALL;
                break;

            case Type::ROAD:
                type_ = Type::ROAD; 
                break;

            case Type::WATER:
                type_ = Type::WATER;
            default:
                type_ = Type::WALL;

        }
    }

    inline bool Tile::is_start() const noexcept
    {
        return is_start_;
    }

    inline void Tile::cood_set(int x, int y) noexcept
    {
        x_ = x;
        y_ = y;
    }


    inline constexpr Tile::operator int () const
    {
        return x_; 
    }

    inline void Tile::weight_set(int weight) noexcept
    {
        weight_ = weight;
    }

    inline void Tile::listed_set() noexcept
    {
        is_listed_ = true;
    }

    inline void Tile::father_set(Tile * const father) noexcept
    {
        father_ = father;
    }


    inline bool Tile::is_listed() const noexcept
    {
        return is_listed_;
    }

    inline int Tile::weight_get() const noexcept
    {
        return  weight_;
    }

    inline int Tile::x_get() const noexcept
    {
        return x_;
    }

    inline int Tile::y_get() const noexcept
    {
        return y_;
    }

    inline Tile::Type Tile::type_get() const noexcept
    {
        return type_;
    }

}
