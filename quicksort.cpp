/*
Sort a given set of elements using the Quicksort method 
Determine the time required to sort the elements.
Repeat the experiment for different values of n, the number of
elements in the list to be sorted and plot a graph of the time taken versus n. The elements
can be read from a file or can be generated using the random number generator. 
*/

#include<iostream>
using namespace std;

class Quicksort{
    int* A;
    int UB;
    int LB;
    public:
        void Quicksort(int* Arr,int L,int U);
        void Sort(int* Arr,int L,int U);
        int Partition(int* &Arr,int L,int U);
};

void Quicksort::Sort(int* A,int L,int U){
    if (UB > LB){
        int q = this->Partition(A,L,U);
        this->Sort(A,L,q);
        this->Sort(A,q+1,U);
    }
}
 
int Quicksort::Partition(int* &A,int L,int U){
    int x = A[U];
    int i = L - 1;
    for(int j = l , j < U - 1 ; j++){
        if (A[j] <= x){
            i++;
            int t = A[i];
            A[i] = A[j];
            A[j] = t ; 
        }
    }
    int t = A[i+1];
    A[i+1] = A[U];
    A[U] = t ;
    return i + 1 ;
}

int main(){
    cou
}
