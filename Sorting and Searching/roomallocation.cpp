#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ; 
cin>>n  ; 
vector<pair<pair<int,int> ,pair<int,int>>> v;
for(int i = 0 ; i<n ;i++){
    int a , b; 
    cin>>a>>b ; 
    v.push_back({{a , i},{b,-1}}) ; 
    v.push_back({{b , i},{a,1}}) ; 
}
sort(v.begin() , v.end());
int rooms_count =1 ; 
int roomsav = 1 ;
int lastend=-1 ; 
set<pair<int,int>> s ; 
vector<int> ans(n) ; 
s.insert( {0,1}) ; 
for(auto p : v){
    //cout<<p.first.first<<" "<<p.first.second<<" "<<p.second.first<<" "<<p.second.second<<endl ; 
    if(p.second.second==1){
        lastend = p.first.first ; 
        roomsav++ ; 
    }else{
        if(roomsav==0 ){
            rooms_count++ ; 
            s.insert(make_pair(p.second.first, rooms_count)) ; 
            ans[p.first.second] = rooms_count ; 
        }else if(s.begin()->first==p.first.first){
             rooms_count++ ; 
            s.insert(make_pair(p.second.first, rooms_count)) ; 
            ans[p.first.second] = rooms_count ; 
            }else{
            roomsav-- ; 
            ans[p.first.second]= (s.begin()->second) ; 
            auto it = s.begin() ; 
            s.erase(it) ; 
            s.insert({p.second.first , ans[p.first.second]});
        }
    }
} 
cout<<rooms_count<<endl ; 
for(auto t : ans){
    cout<<t<<" "; 
}

return 0;
}