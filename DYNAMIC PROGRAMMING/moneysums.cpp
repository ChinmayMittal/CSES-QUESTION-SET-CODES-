#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ; 
cin>>n ; 
int a[n+1] ;
int sum =0 ;  
 for(int i = 1 ; i<= n ; i++){
     cin>>a[i] ; 
     sum+=a[i] ; 
 }
 bool dpprev[100001] ; 
  bool dp[100001] ; 
  dpprev[0] = true ; 
  for(int i = 1 ; i<=sum; i++){
      dpprev[i] = false ; 
   }
   for(int i = 1 ; i<= n ; i++){
       for(int j = 0 ; j<=sum; j++){
           if(dpprev[j]!=true){
               if(a[i]<=j){
                   dp[j] = dpprev[j-a[i]] ; 
               }
           }else{
               dp[j] = true ; 
           }
       }
       for(int k = 0 ; k<=sum ; k++){
           dpprev[k]=dp[k];
       }
   }
   int cnt= 0 ; 
   for(int j =1 ; j<=sum ; j++){
       if(dp[j]==true){
           cnt++ ; 
       }
   }
   cout<<cnt<<endl ; 
   for(int i = 1 ; i<=sum; i++){
       if(dp[i]){
           cout<<i<<" " ; 
       }
   }
return 0;
}