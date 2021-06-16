#include<bits/stdc++.h>
using namespace std ;
int calc_distances(vector<vector<int>>&tree , int parent , int cur , int distances[]){
    if(tree[cur].size()==1 and tree[cur][0]==parent ) {
        distances[cur] = 0 ; 
        return 0 ; 
    }
    int ans = 0 ; 
    for(auto ele : tree[cur] ){
        if(ele!=parent){
            ans = max( ans ,calc_distances(tree , cur , ele , distances)  +1 ) ; 
        }
    }
    return distances[cur] = ans ; 
}
void dfs( vector<vector<int>>&tree , int cur , int parent , int distances[] , int ans[] , int parent_dist ) {
    ans[cur] = max(parent_dist , distances[cur] )  ; 
    multiset<pair<int,int>> temp ; 
    for(auto ele : tree[cur]){
        if(ele !=parent ) temp.insert({  distances[ele ] , ele } ) ;  
    } 
    for(auto ele : tree[cur] ) {
        if(ele!=parent ){
            temp.erase({  distances[ele]  , ele } ) ;
            int temp_dis = parent_dist + 1 ; 
            if(!temp.empty()) temp_dis = max(temp_dis , (*prev(temp.end())).first + 2 ) ; 
            dfs( tree , ele , cur , distances , ans, temp_dis ) ; 
            temp.insert( {distances[ele] , ele })  ;   
        }
    }

    return ; 
    
 
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ;
cin>>n ; 
vector<vector<int>>tree(n+1) ; 
for(int i = 0 ; i<n-1 ; i++){
    int x , y ; 
    cin>>x>>y ; 
    tree[x].push_back(y) ; 
    tree[y].push_back(x) ; 
}
int distances [n+1] = {0}  ;
calc_distances( tree , 0 , 1 , distances ) ;  
int ans[n+1] = {0} ; 
dfs( tree , 1 , 0 , distances , ans , 0 ) ; 
for( int i = 1 ; i<=n ; i ++ ){
    cout << ans[i] << " " ; 
}
return 0;
}