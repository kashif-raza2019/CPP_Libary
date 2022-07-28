#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    unordered_map<int, vector<int>> adj;
    vector<int> dfs_traversal;
    vector<int> bfs_traversal;
    public:
    // Constructor
    Graph(int V){
        this->V = V;
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
    for(auto i : adj){
        cout << "Adj list of vertex " << i.first << ": [";
        for(auto j : i.second){
            cout << j << ", ";
        }
        cout<<"NULL ]"<<endl;
    }
}

void Graph::DFS(int v){
    dfs_traversal.push_back(v);
    for(auto i : adj[v]){
        if(find(dfs_traversal.begin(), dfs_traversal.end(), i) == dfs_traversal.end()){
            DFS(i);
        }
    }
}

void Graph::printDFS(){
    for(auto i : dfs_traversal){
        cout << i << " ";
    }
    cout << endl;
}

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
    for(auto i : bfs_traversal){
        cout << i << " ";
    }
    cout << endl;
}

void Graph::adjacencyMatrixToAdjacencyList(vector<vector<int>> adjMat){
    for(int i = 0; i < adjMat.size(); i++){
        for(int j = 0; j < adjMat[i].size(); j++){
            if(adjMat[i][j] == 1){
                adj[i].push_back(j);
            }
        }
    }
}

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.printGraph();
    g.DFS(2);
    g.printDFS();
    g.BFS(0);
    g.printBFS();
    return 0;
}