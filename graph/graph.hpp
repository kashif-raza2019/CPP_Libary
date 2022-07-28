#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<int> *adj;
    vector<int> dfs_traversal;
    vector<int> bfs_traversal;
    public:
    // Constructor 
    Graph(int V){
        this->V = V;
        adj = new vector<int>[V];
    }
    // Add an edge to graph
    void addEdge(int v, int w);
    // Prints the graph
    void printGraph();
    //DFS traversal
    void DFS(int v);
    // Print DFS
    void printDFS();
    //BFS traversal
    void BFS(int v);
    // Print BFS
    void printBFS();
    // Adjacency Matrix to Adjacency List
    void adjacencyMatrixToAdjacencyList(vector<vector<int>> adjMat);

};

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::printGraph(){
    for(int v = 0; v < V; v++){
        cout << "Adj list of vertex " << v << ": [";
        for(auto i : adj[v]){
            cout << i << ", ";
        }
        cout<<"NULL ]"<<endl;
    }
}

// DFS traversal from a given vertex
void Graph::DFS(int v){
    dfs_traversal.push_back(v);
    for(auto i : adj[v]){
        if(find(dfs_traversal.begin(), dfs_traversal.end(), i) == dfs_traversal.end()){
            DFS(i);
        }
    }
}

void Graph::printDFS(){
    if(dfs_traversal.empty()){
        cout << "DFS traversal not possible" << endl;
        return;
    }
    cout << "DFS traversal: ";
    for(auto i : dfs_traversal){
        cout << i << " ";
    }
    cout << endl;
}

// BFS traversal
void Graph::BFS(int v){
    bool visited[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while(!q.empty()){
        int val = q.front();
        q.pop();
        bfs_traversal.push_back(val);
        for(auto i : adj[val]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void Graph::printBFS(){
    if(bfs_traversal.size() == 0){
        BFS(0);
    }
    cout << "BFS traversal: ";
    for(auto i : bfs_traversal){
        cout << i << " ";
    }
    cout << endl;
}

void Graph::adjacencyMatrixToAdjacencyList(vector<vector<int>> adjMat){
   if(adjMat.size() == 0){
        cout<< "Adjacency Matrix is empty";
        return;
   }
    for(int i = 0; i < adjMat.size(); i++){
         for(int j = 0; j < adjMat[i].size(); j++){
              if(adjMat[i][j] == 1){
                addEdge(i, j);
              }
         }
    }
    printGraph();    
}
