class DisjointSet{
    vector<int>rank,parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    
    int findUPar(int node){
        if(node== parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    
    void unionByRank(int u, int v){
       u=findUPar(u);
       v=findUPar(v);
       if(u==v){
           return;
       }
       if(rank[u]<rank[v]){
           parent[u]=v;
       } 
       else if(rank[v]<rank[u]){
           parent[v]=u;
       } 
       else{
           parent[v]=u;
           rank[u]++;
       } 
    }
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool>result(queries.size(), false);
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }

        sort(edgeList.begin(), edgeList.end(), [](auto &l1, auto &l2){ return l1[2]<l2[2];});
        sort(queries.begin(), queries.end(), [](auto &l1, auto &l2){ return l1[2]<l2[2];});
        int i=0;
        DisjointSet ds(n);
        for(auto &it:queries){
           while(i<edgeList.size() && it[2]>edgeList[i][2]){
               ds.unionByRank(edgeList[i][0], edgeList[i][1]);
               i++;
           }
           if(ds.findUPar(it[0])==ds.findUPar(it[1])){
              result[it[3]]=true;
           }
        }
        return result;
    }
};
