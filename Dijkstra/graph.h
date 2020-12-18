#ifndef GRAPH_H
#define GRAPH_H

#include <memory>

#include "Node.h"
#include "Edge.h"

using std::string;
using std::vector;

class Graph {

    public:
        Graph() = default;
        void addNode(const string& name);
        Node* find(const string& name);
        void resetVals();
        vector<Node*>::iterator begin() { return nodes.begin(); };
        vector<Node*>::iterator end() { return nodes.end(); };



    private:
        vector<Node*> nodes;

};


#endif