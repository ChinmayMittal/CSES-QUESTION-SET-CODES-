#include<bits/stdc++.h>
using namespace std ;
string ans ; 
int towerofhanoi(int n , int s , int e ){
    if(n==1){
        ans.push_back('1'+(s-1));
        ans.push_back('1'+(e-1)) ; 
        return 1 ; 
    }

    int x = towerofhanoi(n-1 , s , 6-s-e);
       ans.push_back('1'+(s-1));
        ans.push_back('1'+(e-1)) ; 
    int y = towerofhanoi(n-1 , 6-s-e , e) ; 
    return 1+x+y ; 

}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ; 
cin>>n ; 
cout<<towerofhanoi(n,1,3)<<endl ; 
for(int i = 0 ; i+1<ans.size() ; i+=2){
    cout<<ans[i]<<" "<<ans[i+1]<<endl ; 
}
return 0;
}
