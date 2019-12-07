#include <iostream>
using namespace std;
const int maxx=100001;
struct Edge{
    int next,to,dis;
}edge[maxx];
int head[maxx],cnt,n,m;
void add_edge(int from,int to,int dis){
    edge[++cnt].next=head[from];
    edge[cnt].to=to;
    edge[cnt].dis=dis;
    head[from]=cnt;
}

int main()
{
    cin>>n>>m;
    for (int i = 0;i<m;i++) {
        int a, b, c;
        cin>>a>>b>>c;
        add_edge(a, b, c);
        add_edge(b, a, c);
    }
    for(int i=1;i<=n;i++){
        cout<<i<<"  ";
        for(int j=head[i];j!=0;j=edge[j].next){
            cout<<edge[j].to<<" ";
        }
        cout<<endl;
    }
}
