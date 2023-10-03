
class Solution
{
	public:
	stack<int> st;
	void dfs(int n, vector<int> adj[],vector<int>& vis, int node){
	    vis[node] = 1;
	    for(auto i: adj[node]){
	        if(!vis[i]){
	            dfs(n,adj,vis,i);
	        }
	    }
        st.push(node);
	}
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    vector<int> vis(n,0);
	    for(int i = 0;i<n;++i){
	        if(!vis[i]){
	            dfs(n,adj,vis,i);
	        }
	    }
	    int i = 0;
	    while(!st.empty()){
	        vis[i++] = st.top();
	        st.pop();
	    }
	    return vis;
	}
};
