#ifndef COST_METHOD_H
#define COST_METHOD_H

#include "Node.h"
#include "Edge.h"
#include "NodeSet.h"

class CostMethod {

    public:
        virtual void calculate(Node* n, const Edge& i, NodeSet& s);
};


#endif