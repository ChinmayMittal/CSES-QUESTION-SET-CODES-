#include<bits/stdc++.h>
using namespace std ;
void dijkstras( int src , vector< long long int >&dist ,  vector< vector< pair< int , int >> >&graph ){

    for( auto &ele : dist){
        ele = INT64_MAX ; 
    }
        dist[src] = 0 ; 
    set<pair<long long int, long long int>> s ;
    s.insert({0,src}) ; 

    while(!s.empty()){
        auto p = *(s.begin()) ; 
        int node = p.second ; 
        long long int par_dist = p.first ; 
        s.erase(s.begin()) ; 

        for( auto child : graph[node] ){
            if( par_dist + child.second < dist[child.first ] ){
                auto f = s.find({dist[child.first] , child.first } ) ; 
                if(f!=s.end()){
                    s.erase(f) ; 
                }
                    dist[child.first] = par_dist + child.second ; 
                    s.insert( { dist[child.first] , child.first}) ; 
            }
        }
    } 
}
int main(){
 #ifndef ONLINE_JUDGE
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 #endif
 ios_base::sync_with_stdio(false); 
 cin.tie(NULL);
 int n , m ; 
 cin >> n >> m ; 
 vector< vector< pair< int , int >> > graph(n+1) ; 
 vector< vector< pair< int , int >> > graph_reverse(n+1) ;
 vector< vector<long long int>> edges( m , vector< long long int>(3,0)) ;    
 for( int i = 0 ; i<m ; i ++ ){
     int a , b , c ; 
     cin >> a >> b >> c ; 
     graph[a].push_back({ b , c} ) ; 
     graph_reverse[b].push_back({ a , c } ) ; 
    edges[i][0] = a ; 
    edges[i][1] = b ; 
    edges[i][2] = c ; 
 }

 vector< long long int >source(n+1) ; 
 vector< long long int >dest(n+1) ;
 dijkstras( 1 , source , graph ) ;  
 dijkstras( n , dest , graph_reverse ) ; 

 long long int ans = INT64_MAX ; 

 for( auto edge : edges ) {
     if( source[edge[0]]!=INT64_MAX and dest[edge[1]]!=INT64_MAX){
         ans = min( ans , edge[2]/2 + dest[edge[1]] + source[edge[0]] ) ; 
     }
 } 
cout << ans << endl ; 
return 0;
}