//
// Created by ziad on 8/9/23.
//

#ifndef GRAPH_MINSPANNINGTREE_H
#define GRAPH_MINSPANNINGTREE_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include "climits"
using namespace std;


class MinSpanningTree {
private:
    int gSize;
    int spanningCost;
    map<char,vector<pair<char,int>>>graph;
public:
    MinSpanningTree() :gSize(0),spanningCost(0){}
    void insert(char fromvertex ,char toVertex,int distance){
        graph[fromvertex].emplace_back(toVertex,distance);
        gSize++;
    }
    vector<char> getAllAvailableNodes() {
        vector<char> availableNodes;
        for (const auto& entry : graph) {
            availableNodes.push_back(entry.first);
        }
        return availableNodes;
    }
    void addtoUsed(vector<char> &usedVertex,vector<char> &availableVertex,char x){
        auto it = find(availableVertex.begin(), availableVertex.end(), x);

        // If the element is found, erase it
        if (it != availableVertex.end()) {
            availableVertex.erase(it);
            usedVertex.push_back(x);
        }
    }
    void view(vector<pair<char,char>> usedEdges){
        cout << "Minimum Spanning Tree Edges:" << endl;
        for (const auto& edge : usedEdges) {
            cout << edge.first << " - " << edge.second << endl;
        }

        cout << "Minimum Spanning Tree Cost: " << spanningCost << endl;
    }
    bool isNeighbourAvailable(char vertex, const vector<char>& availableNodes) {
        for(int i = 0 ; i<availableNodes.size();i++){
            if(availableNodes[i]== vertex){
                return true;
            }
        }
        return false;
    }



    void spanning(char sourceVertex) {
        vector<pair<char, char>> usedEdges;
        vector<char> usedVertex;
        vector<char> availableNodes = getAllAvailableNodes();
        vector<int> cost(gSize, INT16_MAX);
        addtoUsed(usedVertex, availableNodes, sourceVertex);
        cost[sourceVertex - 'a'] = 0;

        while (!availableNodes.empty()) {
            int minDistance = INT16_MAX;
            pair<char, char> edge;

            for (char used : usedVertex) {
                for (const auto adj : graph[used]) {
                    char neighbour = adj.first;
                    int distance = adj.second;
                    if (isNeighbourAvailable(neighbour,availableNodes) && distance < minDistance) {
                        minDistance = distance;
                        edge = make_pair(used, neighbour);
                    }
                }
            }

            if (minDistance != INT16_MAX) {
                usedEdges.push_back(edge);
                cost[edge.second - 'a'] = minDistance;
                spanningCost += minDistance;
                addtoUsed(usedVertex, availableNodes, edge.second);
            }
        }
        view(usedEdges);
    }


};


#endif //GRAPH_MINSPANNINGTREE_H
