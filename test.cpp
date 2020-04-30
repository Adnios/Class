#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct node{//node结构体
    int x,y,yx,sy,s;
};
node minq(node a,node b){//找最优解
    if(a.s!=b.s)return a.s<b.s?a:b;
    if(a.yx+a.sy!=b.yx+b.sy)return a.yx+a.sy<b.yx+b.sy?a:b;
    return a.yx<b.yx?a:b;
}
bool vis[355][355][20][20],look[355][355];//一堆杂七杂八的东西
int tag[355][355];
int n,m,c1,c2,d;
int map[355][355];
const int dx[8]={1,0,-1,0,1,-1,-1,1},dy[8]={0,1,0,-1,1,1,-1,-1};
void lookaround(int x,int y,int k){//处理看到的范围（差分数组tag）
    for(int i=0;i<=k;i++){
        tag[max(x-i,1)][max(y-(k-i),1)]++; 
        tag[max(x-i,1)][min(y+(k-i),m)+1]--;
        tag[min(x+i,n)][max(y-(k-i),1)]++;
        tag[min(x+i,n)][min(y+(k-i),m)+1]--;
    }
}
int sx,sy,ex,ey;
queue <node> q;//队列
node ans=(node){0,0,233333333,233333333,233333333};
void bfs(){//广搜
    while(!q.empty()){
        node fro=q.front();
        q.pop();
        if(fro.s>ans.s)continue;
        if(fro.x==ex&&fro.y==ey){
            ans=minq(ans,fro);
            continue;
        } 
        for(int i=0;i<8;i++){
            int nx=fro.x+dx[i];
            int ny=fro.y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m||map[nx][ny]>0)continue;
            if(look[nx][ny]){
                if(vis[nx][ny][fro.yx+1][fro.sy]||fro.yx+1>c1)continue;
                vis[nx][ny][fro.yx+1][fro.sy]=1;
                q.push((node){nx,ny,fro.yx+1,fro.sy,fro.s+1});
            }
            else{
                if(vis[nx][ny][fro.yx][fro.sy])continue;
                vis[nx][ny][fro.yx][fro.sy]=1;
                q.push((node){nx,ny,fro.yx,fro.sy,fro.s+1});             
            }
        }
        if(fro.sy+1>c2)continue;
        for(int i=0;i<4;i++){
            int nx=fro.x+dx[i]*d;
            int ny=fro.y+dy[i]*d;
            if(nx<1||nx>n||ny<1||ny>m||map[nx][ny]>0)continue;
            if(look[nx][ny]){
                if(vis[nx][ny][fro.yx+1][fro.sy+1]||fro.yx+1>c1)continue;
                vis[nx][ny][fro.yx+1][fro.sy+1]=1;
                q.push((node){nx,ny,fro.yx+1,fro.sy+1,fro.s+1});
            }
            else{
                if(vis[nx][ny][fro.yx][fro.sy+1])continue;
                vis[nx][ny][fro.yx][fro.sy+1]=1;
                q.push((node){nx,ny,fro.yx,fro.sy+1,fro.s+1});               
            }           
        }
    }
}
int main(){
    cin>>n>>m>>c1>>c2>>d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            string s;
            cin>>s;
            if(s[0]=='S'){
                sx=i,sy=j;
                map[i][j]=-1;
                q.push((node){sx,sy,0,0,0});
                vis[i][j][0][0]=1;
            }
            else if(s[0]=='T'){
                ex=i,ey=j;
                map[i][j]=-2;
            }
            else if(s[0]=='.')map[i][j]=0;
            else{
                int x=0;
                for(int i=0;i<s.size();i++)
                    x=x*10+s[i]-'0';
                map[i][j]=x;
                lookaround(i,j,x-1);
            }
        }
    }
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=m;j++){
            sum+=tag[i][j]; //求出look数组（前缀和）
            if(sum>0)look[i][j]=1;  
        }
    }   
    bfs();//广搜
    if(ans.s==233333333)printf("-1");
    else printf("%d %d %d",ans.s,ans.yx,ans.sy);//最后输出
    return 0;
}
