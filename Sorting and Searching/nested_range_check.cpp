#include<bits/stdc++.h>
using namespace std ;
bool compare(pair<pair<int,int> , int > a , pair<pair<int,int> , int > b ) {
    if(a.first.first < b.first.first) return true ; 
    else if(a.first.first == b.first.first ) return a.first.second >= b.first.second ; 
    else return false ; 
}
int main(){
 ios_base::sync_with_stdio(false); 
 cin.tie(NULL);
 #ifndef ONLINE_JUDGE
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 #endif
 int n ;
 cin >> n ; 
 vector<pair<pair<int,int> , int > >a(n) ; 
 for( int i = 0 ; i< n ; i ++ ){
     int x , y ; 
     cin >> x >> y ; 
     a[i] = {{x,y},i} ; 
 }

 sort( a.begin() , a.end(), compare  ) ; 

 vector<int>endtime(n) , contains(n , 0 ) , is_containded(n ,  0 ) ; 
 endtime[n-1] = INT32_MAX ; 

 for( int i = n-2 ; i>=0 ; i-- ){
     endtime[i] = min( endtime[i+1] , a[i+1].first.second ) ; 
 }

int max_endtime = INT32_MIN ; 

 for( int i = 0 ; i<n ; i++ ){
     if(a[i].first.second<=max_endtime){
        is_containded[a[i].second] = 1 ; 
     }
     max_endtime = max(a[i].first.second , max_endtime ) ; 
    if(a[i].first.second >= endtime[i]){
        contains[a[i].second] = 1 ; 
    }
 }

 for ( auto ele : contains ) 
 {
     cout << ele << " " ; 
 }

 cout << "\n" ; 

 for( auto ele : is_containded ) {
     cout << ele <<" " ; 
 } 

return 0;
}