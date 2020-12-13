#ifndef EDGE_H
#define EDGE_H

#include "Node.h"

class Edge {
    public:
        Edge(Node* destination, int length) : destination{destination}, length{length} {};
        Node* getDestination();
        int getLength() const;

    private:
        Node* destination;
        int length;
};

#endif