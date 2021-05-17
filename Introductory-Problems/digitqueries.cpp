#include<bits/stdc++.h>
using namespace std ;
long long int digits_taken_till_n(long long int n ){
    long long int ans = n ; 
    long long int subtracter= 9 ;
    while(n-subtracter>0){
        ans+= n-subtracter ; 
        subtracter = subtracter*10+9 ; 
    }
    return ans ; 
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int q ; 
cin>>q ;  
   // the approach invoolves finding a possible number for which all digits taken to form the numbers from 1- possible are less than the query hence the number to which the digit in the position 
    // of the query belongs is possible +1 
while(q--){
    long long int n ; 
    cin>>n ; 
    long long int s = 1 , e = 1e18 ; 
    long long int pos ; 
    while(s<=e){
        long long int mid  = (s+e)/2 ; 
        long long digits_taken = digits_taken_till_n(mid);
        if(digits_taken>=n){
            e = mid-1 ; 
        }else{
            pos = mid ; 
            s = mid+1 ; 
        }
    }
    long long int t =n- digits_taken_till_n(pos) ; 
    string sans = to_string(pos+1) ; 
     cout<<sans[t-1]<<endl ;
}
return 0;
}
