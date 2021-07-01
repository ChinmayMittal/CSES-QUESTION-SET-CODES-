#include<bits/stdc++.h>
#define mod 1000000007 
#define ll long long 
using namespace std ;
long long int dp[1001][1<<11] ; 
int n , m ; 
void generate_next_mask(int j ,  int current_mask , int cur_tile , vector<int>&next_masks){
    if(cur_tile == n ){
        next_masks.push_back(current_mask) ; 
        return ; 
    }
    if( j&(1<<cur_tile)){
        generate_next_mask( j , current_mask , cur_tile+1 , next_masks ) ; 
    }else{
        generate_next_mask( j , current_mask | (1<<cur_tile)  , cur_tile+1 , next_masks ) ;
        if( cur_tile <=n-2 and !(j&(1<<(cur_tile+1)))){
            generate_next_mask( j , current_mask , cur_tile+2 , next_masks) ; 
        } 
    } 
}
void solve(){

    for( int i = 2 ; i<=m ; i++){
        for( int j = 0 ; j<(1<<n) ; j++ ){

            // for( int k = 0 ; k<10 ; k++){
            //     if(j&(1<<k)){
            //         mask =( mask ^ (1<<k) ) ; 
            //     }
            // } 
            long long int ans = 0 ; 
            vector<int>next_masks ; 
            int current_mask = 0 ; 
            generate_next_mask( j , current_mask ,0 , next_masks ) ; 
            for( auto next_mask : next_masks ){
                ans = (ans+dp[i-1][next_mask])%mod ; 
            }
            dp[i][j] = ans%mod ; 

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
 cin >> n >> m ; 
 if( n>m ){
     swap(n,m) ; 
 }
 // n always contains the smaller values 
 for( int i = 0 ; i<=1000 ; i++){
     for( int j = 0 ; j<(1<<10) ; j++){
         dp[i][j] = -1 ; 
     }
 }
 for( int j = 0 ; j<(1<<n) ; j++ ){
     int zeroes = 0 ; 
     for( int i = 0 ; i<n ; i++){
         if(j&(1<<i)){
             if(zeroes%2==0){
                 zeroes = 0 ; 
                 continue ; 
             }else{
                 dp[1][j] = 0 ; 
                 break ; 
             }
         }else{
             zeroes ++ ; 
         }
     }
     if(dp[1][j]==-1){
         if(zeroes%2==0){
             dp[1][j] = 1 ; 
         }else{
             dp[1][j] = 0 ; 
         }
     }
 }
 solve() ; 
//  cout << dp[1][1] <<" " <<dp[1][0]; 
 cout << dp[m][0] ; 
return 0;
}