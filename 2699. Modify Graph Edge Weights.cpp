class Solution {
public:   
    auto dijkstra(vector<pair<int,int>>adj[], int N, int source, bool skip_negative){
        vector<int>dis(N, 2e9);
        dis[source]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        unordered_map<int,int>parent;    //{node, parent}
        pq.push({0, source});   //{wt, node}
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int wt=it.first;
            int node=it.second;

            for(auto it:adj[node]){
                int adjWt=it.second;
                int adjNode=it.first;
                if (adjWt==-1){
                    if(skip_negative){
                        continue;
                    }
                    adjWt=1;
                }
                
                if(wt+adjWt<dis[adjNode]){
                    dis[adjNode]=wt+adjWt;
                    parent[adjNode]=node;
                    pq.push({dis[adjNode], adjNode});
                }
            }
        }
        return make_pair(dis, parent);
    }
    
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<pair<int,int>>adj[n];
        for(auto it:edges){ 
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        auto [dis, parent]=dijkstra(adj, n, source, false);  //MinusOneToOne
        if(dis[destination]>target){
            return {};
        }
        
        auto [disR, parentR]=dijkstra(adj, n, destination, true);   //SkipMinusOne
        if(disR[source]<target){
            return {};
        }
                
        
        // for(auto it:dis){
        //     cout<<it<<" ";
        // }cout<<endl;
        vector<int>path={destination};
        while(path.back()!=source){
            path.push_back(parent[path.back()]);
        }
        reverse(path.begin(), path.end());
        
        map<pair<int, int>, int>mp_edges;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            mp_edges[{min(u,v ), max(u, v)}]=w;  
        }
        
        int walked=0;
        for(int i=0;i<path.size()-1;i++){
            int u=path[i];
            int v=path[i+1];
            pair<int,int>p={min(u,v ), max(u, v)};
            if(mp_edges[p]==-1){
                mp_edges[p]=max(target-disR[v]-walked , 1);
            }
            walked+=mp_edges[p];
        }
        
        for(auto &it: mp_edges){
            if(it.second==-1){
                it.second=2*(int)1e9;
                
            }
        }
        
        vector<vector<int>>ans;
        for(auto &it: mp_edges){
            int u=it.first.first;
            int v=it.first.second;
            int w=it.second;
            ans.push_back({u, v, w});
        }
        return ans;
        
    }
};
