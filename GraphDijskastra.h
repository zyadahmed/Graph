//
// Created by ziad on 8/8/23.
//

#ifndef GRAPH_GRAPHDIJSKASTRA_H
#define GRAPH_GRAPHDIJSKASTRA_H
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

class GraphDijskastra {
private:
    map<char,vector<pair<char,int>>>graph;
    int gSize;
    char findMinNode(vector<int>&cost,vector<bool>&vis){
        int size = cost.size();
        int min = 1000000;
        char ans;
        for(int i=0;i<size;i++){
            if(!vis[i] && cost[i] < min){
                min = cost[i];
                ans = 'a'+i;
            }
        }
        return ans;
    }

public:
    GraphDijskastra() : gSize(0) {}  // Initialize gSize to 0 in the constructor

    void insert(char fromvertex ,char toVertex,int distance){
        graph[fromvertex].emplace_back(toVertex,distance);
        gSize++;
    }
    void Disj(char vertex){
        vector<int>cost(gSize,100000);
        vector<bool> visited(gSize, false);
        vector<char> parent(gSize,'0');
        vector<pair<char,int>>q;
        cost[0] = 0;
        for(int i = 0 ;i<gSize-1;i++){
            char from = findMinNode(cost,visited);
            cout << "smallest cost now is : " << from << endl;
            for(pair<char,int> p : graph[from]){
                char to = p.first;
                int distance = p.second;
                if(!visited[to-'a'] && cost[from-'a']+distance < cost[to-'a']){
                    cost[to-'a'] = cost[from-'a']+distance ;
                    parent[to-'a'] = from;
                }

            }
            visited[from-'a'] = true;
        }
        traversing(cost,visited,parent);
    }
    void traversing(vector<int>&cost,vector<bool> &visited,vector<char> &parent){
        for(int i = 0 ; i<6 ;i++){
            cout<<"Path from a to "<< (char)('a'+i) <<" = "<<cost[i]<<endl;
            cout << "Parent of : " << (char)('a'+i) << " = " << parent[i] << endl;
            cout << endl << endl;

        }
    }

};


#endif //GRAPH_GRAPHDIJSKASTRA_H
