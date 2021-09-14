#include<bits/stdc++.h>
using namespace std;

int Node, Edge ;
vector<vector<int>> graph ;
vector<int> vis ;


void dfs(int node, int parent, int depthLimit){
    vis[node] = 1 ;
    cout << node << " ";
    if(depthLimit == 0) return;
    for(auto x : graph[node]){
        if(x == parent || vis[x]) continue ;
        cout << " -> ";
        dfs(x,node,depthLimit-1) ;
    }

}


void solve(){
    cout << "Enter number of nodes : "; cin >> Node;
    cout << "Enter number of edges : "; cin >> Edge ;

    graph = vector<vector<int>> (Node+1, vector<int>()) ;
    
    cout << "Enter edges (example = a b) : " << endl ;
    
    for(int i = 0 ; i < Edge ; i++){
        int u , v;
        cin >> u >> v;
        graph[u].emplace_back(v) ;
        graph[v].emplace_back(u) ;
    }

    int start_node = 1;
    cout << "Enter Starting node : "; cin >> start_node ;
    cout << endl ;

    for(int depth = 0 ; depth < Node ; depth++){
        cout << "When Depth Limit is " << depth << "," << endl ;
        vis = vector<int> (Node+1) ;
        dfs(start_node,start_node,depth) ;
        cout << endl ;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    solve();
    return 0 ;
}