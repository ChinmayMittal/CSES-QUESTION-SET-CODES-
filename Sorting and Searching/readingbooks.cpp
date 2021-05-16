#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ; 
cin>>n ; 
long long int a[n] ; 
long long int sum = 0 ; 
for(int i = 0 ; i<n ; i++){

    cin>>a[i] ; 
    sum+=a[i] ; 
}
if(n==1){
    cout<<2*a[0] ; 
    return 0 ; 
}
sort(a , a+n) ; 
long long ltime = 0  ; 
int left = 0 ; 
while(ltime+a[left]<=sum/2){
    ltime+=a[left] ; 
    left ++; 
}
left -- ; 
int right = n-1 ; 
long long rtime = 0 ; 
while(rtime+a[right]<=sum/2){
    rtime += a[right] ; 
    right -- ; 
}
right++ ; 
if(rtime==0){
    rtime +=a[n-1] ; 
    right -- ; 
}
if(right==left+1){
    cout<<2*rtime ; 
}else{
    cout<<sum ; 
}

return 0; 
}