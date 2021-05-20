#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n , k ; 
cin>>n>> k ; 
int a[n] ; 
long long int sum = 0 ; 
for(  int i = 0 ; i<n ; i++){
    cin>>a[i] ; 
    sum+=a[i] ; 
}
long long int possible_ans= INT64_MAX ; 
long long int s = 1 , e = sum ; 
while(s<=e){
    long long int mid  = (s+e)/2  ; 
    int i ; 
    int sub_arrays = 0 ; 
    long long int cur_sum = 0 ; 
    for(i = 0 ; i<n ; i++){
        if(a[i]+cur_sum>mid){
            if(a[i]>mid){
                break ; 
            }
            sub_arrays++ ; 
            cur_sum =0 ; 
            i-- ; 
        }else {
            cur_sum+=a[i] ; 
        }
    }
    if(i==n and sub_arrays<k){
        possible_ans = min(possible_ans , mid) ; 
            e = mid-1 ; 
    }else{
        s = mid+1 ; 
    }
} 
cout<<possible_ans ; 
return 0;
}