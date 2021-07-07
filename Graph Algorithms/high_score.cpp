#include<bits/stdc++.h>
using namespace std ;
const long long int INF  = 10e18 ; 
const long long int NINF = -INF ; 
int n , m ; 
struct edge{
    int a ;
    int b ; 
    int len ; 
}; 
long long int  bellman_ford ( vector<edge> &edges , vector< long long int >&dist  ){
for( int i = 0 ; i<n-1 ; i ++ ) { 
    for( auto edge : edges ){
        if(dist[edge.a]!=INF and dist[edge.b] > dist[edge.a] + edge.len ){
            dist[edge.b] =  dist[edge.a] + edge.len ;  
        }
    }
}
    // checking for negative cycle 
    bool negative_cycle = false ; 

      for( auto edge : edges ){
        if(dist[edge.a]!=INF and dist[edge.b] > dist[edge.a] + edge.len ){
            dist[edge.b] =  NINF ;  
            negative_cycle = true ; 
            break ; 
        }
}

    if( negative_cycle ){
        for( int i = 1 ; i<=n-1 ; i ++ ){
            for( auto edge : edges ){
                if(dist[edge.a]==NINF ) {
                    dist[edge.b] = NINF ; 
                }
            }
        }
    }

    if(dist[n]==NINF) return -1 ;
    else return -dist[n] ; 

}

int main(){
 ios_base::sync_with_stdio(false); 
 cin.tie(NULL);
 #ifndef ONLINE_JUDGE
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 #endif

cin >> n >> m ; 
vector<edge> edges ; 
vector< long long int > dist ( n+1 , INF ) ; 
dist[1] = 0 ; 
for( int i = 0 ; i<m ; i++ ){
    long long int a , b , c ; 
    cin >> a >> b >> c ; 
    struct edge e ; 
    e.a = a ; 
    e.b = b ; 
    e.len = -c  ; 
    edges.push_back(e) ; 
}
cout <<  bellman_ford( edges , dist ) ; 
return 0; 
}