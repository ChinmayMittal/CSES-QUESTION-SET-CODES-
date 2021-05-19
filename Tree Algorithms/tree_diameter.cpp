#include<bits/stdc++.h>
int ans = INT_MIN ; 
using namespace std ;
int diameter(int cur , int parent  , vector<vector<int>>&tree){
    if(tree[cur].size()==1 and parent!=0){
        ans = max(ans , 0) ; 
        return 1;
    }
    int height = INT_MIN ;
    int second_height = INT_MIN ;  
    for(auto nbr : tree[cur]){
        if(nbr!=parent){
            int sub_ans = diameter( nbr , cur , tree) ; 
            if(sub_ans>height){
                second_height = height ;
                height = sub_ans ;  
            }else if(sub_ans<=height and sub_ans>second_height){
                second_height = sub_ans ; 
            }
        }
    }
    if(second_height!=INT_MIN)ans = max(ans , second_height+height) ;
    else if(height!=INT_MIN)ans = max(ans , height) ; 
    else ans = 0 ;  
    return height +1 ; 
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ;
cin>>n ;
vector<vector<int>>tree(n+1) ; 
for(int i = 0 ; i<n-1 ; i++){
    int x ,y ;  
    cin>>x>>y ; 
    tree[x].push_back(y) ; 
    tree[y].push_back(x);
}
diameter( 1 , 0 , tree) ;
cout<<ans ; 
return 0;
}