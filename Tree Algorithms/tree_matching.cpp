#include<bits/stdc++.h>
using namespace std ;
pair<int,int> total_matching( int cur , int parent , vector<vector<int>>&tree){
    if(tree[cur].size()==1 and parent!=-1){
        return make_pair(0 , 0 ) ; 
    }
    vector<pair<int , int>> sub_ans ;
    for(auto nbr : tree[cur]){
        if(nbr!=parent){
            sub_ans.push_back(total_matching(nbr , cur , tree));
        }
    } 
    pair<int,int> ans ; 
    ans.first = ans.second = 0 ; 
    bool not_include_greater = false ;
    int min_diff = INT_MAX ; 
    int min_include = INT_MAX ; 
    for(auto p : sub_ans){
        ans.second += max(p.first , p.second) ; 
        min_include = min(min_include , p.first) ;
        if(p.second>=p.first){
            not_include_greater = true ; 
        } 
        min_diff = min(p.first-p.second , min_diff) ; 
    }
    if(not_include_greater) ans.first = ans.second+1 ;
     else ans.first = ans.second - min_diff+1 ; 
     return ans ; 


}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ; 
cin>>n ; 
vector<vector<int>>tree(n+1) ; 
for(int i = 0 ;i<n-1 ; i++){
    int a ,b ; 
    cin>>a>>b ; 
    tree[a].push_back(b) ;
    tree[b].push_back(a) ;  
}
pair<int ,int> ans = total_matching(1 , -1 ,tree) ;
cout<<max(ans.first, ans.second) ;  
return 0;
}