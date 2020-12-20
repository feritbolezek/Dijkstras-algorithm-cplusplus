#include <iostream>
#include <fstream>

#include "../graph.h"
#include "../dijkstra.h"
#include "../leastCititesVisited.h"

void testGeneralizedCost();
void testGeneralizedLeastCities();
void testReadFromFile();

int main() {

    testGeneralizedCost();
    testGeneralizedLeastCities();
    testReadFromFile();
    
}


void testGeneralizedCost() {
    std::cout << "----------------------TESTING GENERALIZED COST----------------------" << std::endl;

    Node lund{"Lund"};
    Node dalby{"Dalby"};
    Node sandby{"Sodra Sandby"};
    Node hallestad{"Torna Hallestad"};
    Node flyinge{"Flyinge"};
    Node veberod{"Veberod"};
    Node malmo{"Malmo"};
    Node staffanstorp{"Staffanstorp"};

    std::cout << "\033[1;31mExpected:\033[0m Lund Dalby Veberod Malmo 32 \033[1;31mGot:\033[0m ";
    
    lund.addEdge(&dalby,12);
    lund.addEdge(&sandby,12);
    lund.addEdge(&staffanstorp,40);
    dalby.addEdge(&sandby,12);
    dalby.addEdge(&veberod,11);
    dalby.addEdge(&hallestad,5);
    sandby.addEdge(&lund,12);
    sandby.addEdge(&flyinge,4);
    hallestad.addEdge(&veberod,8);
    veberod.addEdge(&malmo,9);
    flyinge.addEdge(&malmo,17);
    staffanstorp.addEdge(&malmo,10);

    
    CostMethod l;

    dijkstra_generalized(&lund,l);

    printShortestPath(&malmo);
    std::cout << "--------------------------------------------------------------------" << std::endl;

}

void testGeneralizedLeastCities() {
    std::cout << "----------------------TESTING GENERALIZED CITIES VISITED----------------------" << std::endl;
    Node lund{"Lund"};
    Node dalby{"Dalby"};
    Node sandby{"Sodra Sandby"};
    Node hallestad{"Torna Hallestad"};
    Node flyinge{"Flyinge"};
    Node veberod{"Veberod"};
    Node malmo{"Malmo"};
    Node staffanstorp{"Staffanstorp"};

    std::cout << "\033[1;31mExpected:\033[0m Lund Staffanstorp Malmo 2 \033[1;31mGot:\033[0m ";
    
    lund.addEdge(&dalby,1);
    lund.addEdge(&sandby,1);
    lund.addEdge(&staffanstorp,40);
    dalby.addEdge(&sandby,1);
    dalby.addEdge(&veberod,1);
    dalby.addEdge(&hallestad,1);
    sandby.addEdge(&lund,1);
    sandby.addEdge(&flyinge,1);
    hallestad.addEdge(&veberod,1);
    veberod.addEdge(&malmo,1);
    flyinge.addEdge(&malmo,1);
    staffanstorp.addEdge(&malmo,10);

    LeastCitiesVisited l;

    dijkstra_generalized(&lund,l);

    printShortestPath(&malmo);
    std::cout << "------------------------------------------------------------------------------" << std::endl;

}

void testReadFromFile() { 
    std::cout << "----------------------TESTING READ CITIES FROM FILE----------------------" << std::endl;

    std::ifstream file("../graf.txt");

    Graph g(file);

    std::cout << "\033[1;31mExpected:\033[0m Lund Dalby Veberod 23 \033[1;31mGot:\033[0m ";

    dijkstra(g.find("Lund"));

    printShortestPath(g.find("Veberod"));
    std::cout << "-------------------------------------------------------------------------" << std::endl;
}