#include "graph.h"

#include <iostream>
#include <algorithm>
#include <stack>


Graph::Graph(std::istream& in) {
    
    std::string city{""};
    std::string distance{""};
    std::string destination{""};

    while(!in.eof()) {

    std::getline(in,city,':');
    std::getline(in,distance, ' ');
    std::getline(in,distance, ' ');
    std::getline(in,destination);

    if (find(city) == nullptr) {
        addNode(city);
    }

    if (find(destination) == nullptr) {
        addNode(destination);
    }

    Node* n = find(city);

    n->addEdge(find(destination),std::stoi(distance));
    

    }
}

void Graph::addNode(const string& name) {    
    nodes.push_back(new Node{name});
}

Node* Graph::find(const string& name) {
    auto it = std::find_if(nodes.begin(),nodes.end(), [&name](Node* n) -> bool { return (*n).getName() == name; });
    if (it != nodes.end()) return &(**it);
    
    return nullptr;
}

void Graph::resetVals() {
    for (auto &n : nodes) (*n).setValue(Node::max_value);
}
