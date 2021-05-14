#include<bits/stdc++.h>
using namespace std ;
 
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ,m ; 
cin>>n>>m ; 
multiset<int> prices ; 
for(int i = 0 ; i<n ; i++ ){
    int x ; 
    cin>>x;
    prices.insert(x);
}
for(int i = 0 ; i<m ; i ++){
    int y ; 
    cin>>y ;  
    auto it = prices.upper_bound(y) ; 
    if(it==prices.begin()){
        cout<<"-1\n" ; 
    }else{
        it-- ; 
        cout<<*it<<endl ; 
        prices.erase(it) ; 
    }
}
return 0; 
}