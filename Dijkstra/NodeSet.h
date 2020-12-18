#ifndef NODE_SET_H
#define NODE_SET_H

#include <vector>
#include <limits>
#include <algorithm>

#include "Node.h"

using std::vector;

class NodeSet {
    public:
        NodeSet() = default;
        void add(Node* node);
        bool isEmpty();
        Node* removeMin();


    private:
        vector<Node*> nodes;

};

#endif