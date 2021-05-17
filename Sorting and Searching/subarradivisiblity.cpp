#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ; 
cin>>n ; 
long long int pre = 0  ; 
map<int , int> m ; 
m[0] = 1 ; 
int x ; 
cin>>x ; 
m[(x%n+n)%n]++ ; 
pre+=x ;
pre  = (pre%n+n)%n ;  
for(int i = 1 ; i<n ; i++){
    cin>>x ; 
    pre = pre+ x ; 
    pre  = (pre%n+n)%n ;
    m[pre]++ ;
}
long long int cnt = 0 ; 
 for(auto p : m ){
    // cout<<p.first<<" "<<p.second<<endl ; 
     cnt += 1ll*p.second*(p.second-1)/2 ; 
 }
 cout<<cnt<<endl ; 
return 0;
}