#include "dijkstra.h"
#include "costMethod.h"
#include <iostream>
#include <stack>

void dijkstra(Node* start) {
    start->setValue(0);

    NodeSet s{};

    s.add(start);

    while(!s.isEmpty()) {
        Node* n = s.removeMin();

        for (auto &i : n->getEdges())
        {
            int l = i.getLength();
            Node* d = i.getDest();
            int a = n->getValue() + l;

            if (a < (*d).getValue()) { // Kolla i bookmarks, vi kan passera in en function som returnerar en bool. (Funktionen kan utföra sin egen beräkning som ger svar på denna if satsen)

                d->setParent(n);
                (*d).setValue(a);
                s.add(d);
            }

        }
        

    }

    
}

void dijkstra_generalized(Node* start, CostMethod& c) {
    start->setValue(0);

    NodeSet s{};

    s.add(start);

    while(!s.isEmpty()) {
        Node* n = s.removeMin();

        for (auto &i : n->getEdges())
        {
            c.calculate(n,i,s);
        }
        

    }

    
}

void printShortestPath(Node* dest) {
    
    std::stack<Node*> path;
    Node* n = dest;

    while (n->getValue() != 0) {
        path.push(n);
        n = n->getParent();
    }

    path.push(n);

    
    while(!path.empty()) {
        Node* i = path.top();
        path.pop();

        std::cout << i->getName() << " ";
    }


    std::cout << dest->getValue(); // TODO: Fixa om tid över
    std::cout << std::endl;
    

}