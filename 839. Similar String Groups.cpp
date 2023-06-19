class DisjointSet{
private:
    vector<int>parent, rank;
public:
    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    
    int findUPar(int node){
        if(node==parent[node])return node;
        return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        u=findUPar(u);
        v=findUPar(v);
        if(u==v)return;
        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[v]<rank[u]){
            parent[v]=u;
        }
        else{
            parent[u]=v;
            rank[v]++;
        }
    }
};
class Solution {
private:
    bool similar(string &a, string &b){
        int n=a.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                cnt++;
            }
        }
        return cnt<=2;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(similar(strs[i], strs[j])){
                    // cout<<i<<" "<<j<<endl;
                    ds.unionByRank(i, j);
                }
            }
        }
        
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[ds.findUPar(i)]++;
            // cout<<ds.findUPar(i)<<endl;
        }
    
        return mp.size();
    }
};
