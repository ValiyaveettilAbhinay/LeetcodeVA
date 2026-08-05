class Solution {
public:

    void dfs(vector<bool>&infected,int node,vector<int>&vis,vector<vector<int>>&adj){
        vis[node] = 1;
        infected[node] = true;

        for(auto &adjN : adj[node]){
            if(!vis[adjN]){
                dfs(infected,adjN,vis,adj);
            }
        }

        return;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<bool>infected(n,false);

        vector<vector<int>>adj(n);
        vector<int>vis(n,0);

        for(auto &invocation : invocations){
            int u = invocation[0],v= invocation[1];
            adj[u].push_back(v);
        }

        dfs(infected,k,vis,adj);
        vector<int>ans;

        bool canRemove = true;
        for(auto &invocation : invocations){
            int u = invocation[0],v = invocation[1];
            if(!infected[u] && infected[v]){
                canRemove = false;
                break;
            }
        }

        for(int i = 0;i<n;i++){
            if(!infected[i] || !canRemove){
                ans.push_back(i);
            }
        }

        return ans;
    }
};