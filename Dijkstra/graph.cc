#include "graph.h"

#include <iostream>
#include <algorithm>

void Graph::addNode(const string& name) {
    // std::cout << "Added: " << name << std::endl;
    nodes.push_back(new Node{name});
}

Node* Graph::find(const string& name) {
    auto it = std::find_if(nodes.begin(),nodes.end(), [&name](Node* n) -> bool { return (*n).getName() == name; });
    //std::cout << "Looking for: " << name << ", Found: " << (**it).getName() << std::endl;
    if (it != nodes.end()) return &(**it);

    return nullptr;
}

void Graph::resetVals() {
    std::transform(nodes.begin(),nodes.end(), nodes.begin(), [](Node* n) -> Node* { (*n).setValue(Node::max_value); });
}