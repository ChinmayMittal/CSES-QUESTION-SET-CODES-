#include<bits/stdc++.h>
using namespace std ;
long long query( vector<long long int >&segtree , int s , int e , int nl, int nr , int ti){
    if(nl>e or nr<s){
        return INT64_MIN ; 
    }
    if(nl>=s and nr<=e){
        return segtree[ti] ; 
    }
    int mid = (nl+nr)/2 ; 
    return max(query(segtree , s , e , nl , mid , ti*2 ) , query(segtree , s , e , mid+1 , nr , ti*2+1)); 
}
void build( vector<long long int>&segt , vector<long long int>&arr , int ti , int s , int e )
{
    if(s==e){
        segt[ti] = arr[s] ; 
        return ; 
    }
    int mid = (s+e)/2 ; 
    build( segt , arr , ti*2 , s , mid ) ; 
    build( segt , arr ,ti*2+1 ,  mid+1 , e) ; 
    segt[ti] = max(segt[2*ti] ,  segt[2*ti+1] );
    return ;  
} 
int main(){
#ifndef ONLINE_JUDGE
freopen("C:\\Users\\Ruchi Mittal\\Desktop\\problemsolving\\input.txt","r",stdin);
freopen("C:\\Users\\Ruchi Mittal\\Desktop\\problemsolving\\output.txt","w",stdout);
 #endif
int n,a,b ; 
cin>>n>>a>>b ; 
vector< long long int> segt(4*n ,  0) ; 
vector<long long int>arr(n , 0 ) ; 
for(int i = 0 ; i<n ; i++){
    cin>>arr[i];
    if(i!=0){
        arr[i] = arr[i-1] + arr[i] ; 
    }
}
// for(auto x : arr){
//     cout<<x<<" " ; 
// }
build(segt , arr , 1 , 0 , n-1 ) ;
// for(auto x : segt){
//     cout<<x<<" " ; 
// }
long long int maxsum = INT64_MIN ; 
for(int i = 0 ; i+a<=n ; i++){
    long long int tempsum  ; 
    if(i!=0) tempsum = -arr[i-1] ;
    else tempsum =  0  ; 
    tempsum += query( segt , i+a-1, min(b+i-1 , n) , 0 , n-1 , 1 );
    maxsum = max( maxsum , tempsum ) ;    
} 
cout<<maxsum ; 
return 0;
}