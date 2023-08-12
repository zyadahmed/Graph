//
// Created by ziad on 8/8/23.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include "UnorderedLinkedList.h"
#include <fstream>
#include <queue>
using namespace std;
class Graph {
public:
    bool isEmpty(){
        return gSize;
    }
    void clearGraph(){
        for(int i = 0 ;i<gSize;i++){
            graph[i].clear();
        }
        gSize = 0;
    }
    Graph(int size){
        maxSize = size;
        gSize = 0;
        graph = new UnorderedLinkedList [size];
    }
    void printGraph(){
        for(int i = 0 ;i< gSize;i++){
            cout<< i << " ";
            graph[i].print();
            cout<<endl;
        }
        cout<<endl;
    }
    void createGraph(){
        ifstream infile;
        int vertex;
        int adjecentvertex;
        if(gSize != 0)
            clearGraph();
        infile.open("/home/ziad/myDisk/c++ my projects/Graph/input.txt");
        if(!infile){
            cout<<"cannot open file";
            return ;
        }
        infile >> gSize;
        for(int i = 0 ; i<gSize;i++){
            infile >> vertex;
            infile>>adjecentvertex;
            while (adjecentvertex != -999 ){
                graph[vertex].insertAtEnd(adjecentvertex);
                infile >>adjecentvertex;
            }
        }
        infile.close();
    }
    ~Graph(){
        clearGraph();
    }
    void depthFirst(){
        bool * vistied;
        vistied = new bool [gSize];
        for(int i = 0 ; i<gSize;i++){
            vistied[i] = false;
        }
        for(int i = 0 ;i<gSize;i++){
            if(!vistied[i])
                dfs(i,vistied);
        }
//        dfs(0,vistied);
        delete [] vistied;
    }
    void breadthFirst(){
        bool * visited = new bool [gSize];
        for (int i = 0; i < gSize; ++i) {
            visited[i] = false;
        }
        queue<int> traversing;
        for(int i = 0 ;i<gSize;i++){
            if(!visited[i]){
                visited[i] = true;
                cout<< i<<" ";
                traversing.push(i);
                while (!traversing.empty()){
                        int currentVertex = traversing.front();
                        traversing.pop();
                        Node* current = graph[currentVertex].getHead();
                        while(current != nullptr){
                            if(!visited[current->data]){
                                visited[current->data] = true;
                                cout<<current->data;
                                traversing.push(current->data);
                            }
                            current = current->next;
                        }

                }
            }
        }
        delete [] visited;
    }

protected:
    int maxSize ; // num of V
    int gSize; //current size of v
    UnorderedLinkedList *graph;
private:
    void dfs(int index ,bool visited[]){
       visited[index] = true;
       cout<<" "<<index<<" ";
       Node * current = graph[index].getHead();
        while (current!= nullptr){
            int next = current->data;
            if(!visited[next]){
                dfs(next,visited);
            }
            current = current->next;
        }

    }


};


#endif //GRAPH_GRAPH_H
