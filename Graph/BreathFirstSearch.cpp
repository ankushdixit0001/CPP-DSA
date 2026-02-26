#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj;

    void push(int u,int v,bool direction){
        adj[u].push_back(v);
        if(!direction){   // undirected
            adj[v].push_back(u);
        }
    }

    void printGraph(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j << ",";
            }
            cout<<endl;
        }
    }

    vector<int> BFSTraversal(vector<int> &result, int start) {
        unordered_map<int,bool> visited;
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for(int neighbor : adj[node]) {
                if(!visited[neighbor]) {   // ✅ Correct check
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return result;
    }
};

vector<int> bfsTraversal(Graph &g, int start) {
    unordered_map<int, bool> visited;
    queue<int> q;
    vector<int> result;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : g.adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return result;
}



int main(){
    Graph g;
    g.push(1,2,0);
    g.push(1,3,0);
    g.push(4,2,0);
    g.push(5,2,0);
    g.push(3,5,0);

    g.printGraph();

    // vector<int> result;
    // result = g.BFSTraversal(result, 1);   // ✅ start from node 1

    // cout << "BFS Traversal: ";
    // for(int i:result){
    //     cout << i << " ";
    // }


    
    //saprate function
    vector<int> traversal = bfsTraversal(g, 1);
    cout << "BFS Traversal starting from 1: ";
    for (int v : traversal) {
        cout << v << " ";
    }

    cout << endl;

    return 0;
}