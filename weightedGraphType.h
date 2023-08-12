//
// Created by ziad on 8/8/23.
//

#ifndef GRAPH_WEIGHTEDGRAPHTYPE_H
#define GRAPH_WEIGHTEDGRAPHTYPE_H

#include "Graph.h"
#include <cfloat>

class weightedGraphType : public Graph{
public:

    void shortestPath(int vertex){
            for(int j = 0 ; j<gSize;j++){
                smallestWeight[j] = weights[vertex][j];
            }
            bool *visited = new bool[gSize];
            for(int i = 0 ; i<gSize;i++){
                visited[i] =false;
            }
            visited[vertex] = true;
            smallestWeight[vertex] = 0;
            for(int i = 0 ; i< gSize;i++){
                double minWeight = DBL_MAX;
                int v;
                for (int j = 0; j < gSize; ++j) {
                    if(!visited[j]){
                        if(!smallestWeight[j] < minWeight){
                            v = j;
                            minWeight = smallestWeight[v];
                        }
                    }
                }
                visited[v] = true;
                for(int j = 0 ; j < gSize;j++){
                    if(!visited[j]){
                        if(minWeight +  weights[v][j]<smallestWeight[j])
                            smallestWeight[j] = minWeight+weights[v][j];
                    }
                }

            }



    }
    void printShortestPath();

    weightedGraphType(int size) : Graph(size) {
        createGraph();
        weights = new double *[gSize];
        smallestWeight = new double[gSize];
        srand(time(nullptr));
        for(int i = 0 ; i<gSize;i++){
            weights[i] = new double [gSize];
            for(int j = 0 ; j< gSize;j++){
                if(graph[i].isAdjacent(j)){
                    if(i==j){
                        weights[i][j] = 0;
                    }else{
                        weights[i][j] = (rand()%100)+1;
                    }
                }else{
                    weights[i][j] = DBL_MAX;
                }
            }

        }
    }
    ~weightedGraphType();
protected:
    double **weights;
    double * smallestWeight;

};


#endif //GRAPH_WEIGHTEDGRAPHTYPE_H
