#include<bits/stdc++.h>
using namespace std ;
int a[200000];
int idx[200001] ; 
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n , m ; 
cin>>n>>m; 
for(int i = 0 ; i<n ; i++){
    cin>>a[i];
    idx[a[i]] = i ; 
}
int cnt = 1; 
for(int i = 2 ; i<= n ; i++){
    if( idx[i-1]>idx[i]){
        cnt++ ; 
    }
}
//cout<<cnt<<endl ; 
while(m--){
    int x , y ; 
    cin>>x>>y ; 
    x--; y-- ; 
    if(x>y){
        swap(x,y) ; 
    }
        if(a[y]!=1){
            if(idx[a[y]-1]<y and idx[a[y]-1]>x){
                cnt++ ; 
            }
        }
        if(a[y]!=n){
            if(idx[a[y]+1]<y and idx[a[y]+1]>x){
                cnt-- ; 
            }
        }
        if(a[x]!=1){
            if(idx[a[x]-1]>x and idx[a[x]-1]<y){
                cnt--;
            }
        }
        if(a[x]!=n and idx[a[x]+1]>x and idx[a[x]+1]<y){
            cnt++ ; 
        }
        if(a[x]==a[y]+1){
            cnt-- ; 
        }
        if(a[x]+1==a[y]){
            cnt++ ; 
        }
        cout<<cnt<<endl ; 
    idx[a[x]] = y ; 
    idx[a[y]] = x ; 
    swap(a[x] , a[y]);
}
return 0;
}