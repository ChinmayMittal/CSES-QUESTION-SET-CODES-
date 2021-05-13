#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int t ;
cin>>t ;  
while(t--){
    long long int x, y ; 
    cin>>x>>y ; 
    if(x==y){
        cout<<((x*x)+(x-1)*(x-1)+1)/2 <<endl ; 
    }else{
        if(max(x,y)%2==0){
            if(x>y){
                cout<<x*x-(y-1)<<endl ; 
            }else{
                cout<<(y-1)*(y-1)+x<<endl  ; 
            }
        }else{
            if(x>y){
                cout<<(x-1)*(x-1)+y<<endl  ; 
            }else{
                cout<<y*y -(x-1)<<endl ; 
            }
        }
    }
}
return 0;
}