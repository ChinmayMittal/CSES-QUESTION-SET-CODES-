#include<bits/stdc++.h>
using namespace std ;
char grid[1001][1001] ; 
int monster_dist[1001][1001] , position[1001][1001] ;
int n , m , path_len =0;
string ans= "" ;  
bool valid_tile( int x , int y  ){
    if(x>n or y>m or x<1 or y<1 ) return false ; 
    if(grid[x][y]=='#') return false ; 

    return true ; 
}

bool is_possible( int x , int y , int dist ){
    if(x>n or y>m or x<1 or y<1 ) return false ; 
    if(grid[x][y]=='#') return false ; 

    if((x==n or y==m or x==1 or y==1) and dist<monster_dist[x][y]){
        path_len = dist ; 
        return true ; 
    } 


    if(position[x][y] <= dist ) return false ; 
    if( dist >= monster_dist[x][y] ) return false ; 

    position[x][y] = dist ;

    if( is_possible(x+1 , y , dist+1) ) {
        ans.push_back('D') ; 
        return true ;
        }  
    if( is_possible(x-1 , y , dist+1) ) {
        ans.push_back('U') ; 
        return true ;
        }  
    if( is_possible(x , y-1 , dist+1) ) {
        ans.push_back('L') ; 
        return true ;
        }  
    if( is_possible(x , y+1 , dist+1) ) {
        ans.push_back('R') ; 
        return true ;
        }  

    return false ; 
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int  x , y ; 
    cin >> n >> m ; 
    vector<pair< int , int >> monsters  ; 
    for( int i = 1 ; i<=n ; i++ ){
        string s ; 
        cin >> s ; 
        for( int j = 0 ; j<s.length() ; j++ ){
            grid[i][j+1] = s[j] ; 
            monster_dist[i][j+1] = INT32_MAX ; 
            position[i][j+1] = INT32_MAX ; 
            if(s[j]=='M'){
                monsters.push_back({ i , j+1 } ) ; 
                monster_dist[i][j+1] = 0 ; 
            }
            if(s[j] == 'A'){
                x = i ; y = j+1 ; 
            }

        }

    }
    queue<pair<pair<int,int> , int> > q ; 
 
    for (auto pos : monsters  ){
    q.push({{pos.first,pos.second} , 0  }) ;
}


        while(!q.empty()){
        auto p = q.front() ; 
        q.pop() ; 
        // monster_dist[p.first.first][p.first.second] = p.second  ; 
        int x = p.first.first ; 
        int y =p.first.second ;   
        if(valid_tile( x , y-1 ) and monster_dist[x][y-1] > p.second +1   ) {
            monster_dist[x][y-1] = p.second + 1 ; 
            q.push({{x , y-1} , p.second +1} ) ; 
        }
        if(valid_tile( x , y+1 ) and monster_dist[x][y+1] > p.second +1   ) {
monster_dist[x][y+1] = p.second + 1 ; 
            q.push({{x , y+1} , p.second +1} ) ; 
        }
        if(valid_tile( x+1 , y ) and monster_dist[1+x][y] > p.second +1   ) {
monster_dist[x+1][y] = p.second + 1 ; 
            q.push({{x+1 , y} , p.second +1} ) ;
        }
        if(valid_tile( x-1 , y ) and monster_dist[x-1][y] > p.second +1   ) {
            monster_dist[x-1][y] = p.second + 1 ; 
            q.push({{x-1 , y} , p.second +1} ) ;
        }
    } 



    if(is_possible(x,y,0)){
       cout<<"YES\n" ; 
       cout << path_len <<"\n"  ;
       for( int i = ans.length()-1 ; i>=0 ; i-- ) {
           cout << ans[i] ; 
       } 
   }else{
       cout << "NO\n" ; 
   }

return 0;
}