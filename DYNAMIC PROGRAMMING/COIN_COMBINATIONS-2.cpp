#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n,x;
cin>>n>>x;
int dp[n+1][x+1];
dp[0][0] = 1 ; 
for(int i = 1 ; i<=x ; i++){
    dp[0][i] = 0 ; 
}
for(int i =1 ; i<= n ;i++){
    int current_coin ;
    cin>>current_coin ;
    for(int j = 0 ; j<=x ; j++){
        if(j==0){
            dp[i][j]=1;
        }else{
            dp[i][j] = dp[i-1][j] ; 
            if(current_coin<=j){
                dp[i][j]=(0ll+dp[i][j-current_coin]+dp[i][j])%1000000007;
            }
        }
    }
}
cout<<dp[n][x];
return 0;
}
