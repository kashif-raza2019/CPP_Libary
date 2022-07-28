#include <bits/stdc++.h>
// Graph Header File
#include "./graph.hpp"
using namespace std;

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.printGraph();
    g.DFS(2);
    g.printDFS();
    g.BFS(2);
    g.printBFS();
    return 0;
}