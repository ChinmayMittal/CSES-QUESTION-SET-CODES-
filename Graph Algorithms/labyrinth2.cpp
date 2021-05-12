#include<bits/stdc++.h>
using namespace std ;

int r,c ; 
char a[1000][1000] ; 
int ax,ay,bx,by ; 
bool visited[1000][1000] ; 
pair<int,int> parent[1000][1000] ; 
int dist[1000][1000]  ; 
string ans = ""; 
bool possible(int i , int j ){
    if(i<0 or j<0 or i>=r or j>=c){
        return false ; 
    }
    if(a[i][j]=='#'){
        return false ; 
    }
    if(visited[i][j]){
        return false ; 
    }
    return true ; 
}
void bfs(int i , int j ){
        visited[i][j] = true ; 
        dist[i][j] = 0 ; 
        queue<pair<int,int>> q ; 
        q.push({i,j});
        while(!q.empty()){
            pair<int,int>par = q.front();
            int x = par.first ; 
            int  y  = par.second ; 
            q.pop() ; 
            if(possible(x-1,y)){
                parent[x-1][y] = make_pair(x,y) ; 
                dist[x-1][y] = 1 + dist[x][y] ; 
                q.push({x-1,y});
                visited[x-1][y]=true;
            } 
            if(possible(x+1,y)){
                parent[x+1][y] = make_pair(x,y) ; 
                dist[x+1][y] = 1 + dist[x][y] ; 
                q.push({x+1,y});
                visited[x+1][y]=true;
            }
            if(possible(x,y-1)){
                parent[x][y-1] = make_pair(x,y) ; 
                dist[x][y-1] = 1 + dist[x][y] ; 
                q.push({x,y-1});
                visited[x][y-1]=true;
            }
            if(possible(x,y+1)){
                parent[x][y+1] = make_pair(x,y) ; 
                dist[x][y+1] = 1 + dist[x][y] ; 
                q.push({x,y+1});
                visited[x][y+1]=true;
            }
        }
        return ; 
        
}
// void printpath(int i , int j ){
//     if(i==ax and j==ay){
//         return ; 
//     }
//     pair<int,int >par = parent[i][j];
//     int x = par.first ; 
//     int y = par.second ; 
    
//     // if(x<i){
//     //     ans.push_back('D') ; 
//     // }
//     // if(x>i){
//     //     ans.push_back('U') ; 
//     // }
//     // if(y<j){
//     //     ans.push_back('R') ; 
//     // }
//     // if(y>j){
//     //     ans.push_back('L');
//     // }
//     cout<<i<<" "<<j<<endl ; 
//     printpath(x,y);
//     return  ; 
// }
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
 #endif
cin>>r>>c ; 
 for(int i = 0 ; i<r ; i++){
     for(int j = 0 ; j<c ; j++){
         cin>>a[i][j] ; 
        visited[i][j] = false ; 
        dist[i][j]=INT_MAX ; 
          if(a[i][j]=='A'){
             ax = i ; 
             ay = j ; 
             a[i][j]='.' ; 
         }else if(a[i][j]=='B'){
             bx = i ; 
             by = j ; 
         }
     }
 }
 
 bfs(ax,ay) ; 
//  for(int i = 0 ; i<r ; i++){
//      for(int j = 0 ; j<c ; j ++){
//          cout<<"{"<<parent[i][j].first<<","<<parent[i][j].second<<"}" ;
//      }
//      cout<<endl ; 
//  }
 if(dist[bx][by]!=INT_MAX){
     cout<<"YES\n";
     cout<<dist[bx][by]<<endl ; 
        int curx =bx ; 
        int cury = by ; 
        while(!(curx==ax and cury==ay)){
           // cout<<curx<<" "<<cury<<endl ; 
            pair<int,int> par = parent[curx][cury] ; 
            int x = par.first ; 
            int y = par.second ; 
            if(x<curx){
                ans.push_back('D');
            }else if(x>curx){
                ans.push_back('U') ; 
            }else if(y<cury){
                ans.push_back('R') ; 
            }else{
                ans.push_back('L');
            }
           //cout<<x<<" "<<y<<endl ;
            curx = x ;
            cury = y ; 
            
        }
     reverse(ans.begin(), ans.end()) ;
     cout<<ans; 
 }else{
     cout<<"NO\n" ; 
 }
return 0;
}