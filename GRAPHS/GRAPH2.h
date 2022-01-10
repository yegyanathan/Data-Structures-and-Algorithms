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

        vector<pair<int, pair<int,int>>> adj;

        Graph(int V,bool isDirected){

            this->V = V;

        }

        int getV(){

            return this->V;

        }

        void addEdge(int wt, int u, int w);
 
        int Find(int p, vector<int>& id);

        void Union(int s, int d, vector<int>& id, vector<int>& sz);

        void Kruskal();

        void Prims();

};

void Graph::addEdge(int wt, int u, int v){

    adj.push_back({wt, {u,v}});
    adj.push_back({wt, {v,u}});

}

int Graph::Find(int p, vector<int>& id){

    int root = p;

    while(root != id[root]){

        root = id[root];

    }


    while( p != root){

        int next = id[p];
        id[p] = root;
        p = next;

    }

    return root;

}

void Graph::Union(int edgeStart, int edgeEnd, vector<int>& id, vector<int>& sz){

    int root1 = Find(edgeStart,id);
    int root2 = Find(edgeEnd,id);

    if( sz[root1] < sz[root2] ){

        sz[root2] += sz[root1];
        id[edgeStart] = edgeEnd;

    }
    else{

        sz[root1] += sz[root2];
        id[edgeEnd] = edgeStart;

    }

}

void Graph::Kruskal(){

    vector<int> id;
    vector<int> sz;
    id.reserve(getV());
    sz.reserve(getV());
    
    int minSum = 0;

    for(int i = 0; i < getV(); i++){

        id[i] = i;
        sz[i] = 1;

    }

    sort(adj.begin(), adj.end());

   for(auto edge : adj){

       int edgeStart = edge.second.first;
       int edgeEnd = edge.second.second;

       int root1 = Find(edgeStart,id);
       int root2 = Find(edgeEnd,id);

       if(root1 != root2){

           minSum = minSum + edge.first;
           cout << edgeStart << "-" << edgeEnd << endl;

           Union(edgeStart,edgeEnd,id,sz);

       }

   }

   cout << "\n\n" ;
   cout << minSum << endl;

}
