//
//  main.cpp
//  DijkstraAlgorithm
//
//  Created by Nabreet Ghumman on 2020-06-04.
//  Copyright © 2020 Nabreet Ghumman. All rights reserved.
//

#include <iostream>

using namespace std;
  
// Number of vertices in the graph
#define V 9
#define INFINITY 999

//cost[][] matrix stores cost of each vertex
//src is the source node
//dist[] array to store cost of each node form source node
//parent[] arary to keep track of parent of each node
int cost[V][V],src, dist[V], parent[V];
bool visited[V] = {0};

//create cost matrix
//initializ dist[] array to INFINITY
void init(int graph[V][V])
{
    for(int i = 0; i < V; i ++){
        parent[i] = i;
        dist[i] = INFINITY;
        for(int j = 0; j < V; j++)
            if(graph[i][j] == 0)
                cost[i][j] = INFINITY;
        else
            cost[i][j] = graph[i][j];
    }
    dist[src] = 0;
};

//return the next nearest unvisited node
int getNextNode()
{
    int minValue = INFINITY;
    int nextNode = 0;
    for (int i = 0; i < V; i++)
        if(dist[i] < minValue && !visited[i]){
            minValue = dist[i];
            nextNode = i;
        }
    return nextNode;
};

//dijkstra algorithm
void dijkstra()
{
    for(int i = 0; i < V; i++){
        int nextNode = getNextNode();
        visited[nextNode] = 1;
        
        for(int adjNode = 0; adjNode < V; adjNode++){
            if(cost[nextNode][adjNode] != INFINITY && cost[nextNode][adjNode] + dist[nextNode] < dist[adjNode]){
                dist[adjNode] = cost[nextNode][adjNode] + dist[nextNode];
                parent[adjNode] = nextNode;
            }
        }
    }
};

//prints cost and path of each node from source node
void display()
{
    cout << "Node: \t\tCost:\t\tPath" << endl;
    for(int i = 0; i < V; i++){
        cout << i << "\t\t\t" << dist[i]<<"\t\t\t" << " ";
        
        cout << i << " ";
        int parentNode = parent[i];
        
        while(parentNode!=src){
            cout << " <- " << parentNode << " ";
            parentNode = parent[parentNode];
        }
        cout << " <- " << src << endl;
        
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
 int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    
 src = 0;
    
    init(graph);
    dijkstra();
    display();
    
}
