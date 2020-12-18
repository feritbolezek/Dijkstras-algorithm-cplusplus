#include <iostream>
#include "NodeSet.h"

using std::numeric_limits;

void NodeSet::add(Node* node) { 
    if (std::find(nodes.begin(), nodes.end(),node) == nodes.end()) nodes.push_back(node); 
}

bool NodeSet::isEmpty() { return nodes.empty(); }

Node* NodeSet::removeMin() {
    auto it = std::min_element(nodes.begin(),nodes.end(),
        [](Node* l,Node* r) -> int { return (*l).getValue() < (*r).getValue(); } );
    
    Node* res = nullptr;

    if (it != nodes.end()) {
        res = *it;
        nodes.erase(it);
    }

    return res;
}