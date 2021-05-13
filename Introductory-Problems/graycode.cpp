#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
 int n ; 
 cin>>n ; 
vector<int> v ={0,1,3,2}; 
for(int i = 3; i<=n ; i++){
    for(int j = v.size()-1;j>=0 ; j--){
        int top =v[j];
        top = (1<<(i-1))|top ; 
        v.push_back(top) ; 
    }
}
for(auto x : v ){
    for(int i = n-1 ; i>=0 ; i--){
        cout<<(((1<<i)&x)>>i) ; 
    }
    cout<<endl ;
}

return 0;

}