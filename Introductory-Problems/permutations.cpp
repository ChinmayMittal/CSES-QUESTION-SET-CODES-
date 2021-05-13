#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ; 
cin>>n ; 
if(n==2 or n==3){
    cout<<"NO SOLUTION" ; 
}else{
    for(int i = 2 ; i<=n ; i+=2){
        cout<<i<<" " ; 
    }
    for(int i = 1 ; i<=n ; i+=2){
        cout<<i<<" "; 
    }
}
return 0;
}