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
        Graph(std::istream& in);
        ~Graph() { for (auto &n : nodes) delete n; };
        void addNode(const string& name);
        Node* find(const string& name);
        void resetVals();
        vector<Node*>::iterator begin() { return nodes.begin(); };
        vector<Node*>::iterator end() { return nodes.end(); };
        void printShortestPath(std::string dest);



    private:
        vector<Node*> nodes;

};


#endif