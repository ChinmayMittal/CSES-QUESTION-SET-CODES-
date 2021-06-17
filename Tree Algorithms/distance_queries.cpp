#include<bits/stdc++.h>
using namespace std ;
vector<int>depth(200000+1 , 0 ) ; 
void calc_parent( vector<vector<int>>&tree , int cur , int parent , vector<vector<int>>&up , int d ){
    depth[cur] = d ; 
    up[cur][0] = parent ; 
    for(auto ele : tree[cur] ) { 
        if(ele!=parent ) {
            calc_parent( tree , ele , cur , up  , d+1 ) ;
        }
    }
    return ; 
}
int lca ( int a , int b , vector<vector<int>>&up) {
    if(depth[a] < depth[b] ) {
        swap(a,b) ; 
    }
    int k = depth[a] - depth[b] ; 
    for( int i = 0 ; i <=20 ; i ++ ){
        if(((1<<i)&k)>0){
            a = up[a][i] ; 
        }
    }
    if(a==b) return a ; 
    for( int j = 20 ; j >= 0  ; j -- ) {
        if(up[a][j]!=up[b][j]){
            a = up[a][j] ; 
            b = up[b][j] ; 
        }
    }

    return up[a][0] ; 

}
int main(){ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n  , q ;
cin>>n >> q  ;  
vector<vector<int>>tree(n+1) ; 
vector<vector<int>>up(n+1 , vector<int>(21 , 0 )) ; 
for(int i = 1 ; i<n ; i++){
    int x , y ; 
    cin >> x >> y; 
    tree[x].push_back(y) ; 
    tree[y].push_back(x) ; 
}
calc_parent(tree , 1 , 0 , up , 0  ) ; 
for(int j = 1 ; j<=20 ; j ++ ){
for( int i = 1 ; i<=n ; i ++ ){
    up[i][j] = up[up[i][j-1]][j-1] ; 
 }
}
// for( int i =1 ; i<=n ; i ++ ){
//     cout << depth[i] << endl ; 
// }
while(q--){
   int a , b ; 
   cin >> a >> b ; 
  int lca_ = lca(a , b , up ) ; 
  cout << depth[a] + depth[b] - 2 * depth[lca_] << "\n" ;    
}
return 0 ; 
}