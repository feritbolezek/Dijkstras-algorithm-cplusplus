#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#define INFO

#include "NodeSet.h"
#include "costMethod.h"


void dijkstra(Node* start);
void dijkstra_generalized(Node* start, CostMethod& c);
void printShortestPath(Node* dest);

#endif