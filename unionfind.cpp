#include<bits/stdc++.h>
using namespace std;

void dsu(){
    int N;
    vector<int> parent(N);
    vector<int> size(N);
    void make_set(int v){
        parent[v]=v;
        size[v]=1;
    }
    int find_set(int v){
        if(v==parent[v]){
            return v;
        }
        return parent[v]=find_set(parent[v]);
    }
    void union_set(int a,int b){
        a=find_set(a);
        b=find_set(b);
        if(a!=b){
            if(size[a]<size[b]){
                swap(a,b);
            }
            parent[b]=a;
            sz[a]+=sz[b];
        }
    }
}
int main(){
    return 0;
}
