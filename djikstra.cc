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


    Tile* Djikstra::search()
    {
        Tile* current;
        Tile* neighbour;

        int weight = 0;

        open_.push_back(&start_);

        while (true)
        {
            current = (*map_)(open_[0]->x_get(), open_[0]->y_get());
            path_.push_back(current);
            open_.erase(open_.begin());
            /*Stop when we have found the end of the road*/
            if (current->x_get() == end_.x_get() && current->y_get() == end_.y_get())
                break;
            else
            {
                /* We check all the neighbour around */
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (x != 0 && y != 0)
                        {
                            if (current->x_get() + x >= 0 && current->x_get() + x < map_->h_get()
                                    && current->y_get() + y >= 0 && current->y_get() + y < map_->w_get())
                            {
                                if ((*map_)(current->x_get() + x, current->y_get())->type_get() == Tile::Type::WALL &&
                                        (*map_)(current->x_get(), current->y_get() + y)->type_get() == Tile::Type::WALL)
                                {
                                    continue;
                                }
                                neighbour = (*map_)(current->x_get() + x, current->y_get() + y);
                                if (x != 0 && y != 0)
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
                                                if (!inserted)
                                                    open_.push_back(neighbour);
                                            }
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
                                                        if (neighbour->weight_get() < current->weight_get())
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
                                                 bool inserted = false;
                                                for(unsigned int i = 0; i < path_.size(); i++)
                                                {
                                                    if (neighbour == path_[i])
                                                    {
                                                        path_.erase(path_.begin() + i);
                                                        for (unsigned int j = 0; j < open_.size() && !inserted; j++)
                                                        {
                                                            if (neighbour->weight_get() < open_[i]->weight_get())
                                                            {
                                                                open_.insert(open_.begin() + j, neighbour);
                                                                inserted = true;
                                                            }
                                                        }
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
    return path_[0];
    }
}
