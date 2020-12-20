#include "Node.h"
#include <iostream>

string Node::getName() const { return name; }

void Node::setValue(int v) { value = v; }

int Node::getValue() const { return value; }

Node* Node::getParent() { return parent; }

void Node::setParent(Node* node) { parent = node; }

void Node::addEdge(Node* destination, int length) { edges.push_back(Edge{destination,length}); }

const vector<Edge>& Node::getEdges() const { return edges; }