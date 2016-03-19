#include<vector>
#include<queue>
#include<fstream>
#include<bitset>
#define maxn 1000100
using namespace std;

bitset<maxn> inQueue;
queue<int> Q;
vector<int> neighbours[maxn];
int n,m,source;
int dist[maxn];

void bfs(int source) {
    Q.push(source);
    dist[source] = 0;
    inQueue[source] = 1;
    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();
        for(int i = 0; i < neighbours[node].size(); i++) {
            int neighbour = neighbours[node][i];

            if(dist[neighbour] == -1)
                dist[neighbour] = dist[node] + 1;

            if(!inQueue[neighbour]) {
                Q.push(neighbour);
                inQueue[neighbour] = 1;
            }
        }
    }
}

int main() {
    ifstream in("bfs.in");
    ofstream out("bfs.out");

    for(int i = 0; i < maxn; i++)
        dist[i] = -1;

    in>>n>>m>>source;
    int x,y;
    for(int i = 0 ;i <= m;i++) {
        in>>x>>y;
        neighbours[x].push_back(y);
    }
    bfs(source);

    for(int i = 1;i <= n; i++)
        out<<dist[i] << " ";

    return 0;
}
