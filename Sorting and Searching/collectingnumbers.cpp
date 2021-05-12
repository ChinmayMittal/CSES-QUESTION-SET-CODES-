#include<bits/stdc++.h>
using namespace std ;
int a[200000] ;  
int found[200001] ; 
// int is_it_before_the_next[200001] ; 

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ; 
cin>>n ; 
 for(int i = 0 ; i<n ; i++){
     cin>>a[i] ; 
 }
 int cnt = 0 ; 
 for(int i = 0 ; i<n ; i++){
     found[a[i]] = true ; 
     if(a[i]!=1 and found[a[i]-1] == true){
          continue ; 
     }else{
         cnt ++ ; 
     }
 }
 cout<<cnt<<endl ; 

return 0;
}
