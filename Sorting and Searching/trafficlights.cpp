#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int x , n ; 
cin>>x>>n ; 
set<int> pos ; 
pos.insert(0) ; 
pos.insert(x) ; 
multiset<int>  len ; 
len.insert(x) ; 
for(int i = 0 ; i< n ; i++){
    int p ; 
    cin>>p ; 
    auto it = pos.upper_bound(p);
    len.insert(*it-p) ; 
    int diff = *it ; 
    it-- ; 
    diff-= *it ; 
    len.insert(p-*it);
    pos.insert(p);
    auto remove = len.find(diff) ;
    len.erase(remove) ;  
    auto ans = len.end() ; 
    ans -- ; 
    cout<<*ans<<endl ; 
}
return 0;
}