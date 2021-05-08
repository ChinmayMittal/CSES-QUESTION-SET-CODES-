#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n  ; 
cin>>n; 
int a[n] ;
int dp[n+1] ; 
for(int i = 0 ; i<n ; i ++){
    cin>>a[i] ; 
} 
dp[0] = INT_MIN ; 
for(int i = 1 ; i<=n ; i++){
    dp[i] = INT_MAX ; 
}
int ans = 0 ; 
for(int i = 0 ; i<n ; i ++){
    auto it = upper_bound(dp , dp+n  , a[i]) -dp ; 
    if(dp[it-1]<a[i]){ //if you don't include this if statement it will give longest non decreasing subsequence 
        dp[it] = a[i] ; 
        ans = max(ans , it) ; 
    }
}
cout<<ans; 

return 0;
}