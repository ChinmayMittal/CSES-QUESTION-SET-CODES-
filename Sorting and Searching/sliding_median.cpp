#include<bits/stdc++.h>
using namespace std ;

int main(){
#ifndef ONLINE_JUDGE
freopen("C:\\Users\\Ruchi Mittal\\Desktop\\problemsolving\\input.txt","r",stdin);
freopen("C:\\Users\\Ruchi Mittal\\Desktop\\problemsolving\\output.txt","w",stdout);
 #endif
int n , k ;
cin>>n>>k ; 
multiset<int> left ; 
multiset<int> right ;
int median ;  
int a[n] ;
for( int i = 0 ; i<n ; i++){
    cin>>a[i];
}
for(int i = 0 ; i<k ;i++){
    if(i==0){
        left.insert(a[i]) ; 
        median = a[i] ; 
    }else{
        if(a[i]<median){
            if(left.size()>right.size()){
                right.insert(*prev(left.end())) ; 
                left.erase(prev(left.end()));
                left.insert(a[i]) ; 
                median = *(prev(left.end()));
            }else{
                left.insert(a[i]) ; 
                median = *(prev(left.end()));
            }
        }else{
              if(left.size()>right.size()){
                right.insert(a[i]) ; 
                median = *(prev(left.end())); 
            }else{
               if(a[i]<=*right.begin()){
                   left.insert(a[i]) ; 
                   median = *(prev(left.end())); 
               }else{
                   left.insert(*right.begin()) ; 
                   right.erase(right.begin()) ; 
                   right.insert(a[i]) ; 
                   median = *(prev(left.end())); 
               }
            }
        }
    }
    // cout<<"median is "<<median<<" "<<endl  ;
    // for(auto ele : left){
    //     cout<<ele<<" " ; 
    // }cout<<endl ; 
    // for(auto ele : right){
    //     cout<<ele<<" " ; 
    // }cout<<endl ; 
}
for(int i = k ; i<n ; i++){
    cout<<median<<" " ; 
    int remove_ele = a[i-k] ;
    if(remove_ele>median){
        auto it = right.find(remove_ele);
        right.erase(it) ; 
    } else{
        auto it = left.find(remove_ele);
        left.erase(it) ;
    }
    while(left.size()>right.size()+1){
        right.insert(*prev(left.end())) ; 
        left.erase(*prev(left.end())) ; 

    }
    while(right.size()>left.size()){
        left.insert(*right.begin());
        right.erase(*right.begin());
    }
   if(left.size()!=0) median = *prev(left.end()) ;
   else median = INT_MAX ; 
    if(a[i]<median){
            if(left.size()>right.size()){
                right.insert(*prev(left.end())) ; 
                left.erase(prev(left.end()));
                left.insert(a[i]) ; 
                median = *(prev(left.end()));
            }else{
                left.insert(a[i]) ; 
                median = *(prev(left.end()));
            }
        }else{
              if(left.size()>right.size()){
                right.insert(a[i]) ; 
                median = *(prev(left.end())); 
            }else{
               if(a[i]<=*right.begin()){
                   left.insert(a[i]) ; 
                   median = *(prev(left.end())); 
               }else{
                   left.insert(*right.begin()) ; 
                   right.erase(right.begin()) ; 
                   right.insert(a[i]) ; 
                   median = *(prev(left.end())); 
               }
            }
        }
}
cout<<median ; 
return 0;
}