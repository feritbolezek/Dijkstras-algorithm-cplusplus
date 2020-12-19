#include <iostream>
#include <fstream>

#include "../graph.h"
#include "../dijkstra.h"

int main() {

    std::ifstream file("../graf.txt");

    Graph g(file);


    dijkstra(g.find("Lund"));

    g.printShortestPath("Veberod");

   // Node* n = g.find("Veberod");
    
    //std::cout << n->getParent()->getParent()->getName() << " " << n->getParent()->getName() << " " << n->getName() << std::endl;

    
    
}