#include <iostream>
#include "UnorderedLinkedList.h"
#include "Graph.h"
#include "GraphDijskastra.h"
#include "MinSpanningTree.h"
using namespace std;
int main() {
    GraphDijskastra graph;

    graph.insert('a', 'b', 5);
    graph.insert('a', 'c', 1);
    graph.insert('b', 'c', 2);
    graph.insert('b', 'd', 2);
    graph.insert('c', 'e', 3);
    graph.insert('e', 'd', 4);
    graph.insert('d', 'f', 6);
    graph.insert('e', 'f', 2);

    graph.Disj('a');
    cout<<"End"<<endl;
    cout<<endl;
    MinSpanningTree mst;
    mst.insert('a', 'b', 5);
    mst.insert('a', 'c', 3);
    mst.insert('b', 'c', 2);
    mst.insert('b', 'd', 8);
    mst.insert('c', 'd', 6);

    char sourceVertex = 'a';
    mst.spanning(sourceVertex);


    return 0;

}
