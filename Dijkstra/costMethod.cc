#include "costMethod.h"

void CostMethod::calculate(Node* n, const Edge& i, NodeSet& s) {
        int l = i.getLength();
        Node* d = i.getDest();
        int a = n->getValue() + l;

        if (a < (*d).getValue()) {
            d->setParent(n);
            (*d).setValue(a);
            s.add(d);
        }
}

