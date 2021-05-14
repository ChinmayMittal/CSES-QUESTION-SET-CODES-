#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ; 
cin>>n ; 
vector<pair<int , int >> v  ;
while(n--){
    int a , b ; 
    cin>>a>>b ; 
    v.push_back({a,1});
    v.push_back({b,-1}) ; 
}
sort(v.begin() , v.end()); 
 int cnt = 0 ; 
 int maxcnt = 0 ; 
 for(int i = 0 ; i<v.size() ; ){
     int j= i ;  
     while(j<v.size() and v[j].first==v[i].first){
         if(v[j].second==1){
             cnt++;
         }else{
             cnt --; 
         }
         j++ ; 
     }
     i = j ; 
     maxcnt = max(cnt , maxcnt) ; 
 }
 cout<<maxcnt ; 
return 0;
}