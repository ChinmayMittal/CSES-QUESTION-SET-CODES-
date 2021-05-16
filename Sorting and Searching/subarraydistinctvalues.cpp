#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n , k ; 
cin>>n>>k;  
int a[n+1]; 
for(int i = 0 ; i<n ; i++){
    cin>>a[i] ; 
}
map<int , int> m ; 
int right = 0 ; 
int left = 0 ;
long long int cnt = 0 ;  
while(right<n){
m[a[right]]++ ; 
while(m.size()>k){
    m[a[left]]-- ; 
    if(m[a[left]]==0){
        m.erase(a[left]) ; 
    }
    left++ ; 
}
cnt += right - left + 1; 
right++ ; 
}
cout<<cnt ; 
return 0;
}