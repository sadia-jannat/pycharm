#include<bits/stdc++.h>
using namespace std;
vector<int> vec[1005];
void bfs(int src,int cost[])
{
    cost[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        int sz=vec[top].size();
        for(int i=0; i<sz; i++)
        {
            int num=vec[top][i];
            if(cost[num]==-1)
            {
                q.push(num);
                cost[num]=cost[top]+1;
            }
        }
    }
}
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n,m;
        cin>>n>>m;
        int cost[n+5];
        memset(cost,-1,sizeof(cost));
        for(int i=0; i<m; i++)
        {
            int u,v;
            cin>>u>>v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        int src;
        cin>>src;
        bfs(src,cost);
//        for(int i=1;i<=n;i++)
//        {
//            int sz=vec[i].size();
//            for(int j=0;j<sz;j++)
//                cout<<vec[i][j]<<" ";
//            cout<<endl;
//        }
        for(int i=1; i<=n; i++)
        {
            if(i!=src)
            {
                if(cost[i]==-1)
                    cout<<"-1 ";
                else
                    cout<<cost[i]*6<<" ";
            }
            vec[i].clear();
        }
         cout<<endl;
    }
}
