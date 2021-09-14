#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int numVertices;
    list<int> *adjacencyList;

public:
    Graph(int numVertices);
    void addEdge(int v, int w);
    void BestFirstSearch(int start);
};

Graph::Graph(int numVertices)
{
    this->numVertices = numVertices;
    adjacencyList = new list<int>[numVertices];
}

void Graph::addEdge(int v, int w)
{
    adjacencyList[v].push_back(w);
}

void Graph::BestFirstSearch(int start)
{
    bool *visited = new bool[numVertices];
    for(int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
    }

    list<int> queue;

    visited[start] = true;
    queue.push_back(start);
    list<int>::iterator i;

    while(!queue.empty())
    {
        start = queue.front();
        cout << start << " " << '\n';
        queue.pop_front();

        for(i = adjacencyList[start].begin(); i != adjacencyList[start].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
int main()
{

    int x, y, lines,vertex,edge;
    float distance;
    cout<<"Enter vertex and edges : ";
    cin>>vertex>>edge;
    Graph g(vertex);
    cout<<"Enter vertex numbered from 0 to vertex-1 "<<endl;
    while(edge--)
      {
          cin>>x>>y;
          g.addEdge(x, y);
      }
    g.BestFirstSearch(0);
    return 0;
}
