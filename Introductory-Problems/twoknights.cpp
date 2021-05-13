#include<bits/stdc++.h>
#define ll long long 
using namespace std ;
long long int a[10001] ; 
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
 ll n ;
 cin>>n ; 
for(ll i = 1 ; i<=n ; i++){
 ll ans = 0 ; 
 ans += ((i*i)*(i*i-1))/2 ; 
 ans -= 4*(i-1)*(i-2) ; 
 cout<<ans<<endl ; 

}
return 0;
}