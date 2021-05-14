#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ; 
cin>>n ; 
vector<pair<int ,int >> movies  ; 
 for(int i = 0 ; i<n ; i ++){
     int s  ,e ; 
     cin>>s>>e ; 
     movies.push_back(make_pair(e,s));
 }
 sort(movies.begin() , movies.end()); 
//  for(int i = 0 ; i<n ; i ++){
//      cout<<movies[i].second<<" "<<movies[i].first<<endl ; 
//  }
  int cnt = 1 ; 
  int lastend = movies[0].first ; 
    for(int i = 1 ; i<movies.size() ; i++){
      if(movies[i].second>=lastend){
          cnt++ ; 
          lastend = movies[i].first ; 
      }
  }
  cout<<cnt<<endl ; 
return 0;
}