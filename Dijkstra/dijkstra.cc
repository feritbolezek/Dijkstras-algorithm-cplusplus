#include "dijkstra.h"

void dijkstra(Node* start) {
    start->setValue(0);

    NodeSet s{};

    s.add(start);

    while(!s.isEmpty()) {
        Node n = *s.removeMin();

        for (auto &i : n.getEdges())
        {
            int l = i.getLength();
            Node* d = i.getDest();
            int a = n.getValue() + l;

            if (a < (*d).getValue()) {
                (*d).setValue(a);
                s.add(d);
            }

        }
        

    }

    
}