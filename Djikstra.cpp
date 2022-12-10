// Implementation of djikstras algorithm 

#include <iostream>
#include <climits>

using namespace std ;

const int N = 5;


class djikstra{
    int* weights;
    int* parents;
    bool* emptyQ;
    int** graph;
    int src;
    int Nodes;
    int* Path;
    public:
        djikstra(int ingraph[N][N],int source,int Nds){
            // Store the distance of weights
            Nodes= Nds;
            int traversed = 0 ;
            // Storing the value of graph
            graph = new int* [Nodes];
            for(int i = 0 ; i < Nodes ; i++){
                graph[i] = new int [Nodes];
                for(int j = 0 ; j < Nodes ; j++){
                    graph[i][j] = ingraph[i][j];
                }
            }
            weights = new int[Nodes];
            parents = new int[Nodes];
            // To check wheter an element is traversed or not
            emptyQ = new bool[Nodes];
            // initialize the nodes
            init_single_source();
            // To store the traversal path
            Path = new int [Nodes];
            while (traversed < Nodes){
                int u = extract_min_node();
                Path[traversed] = u;
                traversed++;
                for(int v = 0 ; v < Nodes ; v++){
                    // If 2 nodes share a connection
                    if (graph[u][v] != 0){
                        cout << graph[u][v];
                        relax(u,v);
                    }
                }
            }
        }
        void init_single_source(){
            for(int i = 0 ; i < Nodes ; i++){
                weights[i] = INT_MAX;
                parents[i] = NULL;
            }
            weights[src] = 0;
        }
        void relax(int u,int v){
            if (weights[v] > weights[u] + graph[u][v]){
                weights[v] = weights[u] + graph[u][v];
                parents[v] = u;
            }
        }
        int extract_min_node(){
            // return index with minimal weight
            int min = weights[0];
            for(int i = 0 ; i < N ; i++){
                if (weights[i] <= min){
                    min = weights[i];
                }
            }
            return min;
        }
        void print_results(){
            cout << "Path : ";
            for(int i = 0 ; i < Nodes - 1 ; i++){
                cout << Path[i] << "-->";
            }
            cout << Path[Nodes-1];
            cout << "\nNode\tParents\n";
            for(int i = 0 ; i < Nodes  ; i++){
                cout << i << "\t" << parents[i] << "\n";
            }
        }
};

int main()
{
    int ingraph[N][N] = {
        { 0 , 10, 3 , 0 , 0 },
        { 0 , 0 , 4 , 2 , 0 },
        { 3 , 4 , 0 , 8 , 2 },
        { 0 , 0 , 0 , 0 , 7 },
        { 0 , 0 , 0 , 9 , 0 }
    };
    djikstra d = djikstra(ingraph,0,5);
    d.print_results();
}