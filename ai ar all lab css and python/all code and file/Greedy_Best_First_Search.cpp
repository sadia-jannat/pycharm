#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;


class GreedyBestFirstSearch{
  
    vector<vector<pi> > graph;

    void addedge(int x, int y, int cost)
    {
        graph[x].push_back(make_pair(cost, y));
        graph[y].push_back(make_pair(cost, x));
    }
    
    void best_first_search(int source, int target, int n)
    {
        vector<bool> visited(n, false);
        priority_queue<pi, vector<pi>, greater<pi> > pq;

        pq.push(make_pair(0, source));
        int s = source;
        visited[s] = true;
        while (!pq.empty()) {
            int x = pq.top().second;
            cout << x << " ";
            pq.pop();
            if (x == target)
                break;
    
            for (int i = 0; i < graph[x].size(); i++) {
                if (!visited[graph[x][i].second]) {
                    visited[graph[x][i].second] = true;
                    pq.push(make_pair(graph[x][i].first,graph[x][i].second));
                }
            }
        }
    }
    public:                 
    void solve(){
        int node,edge ;
        cout << "Enter the number of nodes : "; cin >> node ;
        cout << "Enter the number of edges : "; cin >> edge ;
        graph.resize(node+1) ;
        cout << "Enter the edges and the cost of that edge ( Example : u v cost ) : " << endl ;
        for(int i = 0 ; i < edge ; i++){
            int u , v , cost ;
            cin >> u >> v >> cost ;
            addedge(u,v,cost) ;
        }
        int startingNode , target;
        cout << "Enter the starting Node : " ; cin >> startingNode ;
        cout << "Enter the target Node : " ; cin >> target ;

        cout << endl << "Desired Path : ";
        best_first_search(startingNode, target, node+1);

    }
};
  
int main()
{

    GreedyBestFirstSearch GBFS;
    GBFS.solve() ;  
    return 0;
}