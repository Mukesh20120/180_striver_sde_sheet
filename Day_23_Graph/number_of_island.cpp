int di[8]={-1,1,0,0,1,-1,-1,1};
int dj[8]={0,0,-1,1,1,-1,1,-1};
void change(int** arr,int n,int m,int i,int j){
    if(i<0 || j<0 || i>=n || j>=m || arr[i][j]==0)return;
    arr[i][j]=0;
    for(int ind=0;ind<8;ind++){
        change(arr,n,m,i+di[ind],j+dj[ind]);
    }
}

int getTotalIslands(int** arr, int n, int m)
{
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                change(arr,n,m,i,j);
                cnt++;
            }
        }
    }
  return cnt;
}


//we can also do this question using bfs and dfs traversal
#include <bits/stdc++.h>
void bfs(int** arr,int **visit,int n,int m,int i,int j){
    //first we mark the visited node
    visit[i][j]=1;
    //queue data structure for bfs traversal
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        //now we have to see all adjacent node
        for(int a=-1;a<=1;a++){
            for(int b=-1;b<=1;b++){
                int nr=r+a;
                int nc=c+b;
                if(nr>=0 && nr<n && nc>=0 && nc<m && arr[nr][nc] && !visit[nr][nc]){
                    visit[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
}

int getTotalIslands(int** arr, int n, int m)
{
    //let make 2d dynamic visit array
    int **visit;
    visit=new int*[n];
    for(int i=0;i<n;i++)
         visit[i]=new int[m];
    
    //filling with 0 
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            visit[i][j]=0;
    
    
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visit[i][j] && arr[i][j]){
                bfs(arr,visit,n,m,i,j);
                cnt++;
            }
        }
    }
    return cnt;
}
