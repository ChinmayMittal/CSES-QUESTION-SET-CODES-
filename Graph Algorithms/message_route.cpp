#include<bits/stdc++.h>
using namespace std ;
void bfs(vector<vector<int>>&map , int src , int dis[] , int parent[]) {
    queue<int> q ; 
    parent[src] = -1 ; 
    q.push(src);
    dis[src] = 0 ; 
    while(!q.empty()){
        int cur = q.front() ; 
        q.pop() ; 
        for(auto nbr : map[cur]){
            if(dis[nbr]==INT_MAX){
                dis[nbr] = dis[cur] + 1 ; 
                q.push(nbr);
                parent[nbr] = cur ; 
            }
        }
    }
    return ; 
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ; 
cin>>n ; 
vector<vector<int>> map(n+1) ; 
int m ; 
cin>>m ; 
for(int i = 0 ; i<m ; i++){
    int x , y ; 
    cin>>x>>y ; 
    map[x].push_back(y) ;
    map[y].push_back(x) ;  
}
int dis[n+1] ;
for(int i =1 ; i<=n ; i++){
    dis[i] = INT_MAX ; 
}
int parent[n+1] ;  
bfs(map , 1 , dis , parent) ;
if(dis[n]==INT_MAX){
    cout<<"IMPOSSIBLE\n";
} else{
    cout<<dis[n]+1<<endl ;
    stack<int> s ; 
    int cur = n ; 
    while(cur!=-1){
        s.push(cur) ; 
        cur = parent[cur] ; 
    }
    while(!s.empty()){
        cout<<s.top()<<" " ; 
        s.pop() ; 
    }
}
return 0;
}