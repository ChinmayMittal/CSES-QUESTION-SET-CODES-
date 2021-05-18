#include<bits/stdc++.h>
using namespace std ;
void dijkstras(vector<vector<pair<int , int >>>&graph , int src ){
    int n = graph.size()-1 ;
    long long int dis[n+1] ; 
    for(int i = 1 ; i<=n ; i++){
        dis[i] = INT64_MAX ; 
    }
    dis[src] = 0 ; 
    set<pair<long long int , int > >s ; 
    s.insert({0 , src});
    while(!s.empty()){
        auto dis_fixed = *s.begin() ; 
        s.erase(s.begin()) ; 
        for(auto x : graph[dis_fixed.second]){
            if(dis[x.first]==INT64_MAX){
                dis[x.first] = dis[dis_fixed.second] + x.second ; 
                s.insert({dis[x.first] , x.first}) ;  
            }else if(dis[x.first]> dis[dis_fixed.second]+ x.second){
                auto it = s.find({dis[x.first] , x.first}) ; 
                if(it!=s.end()){
                    s.erase(it) ;
                }
                dis[x.first] =  dis[dis_fixed.second]+ x.second;
                s.insert({ dis[dis_fixed.second] + x.second  , x.first});
            }
        }
    }
    for(int i = 1 ; i<=n ; i++){
        cout<<dis[i]<<" " ; 
    }
    return ; 
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n , m ; 
cin>>n>>m ; 
vector<vector<pair<int , int >>> graph(n+1) ; 
for(int i = 0 ; i<m ; i++ ){
    int x , y ,d  ;
    cin>>x>>y>>d ; 
    graph[x].push_back({ y  , d }) ; 
}
dijkstras(graph , 1 ) ; 
return 0;
}