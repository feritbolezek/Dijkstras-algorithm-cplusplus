#include "dijkstra.h"
#include <iostream>

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

            if (a < (*d).getValue()) {

                d->setParent(n);
                (*d).setValue(a);
                s.add(d);
            }

        }
        

    }

    
}