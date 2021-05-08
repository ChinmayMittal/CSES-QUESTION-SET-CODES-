#include<bits/stdc++.h>
using namespace std ;
 
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ,x ; 
cin>>n>>x  ; //take input n and x 
int a[n] ; //create an array to store coin values 
for(int i = 0 ; i<n ; i++){
    cin>>a[i] ; 
    //inputting coin values in the array 
}
int dp[x+1] ; 
//creating dp array to store answer for sub problems 
dp[0] =  1 ; //one way to make 0 rupees --  do nothing !!
for(int i = 1 ; i<= x ; i++){ // compute answers to current state from previous states 
        dp[i] = 0 ; //initializing value 
    for(int j = 0 ; j<n ; j++){ //checking if a particular coin is possible 
        if(a[j]<=i){// 0ll prevents overflow by type casting the expression 
            dp[i] = (0ll+dp[i-a[j]]+dp[i])%1000000007 ; // if possible to take a coin then take the coin 
            //number of ways is the number of ways to make the remaining sum after picking a coin 
        }
    }
}
cout<<dp[x] ; //dp[x] stores the number of ways to make x 
return 0;
}
