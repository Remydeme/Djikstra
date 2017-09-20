#pragma once

#include <vector>


class Djikstra
{
    
    public :

        using case_s = struct case_s;

    private:

    /* contain that have been visited and that
    are not in closed */

    std::vector<case_s*> open_; 

    /* Closed vector contain the whole of cases that
    corespond to the path  */

    std::vector<case_s*> closed_;
};
