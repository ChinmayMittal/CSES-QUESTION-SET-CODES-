#include<bits/stdc++.h>
using namespace std ;
long long int cnt = 0 ; 
char a[9][9] ; 
bool canplace(int i , int j ){
 
    if(i<1 or i>8 or j<1 or j>8 ){
        return false ; 
    }
    if(a[i][j]=='*'){
        return false ; 
    }
    for(int r = 1 ; r<=8 ; r ++){
        if(r!=i and a[r][j]=='Q'){
            return false ; 
        }
    }
    for(int c = 1 ; c<=8 ; c++){
        if(c!=j and a[i][c]=='Q'){
            return false ; 
        }
    }
    for(int d = 1 ; i+d<=8 and j+d<=8 ;d++){
        if(a[i+d][j+d]=='Q'){
            return false ; 
        }
    }
     for(int d = -1 ; i+d>0 and j+d>0 ;d--){
        if(a[i+d][j+d]=='Q'){
            return false ; 
        }
    }
    for(int d = 1 ; i+d<=8 and j-d>=1 ; d++){
        if(a[i+d][j+d]=='Q'){
            return false ; 
        }
    }
    for(int d = 1 ; i-d>=1 and j+d<=8 ; d++){
        if(a[i-d][j+d]=='Q'){
            return false ; 
        }
    }

    return true ;

}
bool nqueens(int i , int j , int n ){
     if(n==0){
        cnt++ ; 
        return false ; 
    }
    if(j>8){
        return nqueens(i+1,1 ,n ) ; 
    }
    if(i>8){
        return false ; 
    }
   
    if(canplace(i,j)){
        a[i][j] = 'Q' ; 
        nqueens(i , j+1 , n-1) ; 
         a[i][j] = '.' ; 
         nqueens(i,j+1,n);
    }else{
        return nqueens(i,j+1 , n ) ; 
    }
    return false ;
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif

for(int i = 1 ; i<= 8 ; i++){
    for(int j = 1 ; j<=8 ; j++){
        cin>>a[i][j];
    }
}
    nqueens(1,1,8) ; 
    cout<<cnt; 
return 0;
}