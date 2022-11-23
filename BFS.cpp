// Print all the nodes reachable from a given starting node in a digraph using BFS method
#include<iostream>
using namespace std;
// creating graph class

int WHITE = 0;
int GREY = 1;
int BLACK = 2;


class graph
{
    int **Adj;
    int nodes;
    int* parents;
    int* colors;
    public:
        graph(int N,int** G);
        friend void print(graph &Graph);
};

graph::graph(int N,int** G){
    nodes = N;
    // Allocating memory
    Adj = new int*[nodes];
    for(int np = 0 ; np < nodes ; np++){
        Adj[np] = new int[nodes];
    }
    // Copying values
    for(int r = 0 ; r < nodes ; r++ ){
        for(int c = 0 ; c < nodes ; c++){
            Adj[r][c] = G[r][c];   
        }
    }
    // Allocating parent and color array
    parents = new int[nodes];
    colors = new int[nodes];
    // setting a default value of 1
    for(int npc = 0 ; npc < nodes ; npc++){
        parents[npc] = -1;
        colors[npc] = -1;
    }
}

void print(graph &Graph){
    for(int i = 0 ; i < Graph.nodes ; i++){
        for(int j = 0 ; j < Graph.nodes ; j++){
            cout << Graph.Adj[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    // Getting user input and printing the graph for testing
    int nodes;
    cout << "Enter the number of nodes : " ;
    cin >> nodes;
    int** A = new int*[nodes];
    cout << "Enter the graph : \n";
    for(int r = 0 ; r < nodes ; r++ ){
        A[r] = new int[nodes];
        for(int c = 0 ; c < nodes ; c++){
            cin >> A[r][c];
        }
    }
    graph G(4,A);
    print(G);
}