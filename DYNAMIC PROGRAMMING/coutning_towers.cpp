#include<bits/stdc++.h>
#define mod 1000000007 
#define ll long long 
using namespace std ;
long long int dp[10000001][2] ; 
void solve(){

    dp[1][0] = 1 ; 
    dp[1][1] = 1 ; 
    for( ll i=2 ; i<=1000000 ; i ++ ){
        dp[i][0] =( dp[i-1][1] + dp[i-1][0]*2 )%mod ;
        dp[i][1] = (dp[i-1][1]*4 + dp[i-1][0])%mod ;  
    }
}
int main(){
 #ifndef ONLINE_JUDGE
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 #endif
 ios_base::sync_with_stdio(false); 
 cin.tie(NULL);
 int t ; 
 cin >>t ; 
 solve() ; 
 while(t--){
     int n ; 
     cin >> n ; 
     cout << (dp[n][0] + dp[n][1])%mod << "\n" ;  
 }
return 0;
}