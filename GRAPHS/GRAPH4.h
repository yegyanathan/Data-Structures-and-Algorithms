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
        bool isDirected;

    public:

        map<int,list<pair<int,int>>> adj;

        Graph(int V, bool isDirected){

            this->V = V;
            this->isDirected = isDirected;

        }

        int getV(){

            return this->V;

        }

        bool getIsDirected(){

            return this->isDirected;

        }

        void addEdge(int u, int v, int wt);

        void Dijkstra(int source);

};

void Graph::addEdge(int u, int v, int wt){

    if(getIsDirected()){

        adj[u].push_back({wt,v});

    }
    else{

        adj[u].push_back({wt,v});
        adj[v].push_back({wt,u});

    }

}

void Graph::Dijkstra(int source){

    //calculating distance of other nodes from source node.
    //vector keeps track of min distance path of the node from source.
    vector<int> distFromSource;
    distFromSource.assign(getV(),30000);
    distFromSource[source] = 0;

    vector<bool> visited;
    visited.assign(getV(),false);

    list<pair<int,int>>::iterator itr;

    int currentNode = source;
    visited[currentNode] = true;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> toNodes;
    toNodes.push({currentNode,distFromSource[currentNode]});

    while(!toNodes.empty()){

        for(itr = adj[currentNode].begin(); itr != adj[currentNode].end(); ++itr ){

            if(!visited[(*itr).second]){

                toNodes.push((*itr));
                
                if(distFromSource[(*itr).second] > distFromSource[currentNode] + (*itr).first){

                    distFromSource[(*itr).second] = distFromSource[currentNode] + (*itr).first;

                }

            }

        }

        if(!visited[toNodes.top().second]){

            currentNode = toNodes.top().second;
            visited[currentNode] = true;

        }

        toNodes.pop();

    }

    for(int i = 0; i < distFromSource.size(); i++){

        cout << i << " - " << distFromSource[i] << endl;

    }

}