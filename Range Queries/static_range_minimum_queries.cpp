#include<bits/stdc++.h>
using namespace std ;

int main(){
 #ifndef ONLINE_JUDGE
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 #endif
 ios_base::sync_with_stdio(false); 
 cin.tie(NULL);
 int n , q ;
 cin >> n >> q; 
 vector<int>arr(n) ; 
 vector<vector<int>>sparse_table( n , vector<int>( 19 , 0)) ; 
 for( int i = 0 ; i< n ; i ++ ){
    cin >> arr[i] ; 
    sparse_table[i][0] = arr[i] ; 
 } 

 for( int j = 1 ; j<=18 ; j++ ){
    for( int i = 0 ; i+(1<<j) <=n ; i++ ){
         sparse_table[i][j] = min(sparse_table[i][j-1] , sparse_table[(i+(1<<(j-1))) ][j-1]) ; 
     }
 }


while(q--){

    long long int a , b ; 
    cin >> a >> b ; 
    a-- ; 
    b-- ; 
    int j = -1 ;
    while(a+(1<<(j+1)) <=b+1 ) {
        j++ ; 
    }

    cout << min( sparse_table[a][j] , sparse_table[b-(1<<j)+1][j] ) << "\n" ;  
}

 
return 0;
}