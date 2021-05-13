#include<bits/stdc++.h>
using namespace std ;
long long int a[20] ; 
int n ; 
long long int mindiff(int i , long long int sum1 , long long int sum2){ 
    if(i==n){
        return abs(sum1-sum2) ; 
    }
    long long int x = mindiff(i+1 , sum1+a[i] , sum2);
    long long int y = mindiff(i+1 , sum1 , sum2+a[i]) ; 
    return min(x,y) ; 
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif

cin>>n ; 

for(int i =0 ; i<n ; i++){
    cin>>a[i] ; 
}
cout<<mindiff(0,0,0);
return 0;
}