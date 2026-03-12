class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    bool unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;
        if(rank[a]<rank[b]) swap(a,b);
        parent[b]=a;
        if(rank[a]==rank[b]) rank[a]++;
        return true;
    }
};
class Solution {
public:
    bool possible(int n, vector<vector<int>>& edges, int k, int mid){
        DSU dsu(n);
        int upgrades=0;
        int used=0;
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int s=e[2];
            int must=e[3];
            if(must){
                if(s<mid) return false;
                if(dsu.unite(u,v)) used++;
                else return false;
            }
        }
        sort(edges.begin(), edges.end(), [](auto &a, auto &b){
    return a[2] > b[2];
});
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int s=e[2];
            int must=e[3];
            if(must) continue;
            if(dsu.find(u)==dsu.find(v)) continue;
            if(s>=mid){
                dsu.unite(u,v);
                used++;
            } else if(s*2>=mid && upgrades<k){
                upgrades++;
                dsu.unite(u,v);
                used++;
            }
            if(used==n-1) return true;
        }
        return used==n-1;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int low=0;
        int high=200000;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(n,edges,k,mid)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};