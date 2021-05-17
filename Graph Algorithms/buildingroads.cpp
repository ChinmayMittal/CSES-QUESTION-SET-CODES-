#include<bits/stdc++.h>
using namespace std ;
int find(int i , int parent[]){
    if(parent[i]==-1){
        return i ; 
    }
    int super_parent = find(parent[i] , parent) ;
    parent[i] = super_parent ; 
    return super_parent ;  
}
void join_(int x , int y , int parent[]){
    int a = find(x , parent) ; 
    int b = find( y , parent); 
     if(a!=b){
         parent[a]  = b ; 
     } 
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n , m ; 
cin>>n>>m ; 
int parent[n+1] ; 
for(int i =1 ; i<=n ; i++){
    parent[i]=-1 ; 
}
for(int i = 0 ; i<m ; i++){
    int a ,b ; 
    cin>>a>>b ; 
    join_(a,b,parent) ; 
}
long long int cnt = 0 ; 
set<int> s  ; 
for(int i = 1 ; i<=n ; i++){
    s.insert(find(i , parent) );
}
cout<<s.size()-1<<endl ; 
for(auto it = s.begin() ; it!=prev(s.end()) ; it++){
    cout<<*it<<" "<<*next(it)<<endl ; 
}
return 0;
}