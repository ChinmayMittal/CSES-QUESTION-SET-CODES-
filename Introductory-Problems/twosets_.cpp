#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ; 
cin>>n; 
if(n%4!=0 and n%4!=3){
    cout<<"NO" ; 
}else if(n%4==0){
      cout<<"YES\n" ; 
    cout<<n/2<<endl ; 
    for(int i = 0 ; i<n ; i +=4){
        cout<<(i+1)<<" "<<i+4<<" " ; 
    }
    cout<<endl ; 
    cout<<n/2<<endl ; 
      for(int i = 0 ; i<n ; i +=4){
        cout<<(i+2)<<" "<<i+3<<" " ; 
    }
}else if(n%4==3){
  cout<<"YES\n" ; 
  cout<<n/2+1<<endl ;
  cout<<"1 2 "; 
  for(int i = 4 ; i<n+1 ; i+=4){
    cout<<i<<" "<<i+3<<" ";
  }
  cout<<endl; 
  cout<<n/2<<endl ;
cout<<"3 ";
for(int i = 4 ; i<n+1; i+=4){
  cout<<i+1<<" "<<i+2<<endl ; 
}
}
return 0;
}