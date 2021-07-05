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
long long int query(vector<long long int>&a , vector<long long int>&segtree , vector<long long int>&lazy_tree , int s, int e , int ti ,  int k ){
        if(lazy_tree[ti]!=0){
        segtree[ti] += lazy_tree[ti]*(e-s+1) ; 
 
        if(s!=e){
            lazy_tree[ti*2] += lazy_tree[ti] ; 
            lazy_tree[2*ti + 1 ] += lazy_tree[ti] ; 
        }
        lazy_tree[ti] = 0 ; 
    }
    if(s==e and s==k){
        return segtree[ti] ; 
    }

    int mid = (s+e)/2 ; 

    if( k<=mid ){
        return query( a , segtree , lazy_tree , s , mid , ti*2 , k ) ; 
    }else{
        return query( a , segtree , lazy_tree , mid+1 , e , ti*2+1 , k )  ; 
    }

}
void update( vector<long long int>&a , vector<long long int>&segtree , vector<long long int>&lazy_tree , int s, int e , int ti , int ra , int rb ,  int u){
    if(lazy_tree[ti]!=0){
        segtree[ti] += lazy_tree[ti]*(e-s+1) ; 
 
        if(s!=e){
            lazy_tree[ti*2] += lazy_tree[ti] ; 
            lazy_tree[2*ti + 1 ] += lazy_tree[ti] ; 
        }
        lazy_tree[ti] = 0 ; 
    }

    if( s>=ra and e<=rb ){
        segtree[ti] += u*(e-s+1) ; 
                if(s!=e){
            lazy_tree[ti*2] += u ; 
            lazy_tree[2*ti + 1 ] += u ; 
        }
        return ; 
    }

    if( e<ra or s > rb){
        return ; 
    }

    int mid = (s+e)/2 ; 

    update( a , segtree , lazy_tree , s , mid , ti*2 , ra , rb , u  ) ; 
    update( a , segtree , lazy_tree , mid+1 , e , ti*2+1 , ra , rb , u  ) ; 

    segtree[ti] = segtree[ti*2] + segtree[2*ti+1] ; 

}
int main(){

 ios_base::sync_with_stdio(false); 
 cin.tie(NULL);
 #ifndef ONLINE_JUDGE
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 #endif
 int n , q ; 
 cin>>n>>q ;
vector<long long int> v(n);
vector<long long int> segtree(4*n);  
vector< long long int >lazy_tree(4*n , 0 ) ; 
for(int i = 0 ;i<n ; i++){
    cin>>v[i] ; 
}
buildtree(v , segtree , 0 , n-1 , 1) ;

while(q--){
    int type ; 
    cin >> type ; 
    if(type==1){
        long long int a , b , u ; 
        cin >> a >> b >> u ; 
        a-- ; b-- ; 
        update( v , segtree , lazy_tree , 0 , n-1 , 1 , a , b , u ) ; 
    }else{
        int k ; 
        cin >> k ; 
        k-- ; 
        cout << query( v , segtree , lazy_tree , 0 , n-1 , 1 , k ) <<"\n" ; 
    }
}
return 0;
}