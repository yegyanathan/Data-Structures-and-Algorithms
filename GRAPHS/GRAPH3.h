#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

class Graph{

    private:

        int V;

    public:

        map<int,list<pair<int,int>>> adj;

        Graph(int V){

            this->V = V;

        }

        int getV(){

            return this->V;

        }

        void addEdge(int u, int v, int wt);

        void LazyPrims();

        void EagerPrims();

};

void Graph::addEdge(int u, int v, int wt){

    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});

}

void Graph::LazyPrims(){

    int minCost = 0;

    priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>> Edges;

    list<pair<int,int>>::iterator itr;

    vector<bool> visited;
    visited.assign(getV(),false);

    int currentNode = 0;
    int edgeCount = 0;

    do{

        visited[currentNode] = true;

        for(auto toNode : adj[currentNode]){

            if(!visited[toNode.first]){

                Edges.push({toNode.second,{currentNode,toNode.first}});

            }
        }

        if(!visited[Edges.top().second.second]){

            minCost += Edges.top().first;
            cout << Edges.top().second.first << "-" << Edges.top().second.second << endl;

            currentNode = Edges.top().second.second;
            edgeCount++;

        }

        Edges.pop();

    }while( !Edges.empty() && edgeCount != getV()-1);
        

    cout << "\n\n" ;
    cout << minCost <<endl;

}