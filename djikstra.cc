#include <iostream>

#include "djikstra.hh"

namespace Djikstra
{

    Djikstra::Djikstra(Map* map, Tile&& start, Tile&& end) : map_(map),
    start_(start),
    end_(end)
    {   
        if (!start_.is_start())
            start_.start_set();
        if (!end_.is_arrival())
            end_.arrival_set();
        start_.listed_set();
    }

    Djikstra::Djikstra(Map* map, Tile& start, Tile& end) : map_(map),
    start_(start),
    end_(end)
    {
        if (!start_.is_start())
            start_.start_set();
        if (!end_.is_arrival())
            end_.arrival_set();
        start_.listed_set();
    }

    void display(Tile* c)
    {
        std::cout << "current : x : " << c->x_get() << " y : "<< c->y_get() << " w : " << c->weight_get() << "\n";
    }

    Tile* Djikstra::search()
    {
        std::vector<Tile*> closed;
        std::vector<Tile*> open_;
        Tile* current = nullptr;
        Tile* neighbour = nullptr;

        int weight = 0;

        open_.push_back(&start_);

        while (open_.size() > 0)
        {
            current = (*map_)(open_[0]->x_get(), open_[0]->y_get());
            closed.push_back(current);
            open_.erase(open_.begin());
            /*Stop when we have found the end of the road*/
            display(current); /* debugging*/ 
            if (current->x_get() == end_.x_get() && current->y_get() == end_.y_get())
                break;
            else
            {
                /* We check all the neighbour around */
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        std::cout << "\n\n Map : \n";
                        for (int i = 0; i < map_->h_get(); i++)
                        {
                            for (int j = 0; j < map_->w_get(); j++)
                            {
                                std::cout << ((*map_)(i, j))->weight_get() << " ";
                            }
                            std::cout << "\n";
                        }

                        if (!((x == 0) && (y == 0)))
                        {
                            if (current->x_get() + x >= 0 && current->x_get() + x < map_->h_get()
                                    && current->y_get() + y >= 0 && current->y_get() + y < map_->w_get())
                            {
                                if ((*map_)(current->x_get() + x, current->y_get() + y)->type_get() ==
                                        Tile::Type::WALL 
                                       /* && (*map_)(current->x_get(), current->y_get() + y)->type_get() ==
                                        Tile::Type::WALL*/)
                                {
                                    continue;
                                }
                                neighbour = (*map_)(current->x_get() + x, current->y_get() + y);
                                if ((x != 0) && (y != 0))
                                    weight = 14;
                                else
                                    weight = 10;
                                if (neighbour->type_get() != Tile::Type::WALL)
                                {
                                    if (!neighbour->is_listed())
                                    {
                                        neighbour->listed_set(); // have been visited 
                                        neighbour->father_set(current); 
                                        neighbour->weight_set(current->weight_get() + weight); // new weight of the node
                                        if (open_.size() > 0) // if there is Tile in the array
                                        {
                                            bool inserted = false;
                                            for (unsigned int i = 0; i < open_.size() && !inserted; i++)
                                            {
                                                /*replace Tile at i by a Tile with a lower weight*/
                                                if (neighbour->weight_get() < open_[i]->weight_get())
                                                {
                                                    open_.insert(open_.begin() + i, neighbour);
                                                    inserted = true;
                                                }
                                            }
                                            if (!inserted)
                                                open_.push_back(neighbour);
                                        }
                                        else
                                            open_.push_back(neighbour);
                                    }
                                    else
                                    {

                                        /* if this node have already been visited  we will have is weight that is lower
                                           than  CurrWeight + weight */
                                        if (current->weight_get() + weight < neighbour->weight_get())
                                        {
                                            bool inopen = false;
                                            neighbour->weight_set(current->weight_get() + weight);
                                            neighbour->father_set(current);
                                            for (unsigned int i = 0; i < open_.size(); i++)
                                            {
                                                // delete the node at is old position
                                                if (open_[i] == neighbour)
                                                {
                                                    inopen = true;
                                                    open_.erase(open_.begin() + i);
                                                    bool inserted = false;
                                                    for (unsigned int j = 0; j < open_.size() && !inserted; j++)
                                                    {
                                                        if (neighbour->weight_get() < open_[j]->weight_get())
                                                        {
                                                            open_.insert(open_.begin() + j, neighbour);
                                                            inserted = true;
                                                        }
                                                    }
                                                    if (!inserted)
                                                        open_.push_back(neighbour);

                                                }
                                            }

                                            /*
                                               If the node is listed but is not in the open array that mean that 
                                               this point constitute the path so we erase this point of the path.
                                             */
                                            if (!inopen)
                                            {
                                                for(unsigned int i = 0; i < closed.size(); i++)
                                                {
                                                    if (neighbour == closed[i])
                                                    {
                                                        closed.erase(closed.begin() + i);
                                                        bool inserted = false;
                                                        for (unsigned int j = 0; j < open_.size() && !inserted; j++)
                                                        {
                                                            if (neighbour->weight_get() < open_[j]->weight_get())
                                                            {
                                                                open_.insert(open_.begin() + j, neighbour);
                                                                inserted = true;
                                                            }
                                                        }
                                                        if (!inserted)
                                                            open_.push_back(neighbour);
                                                    }
                                                }
                                            }

                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (current == (*map_)(end_.x_get(), end_.y_get()))
        {
            do
            {
                path_.push_back(current);
                current = current->father_get();
            } while (current != (*map_)(start_.x_get(), start_.y_get()));
            path_.push_back(current);
        }
            std::cout << "\n\n Road is :  \n\n\n";
        for (auto it : path_)
            display(it);
        return closed[0];
    }
}
