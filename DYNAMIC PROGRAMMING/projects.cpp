#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ; 
cin>>n ; 
multiset<pair<pair<int,int> ,int> > m  ;
 for(int i = 1 ; i<= n ; i++){
     int a , b  , r ; 
     cin>>a>>b>>r ; 
     m.insert(make_pair(make_pair(b,a), r)) ; 
 }
 map<int , long long int> r  ;
 long long int maxans = 0 ; 
 for(auto p : m){
     long long int op1;
     int start = p.first.second ; 
    auto it =  r.lower_bound(start) ;
     if(it==r.begin()){
         op1 = 0 ; 
     } else{
         it-- ; 
         op1 = it->second ; 
     }
     op1+= p.second ; 
     r[p.first.first] = max(maxans , op1) ; 
     maxans = r[p.first.first];
 }
 cout<<maxans<<endl ; 
return 0;
}