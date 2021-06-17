#include<bits/stdc++.h>
using namespace std ;
void calc_parent( vector<vector<int>>&tree , int cur , int parent , vector<vector<int>>&up ){
    up[cur][0] = parent ; 
    for(auto ele : tree[cur] ) { 
        if(ele!=parent ) {
            calc_parent( tree , ele , cur , up ) ;
        }
    }
    return ; 
}
int main(){ 
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n  , q ;
cin>>n >> q  ;  
vector<vector<int>>tree(n+1) ; 
vector<vector<int>>up(n+1 , vector<int>(21 , 0 )) ; 
for(int i = 2 ; i<=n ; i++){
    int x ; 
    cin >> x ; 
    tree[x].push_back(i) ; 
    tree[i].push_back(x) ; 
}
calc_parent(tree , 1 , 0 , up ) ; 
for(int j = 1 ; j<=20 ; j ++ ){
for( int i = 1 ; i<=n ; i ++ ){
    up[i][j] = up[up[i][j-1]][j-1] ; 
 }
}
while(q--){
    int x , k ; 
    cin >> x >> k ; 
    int cur = x ; 
    for( int i = 0 ; i <=20 ; i ++ ){
        if(((1<<i)&k)>0){
            cur = up[cur][i] ; 
        }
    }
    if(cur==0 ){
        cout <<"-1\n" ; 
    }else{
        cout << cur <<endl ; 
    }

}
return 0 ; 
}