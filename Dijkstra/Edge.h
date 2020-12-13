#ifndef EDGE_H
#define EDGE_H

class Node;

class Edge {
    public:
        Edge() = default;
        Edge(Node* destination, int length) : _destination{destination}, _length{length} {};
        Node* getDest() const;
        int getLength() const;

    private:
        Node* _destination;
        int _length;
};

#endif