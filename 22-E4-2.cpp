/*小明被困在一个迷宫之中，迷宫中共有N个点，标号分别为1,2,3…N，且迷宫只有一个出口。N个点之间互相有一些道路连通(单向)，两个点之间可能有多条道路连通，
但是并不存在一条两端都是同一个点的道路。小明希望知道从当前位置S去往出口T的最短距离是多少。如果不存在去往出口的道路，输出-1*/

#include <iostream>
#include <queue>

using namespace std;

struct Edge {
    int u, v, w;
    int next;
} edge[1000005];

struct Node {
    int dist;
    int n;
    bool operator<(const Node &n) const {
        return dist > n.dist;
    }
};

int head[100005];
bool visited[100005];
int dist[100005];

priority_queue<Node> q;

int main() {
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    for (int i = 1; i <= N; i++) {
        head[i] = 0;
        visited[i] = false;
        dist[i] = 0x7fffffff;
    }
    for (int i = 1; i <= M; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
        edge[i].next = head[edge[i].u];
        head[edge[i].u] = i;
    }
    dist[S] = 0;
    q.push({0, S});
    while (!q.empty()) {
        Node n = q.top();
        q.pop();
        if (visited[n.n])
            continue;
        visited[n.n] = true;
        for (int i = head[n.n]; i != 0; i = edge[i].next) {
            if (dist[edge[i].v] > n.dist + edge[i].w) {
                dist[edge[i].v] = n.dist + edge[i].w;
                q.push({dist[edge[i].v], edge[i].v});
            }
        }
    }
    if (dist[T] == 0x7fffffff)
        cout << -1;
    else
        cout << dist[T];
}