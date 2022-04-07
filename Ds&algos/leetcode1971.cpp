class Solution {
public:
    
    bool dfs(int n,bool is_visited[n],vector<vector<int>>& adj,int source, int destination){
   
        if(source == destination){
            return true;
        }
        if(is_visited[source]){
            return false;
        }
        is_visited[source] = 1;
        for(auto node : adj[source]){
            if (dfs(n,is_visited,adj,node, destination)) return true;
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination){
        bool is_visited[n];
        memset(is_visited,0,sizeof(is_visited));
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        if (dfs(n,is_visited,adj,source,destination)){
            return true;
        }
        else{
            return false; 
        }
    }
};