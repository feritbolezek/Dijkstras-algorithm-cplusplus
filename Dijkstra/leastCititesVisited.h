#ifndef LEAST_CITIES_VISITED_H
#define LEAST_CITIES_VISITED_H

#include "costMethod.h"

class LeastCitiesVisited : public CostMethod {

    public:
        void calculate(Node* n, const Edge& i, NodeSet& s) override;

};


#endif