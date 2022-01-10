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

        map<int,list<int>> adj;

        Graph(int V,bool isDirected){

            this->V = V;
            this->isDirected = isDirected;

        }

        int getV(){

            return this->V;

        }

        bool getIsDirected(){

            return isDirected;

        }

        void addEdge(int v1,int v2);

        void BreadthFS(int source);

        void DepthFS(int source);
        void DepthFSUtil(int source,bool *visited);

        void KahnAlgo();

        bool UnionFind(int v,int w)

};

void Graph::addEdge(int v1,int v2){

    if(getIsDirected()){

        adj[v1].push_back(v2);

    }
    else{

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);

    }

}

void Graph::BreadthFS(int source){

    int *parentOf = new int[getV()];
    int *distanceOf = new int[getV()];
    bool *visited = new bool[getV()];

    for(int i = 0; i < getV(); i++){

        visited[i] = false;

    }

    queue<int> q;
    list<int>::iterator itr;

    q.push(source);
    visited[source] = true;
    distanceOf[source] = 0;
    parentOf[source] = -1;

    cout << source << " ";

    while(!q.empty()){
        
        int parent = q.front();

        for(itr = adj[parent].begin();itr != adj[parent].end();itr++){

            if(!visited[*itr]){

                cout << *itr << " ";
                q.push(*itr);
                visited[*itr] = true;
                parentOf[*itr] = parent;
                distanceOf[*itr] = distanceOf[parent] + 1;

            }

        }

        q.pop();

    }

}

void Graph::DepthFSUtil(int source,bool *visited){

    list<int>::iterator itr;

    visited[source] = true;

    cout << source << " ";

    for(itr = adj[source].begin(); itr != adj[source].end(); itr++){

        if(!visited[*itr]){

            DepthFSUtil(*itr,visited);

        }

    }

}

void Graph::DepthFS(int source){

    bool *visited = new bool[getV()];

    for(int i = 0; i < getV(); i++){

        visited[i] = false;

    }

    DepthFSUtil(source,visited);

}

void Graph::KahnAlgo(){

    //find in-degree for each node.

    list<int>::iterator itr,it;

    vector<int> IN;
    IN.assign(getV(),0);

    queue<int> q;

    for(auto ele : adj){

        for(itr = ele.second.begin(); itr != ele.second.end(); itr++){

            IN[*itr]++;

        }

    }
    
    for(int i = 0; i < IN.size(); i++){

        if(IN.at(i) == 0){

            q.push(i);
            IN.at(i) = -1;

        }

    } 

    while(!q.empty()){

        int temp = q.front();

        cout << temp << " ";

        for(it = adj[temp].begin(); it != adj[temp].end(); it++){

            IN[*it]--;

            if(IN[*it] == 0){

                q.push(*it);
                IN.at(*it) = -1;

            }

        }

        q.pop();

    }

}
