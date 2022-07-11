#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;


struct Edge{
    int source;
    int dest;
    int weight;
};

bool comparator(Edge a, Edge b){
    return a.weight < b.weight;
}

int checkParent(int node,int parents[]){
    if(parents[node] == node){
        return node;
    }
    return checkParent(parents[node], parents);
}


void makeMst(int edges,int vertices,Edge input[]){
    sort(input,input+edges,comparator);
    Edge output[vertices-1];
    int count = 0;
    int parents[vertices];
    for(int i=0;i<vertices;i++){
        parents[i] = i;
    }
    int i= 0;
    while(count != vertices-1){
//        cout << input[i].source << " " <<  input[i].dest << " " << input[i].weight;
//        cout << endl;
//        cout << checkParent(input[i].source,parents) << " " << checkParent(input[i].dest,parents) << endl;
        int sourceParent = checkParent(input[i].source,parents);
        int destParent = checkParent(input[i].dest,parents);
        if(checkParent(input[i].source,parents)  != checkParent(input[i].dest,parents) ){
            output[count].source = input[i].source;
            output[count].dest = input[i].dest;
            output[count].weight = input[i].weight;
            parents[sourceParent] = destParent;
            count++;
        }
        i++;
    }
    cout << endl;
    for(int i=0;i<count;i++){
        cout << min(output[i].source,output[i].dest) << " " <<  max(output[i].dest,output[i].source )<< " " <<  output[i].weight ;
        cout << endl;
    }
}

int main(){
    int vertices;
    int edges;
    cin >> vertices >> edges;
    Edge input[edges];
    for(int i=0;i<edges;i++){
        int v1;
        int v2;
        int weight;
        cin >> v1 >> v2 >> weight;
        input[i].source = v1;
        input[i].dest = v2;
        input[i].weight = weight;
    }
    makeMst(edges,vertices,input);
}
