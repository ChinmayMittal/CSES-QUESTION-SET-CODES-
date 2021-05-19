#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ,q ;
cin>>n>>q  ; 
int a[n+1] ;
a[0] = 0 ; 
for(int i = 1 ; i<=n ; i++){
    int x ;
    cin>>x ; 
    a[i] = a[i-1]^x ; 
  //  cout<<a[i]<<" " ; 
} 
//cout<<endl ; 
for(int i = 1 ;i<=q ;i++)
{
    int x ,y; 
    cin>>x>>y ; 
    cout<<(a[y]^a[x-1])<<endl ; 
}

return 0;
}