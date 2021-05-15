#include<bits/stdc++.h>
using namespace std ;
# define m 1000000007
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ; 
cin>>n ; 
if(n%4!=0 and n%4!=3){
    cout<<"0" ; 
}else{
    //int a[501][125];
    vector<long long int> a(n*(n+1)/4+1,0) ; 
    vector<long long int> acur(n*(n+1)/4+1,0);
     for(int i = 1 ; i<=n; i++){
        for(int j = 0 ; j<=n*(n+1)/4 ; j++){
            if(j==0){
                acur[0]=1 ; 
            }else{
                if(i!=1) acur[j] = a[j] ; 
                else {
                    if(j==1){
                        acur[1]=1 ; 
                    }else{
                        acur[j]=0 ; 
                    }

                }
                if(i<=j and i!=1){
                    acur[j]=(acur[j]+a[j-i]+0ll)%m ; 
                }
            }
        }
        for(int k = 0 ; k<=n*(n+1)/4 ;  k++){
            a[k] = acur[k] ; 
        }
    }
    // for(int i =1 ; i<=n ; i++){
    //     for(int j = 0 ; j<=n*(n+1)/4 ; j++){
    //         cout<<a[j]<<" "  ; 
    //     }
    //     cout<<endl ; 
    // }
    cout<<(1ll*a[n*(n+1)/4]*(500000004))%1000000007;//modulo inverse of 2
}
return 0;
}