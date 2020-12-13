#include "Node.h"

string Node::getName() const { return name; }

void Node::setValue(int v) { value = v; }

int Node::getValue() const { return value; }

void Node::addEdge(Node* destination, int length) { 
    Edge e{destination,length};
    edges.push_back(e); 
    }

const vector<Edge>& Node::getEdges() const { return edges; }