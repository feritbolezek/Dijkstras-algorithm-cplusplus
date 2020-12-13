#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include <limits>
#include "Edge.h"

using std::string;
using std::vector;
using std::numeric_limits;

class Node {

    public:
        Node(const string& name) : name{name} { value = max_value; };
        string getName() const;
        void setValue(int v);
        int getValue() const;
        void addEdge(Node* destination, int length);
        const vector<Edge>& getEdges() const;
        static const int max_value = numeric_limits<int>::max();

    private:
        string name;
        int value;
        vector<Edge> edges;

};
#endif