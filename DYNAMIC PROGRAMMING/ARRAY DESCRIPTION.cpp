#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n , m ;
cin>>n>>m ; 
int dp[n+1][m+1];
int a[n] ; 
for(int i = 0 ; i<n ; i ++){
    cin>>a[i] ; 
    if(a[i]!=0){
        for(int j = 1 ;j<=m ; j++){
             if(j!=a[i])dp[i+1][j] = 0 ; 
             else dp[i+1][j]=1;
        }
    }
}
if(a[0]==0){
    for(int j=1 ; j<=m ;j++){
        dp[1][j] = 1 ; 
    }
}
for(int i =2 ; i<= n ; i++){
    if(a[i-1]==0){
        for(int j = 1 ; j<=m ; j++){
            dp[i][j]=0 ; 
            for(int k = max(j-1 , 1) ; k<=min(m,j+1) ; k++){
                dp[i][j] = (0ll+dp[i][j]+dp[i-1][k])%1000000007 ; 
            }
        }
    }else{
        dp[i][a[i-1]]=0 ; 
            for(int k = max(a[i-1]-1 , 1) ; k<=min(m,a[i-1]+1) ; k++){
                dp[i][a[i-1]] = (0ll+dp[i][a[i-1]]+dp[i-1][k])%1000000007 ; 
            }
    }
}
int ans = 0 ; 
for(int i = 1; i<= m ; i++){
    ans = (ans+dp[n][i]+0ll)%1000000007; 
}
cout<<ans; 
return 0;
}
