#include<bits/stdc++.h>
using namespace std ;
long long int dp[5000][5000];

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ; 
cin>>n;
int a[n] ; 

for(int i = 0 ; i<n ; i++){
    cin>>a[i] ; 
}
if(n%2==1){
    for(int i = 0 ; i<n ; i++){
        dp[i][i] = a[i] ; 
    }
    for(int j = 2 ; j<n; j+=2){
         for(int i = 0 ; i<=n-1-j ; i++ ){
             long long int op1 = a[i]+dp[i+2][i+j];
             long long int op2 = a[i]+dp[i+1][i+j-1];
             long long int op3 = a[i+j]+dp[i][i+j-2];
             long long int op4 = a[i+j]+dp[i+1][i+j-1];
             dp[i][i+j] = max(min(op1,op2),min(op3,op4)) ; 
         }
     }
  cout<<dp[0][n-1]<<endl ; 

}else if(n%2==0){
   
    for(int i = 0 ; i<n-1 ; i++){
        dp[i][i+1] = max(a[i],a[i+1]);
    }
     for(int j = 3 ; j<n; j+=2){
         for(int i = 0 ; i<=n-1-j ; i++ ){
             long long int op1 = a[i]+dp[i+2][i+j];
             long long int op2 = a[i]+dp[i+1][i+j-1];
             long long int op3 = a[i+j]+dp[i][i+j-2];
             long long int op4 = a[i+j]+dp[i+1][i+j-1];
             dp[i][i+j] = max(min(op1,op2),min(op3,op4)) ; 
         }
     }
     cout<<dp[0][n-1]<<endl ; 
  
}
// for(int i = 0 ; i<4 ; i++){
//     for(int j =0 ; j<4 ; j++){
//         cout<<dp[i][j]<<" ";
//     }
//     cout<<endl ;
// }

return 0;
}