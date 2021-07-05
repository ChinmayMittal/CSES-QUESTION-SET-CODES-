#include<bits/stdc++.h>
using namespace std ;

int main(){
 ios_base::sync_with_stdio(false); 
 cin.tie(NULL);
 int n , m , q ; 
 cin >> n >> m >> q ; 
 vector<vector<long long int>>distances(n+1 , vector<long long int>(n+1 , 10e16 )) ; 
 for( int i = 1 ; i<=n ; i++ ){
     distances[i][i] = 0 ; 
 }
 for( int i = 1 ; i<=m  ; i++ ){
     long long int x , y , d ; 
     cin >> x >> y >> d ;  
     distances[x][y] = distances[y][x]= min(d , distances[x][y] )  ; 
 }

 for( int i =1 ; i<=n ; i++ ){
     for( int r = 1 ; r<=n ; r++ ){
        for( int c = 1 ; c<=n ; c++ ){
            if(r!=i and c!=i) distances[r][c] = min(distances[r][c] , distances[r][i] + distances[i][c]) ; 
        }
    }
 }

 while(q--){
     int x , y ; 
     cin >> x >> y ; 
     cout << ((distances[x][y]!=10e16)?distances[x][y] : -1) << "\n";
}
return 0;
}