#include<bits/stdc++.h>
using namespace std ;
int dfs( int parent , int subordinate[] , vector<vector<int>>&children ){
    if(children[parent].size()==0){
        subordinate[parent] = 0 ; 
        return 1 ; 
    }
    for(auto child : children[parent]){
        subordinate[parent] += dfs(child , subordinate , children) ; 
    }

    return subordinate[parent] +1; 

}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ; 
cin>>n ; 
vector<vector<int>>children(n+1) ; 
for(int i =2 ; i<=n ; i++){
    int x ;
    cin>>x ; 
    children[x].push_back(i) ; 
}
int subordinate[n+1]= {0};
dfs(1 , subordinate , children) ;
for(int i = 1 ; i<=n ; i++){
    cout<<subordinate[i]<<" "; 
} 
return 0;
}
