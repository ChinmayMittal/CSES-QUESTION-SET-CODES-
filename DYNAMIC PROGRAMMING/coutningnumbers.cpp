#include<bits/stdc++.h>
using namespace std ;
 long long int  dp[20][10][2][2] ; 
  vector<int>A,B ;
long long int solve_a( int n , int x , int leading_zeroes , int tight_constraint ){
    if(n==1){
        long long int ans = 0 ; 
            if(x!=0 or leading_zeroes ){
                ans ++ ; 
            }
            for( int i = 1 ; i<=9 ; i++){
                if(tight_constraint and i>A[0]) break; 
                if(i!=x) ans ++ ; 
            }
            return ans ; 
    }
    if(dp[n][x][leading_zeroes][tight_constraint]!=-1) return dp[n][x][leading_zeroes][tight_constraint] ; 
    
    long long int ans = 0 ; 
    for( int i = 0 ; i<=9 ; i++){
        if(tight_constraint and i>A[n-1]){
            break ; 
        }
        if(tight_constraint and i==A[n-1]){
            if(x!=i){
                int temp ; 
                if(!leading_zeroes) temp= 0 ; 
                else if( i==0) temp =1 ; 
                else temp = 0 ; 
                ans += solve_a(n-1 , i , temp , 1 ) ; 
            }
        }else{
            if(i!=x){
                int temp ; 
                if(!leading_zeroes) temp= 0 ; 
                else if( i==0) temp =1 ; 
                else temp = 0 ; 
                ans += solve_a(n-1,i, temp , 0)  ; 
            }else if(i==0 and leading_zeroes){
                ans += solve_a( n-1 , 0 , 1 , 0 ) ; 
            }
        }

    }
    if(x!=-1) dp[n][x][leading_zeroes][tight_constraint] = ans ; 
    return ans ; 
}
int main(){
 #ifndef ONLINE_JUDGE
 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
 #endif
 ios_base::sync_with_stdio(false); 
 cin.tie(NULL);
 long long int a , b  , temp_a , temp_b ; 
 cin >> a >> b ;
 temp_a = a ; 
 temp_b = b ; 
 long long int ans_a , ans_b ; 
 if(a==0)  ans_a = 0 ; 
 if(b==0)  ans_b = 1 ;
 if(a==1) ans_a = 1 ; 
 if(b==1) ans_b = 2 ; 

 a-- ; 
 while(a>0){
     int d = a%10 ;  
     A.push_back(d) ; 
     a = a/10 ; 
 } 

 for( int i = 0 ; i<=19 ; i++){
     for( int j = 0 ; j<=9 ; j++){
         for( int k = 0 ; k<=1 ; k++){
             for( int l = 0 ; l<=1 ; l++){
                 dp[i][j][k][l] = -1 ; 
             }
         }
     }
 }
 if(temp_a!=0 and temp_a!=1) ans_a = solve_a( A.size() , -1 , 1 , 1 ) ; 

  for( int i = 0 ; i<=19 ; i++){
     for( int j = 0 ; j<=9 ; j++){
         for( int k = 0 ; k<=1 ; k++){
             for( int l = 0 ; l<=1 ; l++){
                 dp[i][j][k][l] = -1 ; 
             }
         }
     }
 }
 A.clear() ; 
   while(b>0){
     int d = b%10 ;  
     A.push_back(d) ; 
     b = b/10 ; 
 } 
//  for( auto ele : A){
//    cout << ele << " " ; 
//  }

 if(temp_b!=0 and temp_b!=1) ans_b = solve_a( A.size() , -1 , 1 , 1 ) ; 
 

 cout << ans_b -   ans_a ; 

return 0;
}