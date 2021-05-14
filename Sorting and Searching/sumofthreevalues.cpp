#include<bits/stdc++.h>
using namespace std ;
pair<int , int > find(int s , int e ,long long int x , pair<int,int> a[]){
    while(s<e){
        if(a[s].first+a[e].first==x){
            return make_pair(s,e) ; 
        }else if(a[s].first+a[e].first<x){
            s++ ; 
        }else{
            e-- ; 
        }

    }
    return make_pair(-1 , -1) ; 
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
int n ; 
cin>>n ; 
long long int x  ; 
cin>>x ; 
pair<int,int> a[n] ;
for(int i = 0 ; i<n ; i++){
    int nu ; 
    cin>>nu ; 
    a[i] = make_pair(nu , i+1) ;  
}
sort(a , a+n) ;
bool done = false ; 
for(int i = 0 ; i<n-2 ; i++){
    pair<int , int >p = find(i+1 , n-1 , x-a[i].first , a) ; 
    if(p.first!=-1){
        cout<<a[i].second<<" "<<((a[p.first]).second)<<" "<<a[p.second].second ; 
        done = true ;
        break ; 
    }
} 
if(!done){
    cout<<"IMPOSSIBLE" ; 
}

return 0;
}
