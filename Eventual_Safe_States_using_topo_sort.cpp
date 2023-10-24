/*
A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int>indeg(V,0);
        vector<vector<int>>adjrev(V);
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                adjrev[it].push_back(i);
                indeg[i]++;
            }
        }
        vector<int>res;
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        while(q.size()!=0)
        {
            int x=q.front();
            q.pop();
            res.push_back(x);
            for(auto it:adjrev[x])
            {
                indeg[it]--;
                if(indeg[it]==0)
                    q.push(it);
            }
        }
        sort(res.begin(),res.end());
        return res;
        
    }
};

int main()
{
    int v,e,x,y;
    cin >> v >> e;
    vector<int>adj[v];
    for(int i=0;i<e;i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    Solution s;
    vector<int>res=s.eventualSafeNodes(v,adj);
    for(int i=0;i<res.size();i++)
    {
        cout << res[i] << " " ;
    }
    return 0;
}