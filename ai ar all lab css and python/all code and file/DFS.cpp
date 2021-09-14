#include<bits/stdc++.h>
using namespace std;
int cost[100000];
int main()
{
    int n,m,src;
    cin>>n>>m>>src;
    vector <int> vec[n+10];
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    stack <int> s;
    s.push(src);
    cost[src]=1;
    int d[n+10],f[n+10],num=1;
    d[src]=num;
    while(!s.empty())
    {
        int top=s.top();
        cout<<top<<endl;
        int sz=vec[top].size();
        int c=0;
        for(int i=0; i<sz; i++)
        {
            if(cost[vec[top][i]]==0)
            {
                s.push(vec[top][i]);
                ++cost[vec[top][i]];
                d[vec[top][i]]=++num;
                break;
            }
            else
                c++;
        }
        if(sz==c)
        {
            f[s.top()]=++num;
            s.pop();
        }
    }
    for(int i=1;i<=n;++i)
    {
        cout<<d[i]<<" "<<f[i]<<endl;
    }
}
