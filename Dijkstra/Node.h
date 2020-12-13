#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include "Edge.h"

using std::string;
using std::vector;

class Node {

    public:
        Node(const string& name) : name{name} {};
        string getName() const;
        void setValue(int v);
        int getValue() const;
        void addEdge(Node* destination, int length);
        const vector<Edge>& getEdges() const;

    private:
        string name;
        int value;
        vector<Edge> edges;

};
#endif