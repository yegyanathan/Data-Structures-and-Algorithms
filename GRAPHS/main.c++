#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<algorithm>
#include<vector>
#include "GRAPH4.h"

using namespace std;

int main(){

    Graph G(7,false);

    G.addEdge(0,1,1);
    G.addEdge(0,2,1);
    G.addEdge(1,2,3);
    G.addEdge(1,3,2);
    G.addEdge(3,4,1);
    G.addEdge(3,5,7);
    G.addEdge(3,6,1);
    G.addEdge(4,5,4);
    G.addEdge(5,6,9);

    G.Dijkstra(3);

}