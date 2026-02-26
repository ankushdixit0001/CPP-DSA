#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>> adj;

    void push(int u,int v, int direction){
        adj[u].push_back(v);//u =node1,   v=node2
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printGraph(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    graph g;
    g.push(1,2,0);
    g.push(1,3,0);
    g.push(4,2,0);
    g.push(5,2,0);
    g.push(3,5,0);

    g.printGraph();
    return 0;
}