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


   // std::cout << "city: " << city << " ";
   // std::cout << "distance: " << distance << " ";
   // std::cout << "destination: " << destination << std::endl;

    if (find(city) == nullptr) {
        addNode(city);
    }

    if (find(destination) == nullptr) {
        addNode(destination);
    }

    Node* n = find(city);

   // std::cout << "distance is: " << distance << std::endl;

    n->addEdge(find(destination),std::stoi(distance)); // TODO: DETTA KAN KRASCHA PROGRAMMET OM DEN INTE KAN GÖRAS OM TILL INT.
    

    }

    /*for (auto &i : nodes) VÄRDEFULL FÖR TEST
    {
        std::cout << "THIS: " << i->getName() << std::endl;
        for (auto &j : i->getEdges())
        {
            std::cout << "---" << j.getLength() << " " << j.getDest()->getName() << std::endl;
        }
        
    }*/



}

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
    //std::transform(nodes.begin(),nodes.end(), nodes.begin(), [](Node* n) -> Node* { (*n).setValue(Node::max_value); });

    for (auto &n : nodes) (*n).setValue(Node::max_value);

}
