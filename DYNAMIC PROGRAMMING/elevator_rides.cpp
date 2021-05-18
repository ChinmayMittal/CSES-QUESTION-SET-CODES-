#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n,x; 
cin>>n>>x ; 
int weight[n] ; 
for(int i = 0 ; i<n ; i++){
    cin>>weight[i] ; 
}
//pg 103-04 cp handbook 
pair<int , int > dp[1<<n] ; 
dp[0] = make_pair(1 , 0 ) ;
for(int i = 1 ; i<(1<<n) ; i++){
    dp[i] = make_pair(INT_MAX,0);
    for(int j = 0 ; j<n ; j++){
        if((1<<j)&i){
             auto sub = dp[(1<<j)^i] ; 
             if(sub.second+weight[j]<=x){
                 sub.second+=weight[j] ; 
             }else{
                 sub.first++ ; 
                 sub.second = weight[j];
             }
              dp[i] = min(sub , dp[i]) ;
        }
    }
} 
cout<<dp[(1<<n)-1].first ; 
return 0;
}