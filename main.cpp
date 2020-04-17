/*
step:1

stack STACK
void DFS(int source) {
    visited[s]=true
    for all neighbours X of source that are not visited:
        DFS(X)
    STACK.push(source)
}

step: 2

CLEAR ADJACENCY_LIST
for all edges e:
    first = one end point of e
    second = other end point of e
    ADJACENCY_LIST[second].push(first)


       step :3
while STACK is not empty:
    source = STACK.top()
    STACK.pop()
    if source is visited :
        continue
    else :
        DFS(source)

*/


#include <bits/stdc++.h>
#define MAX 10

using namespace std;

vector<int> g[MAX];
vector<int> gr[MAX];
stack<int> order;

int visited[MAX];


void dfs1 (int v)
{
    visited[v] =1;
    for (int i=0; i<g[v].size(); i++)
    {
        int k=g[v][i];
        if(visited[k]==0)
        {
            dfs1(k);
        }

    }
    order.push(v);
}

void dfs2(int v)
{
    cout<<v<<" ";

    visited[v] =1;

    for (int i=0; i<gr[v].size(); i++)
    {
        int l=gr[v][i];
        if(visited[l]==0)
        {
            dfs2(l);
        }
    }

}

int main()
{
    int n,e,a,b;
    cout<<"Enter the number of node:";
    cin>>n;
    cout<<"Enter the number of edge:";
    cin>>e;
    cout<<endl<<"Enter the input like(a--->b):"<<endl;
    for (int i=0; i<e; i++)
    {
        cin>>a>>b;
        g[a].push_back (b); // take input main grap
        gr[b].push_back (a);  //take input reverse grap
    }

    // visited array make all element 00
    for(int i=0; i<n; i++)
    {
        visited[i]=0;
    }
    for (int i=0; i<n; i++)
    {
        if (visited[i]==0)
        {
            dfs1 (i);
        }
    }


    //For DFS 2 again element make 00
    for(int i=0; i<n; i++)
    {
        visited[i]=0;
    }

    cout<<endl<<"Strongly connected component are:"<<endl;
    while (!order.empty())
    {
        int v = order.top();
        order.pop();
        if (visited[v]==0)
        {
            dfs2(v);
            cout<<endl;
        }
    }
    return 0;
}
