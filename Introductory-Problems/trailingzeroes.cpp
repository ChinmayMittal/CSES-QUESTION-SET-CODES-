#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ; 
cin>>n ; 
int temp = n ; 
long long int two = 0 ; 
while(temp>0){
    two += temp/2 ; 
    temp/=2 ; 
}
temp = n ; 
long long int five = 0 ; 
while(temp>0){
    five += temp/5 ; 
    temp = temp/5 ; 
}
cout<<min(five,two)<<endl  ;  
return 0;
}