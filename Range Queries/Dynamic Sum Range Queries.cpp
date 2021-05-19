#include<bits/stdc++.h>
using namespace std ;
long long buildtree(vector<long long int>&a , vector<long long int>&segtree , int s, int e , int ti){
    if(s==e){
        segtree[ti] = a[s] ; 
        return a[s] ; 
    }
    int mid = (s+e)/2 ; 
    long long left = buildtree( a , segtree , s , mid , ti*2) ;
    long long right = buildtree( a , segtree , mid+1 , e , ti*2+1); 
    segtree[ti] = left+right ; 
    return segtree[ti] ; 
}
long long query( vector<long long int>&a , vector<long long int>&segtree , int s, int e , int ti , int l , int r){
    if(l>e or r<s){
        return 0 ; 
    }
    if(s>=l and r>=e){
        return segtree[ti];
    }
    int mid = (s+e)/2 ; 
    return query(a , segtree , s , mid , ti*2 , l , r)+ query(a , segtree , mid+1 ,e , ti*2+1 , l , r) ;
}
void update( vector<long long int>&a , vector<long long int>&segtree , int s, int e , int ti , int idx , int v){
    if(s==e and s==idx){
        a[idx] = v ; 
        segtree[ti] = v ; 
        return  ; 
    }
    if(idx<s or idx>e){
        return ; 
    }
    int mid = (s+e) /2 ; 
    update( a , segtree , s , mid , ti*2 , idx , v ) ; 
    update( a , segtree , mid+1 , e , ti*2 +1 , idx , v ) ;
    segtree[ti] = segtree[2*ti] + segtree[2*ti+1] ;
    return ;   
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n , q ; 
cin>>n>>q ;
vector<long long int> v(n);
vector<long long int> segtree(4*n);  
for(int i = 0 ;i<n ; i++){
    cin>>v[i] ; 
}
buildtree(v , segtree , 0 , n-1 , 1) ; 
// for(auto x  :segtree){
//     cout<<x<<" " ; 
// }
// cout<<endl ; 
for(int i = 0 ; i<q ; i++){
    int q , a , b ; 
    cin>>q>>a>>b ; 
    if(q==2){
        a-- ; b-- ; 
        cout<<query(v , segtree , 0 , n-1 , 1 , a , b )<<endl ; 
    }else {
        a-- ; 
        update(v, segtree , 0 , n-1 , 1, a ,b) ; 
    }
    
   
}

return 0;
}
