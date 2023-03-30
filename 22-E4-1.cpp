/*沙漠上，新建了N座城市，用1,2,3…N表示，城市与城市之间还没有道路，现在需要建设这些城市的道路网络，需要在城市间修建道路。
施工队给出了M条道路的预计费用信息，每条道路的预计费用信息可以表示为U_iV_iW_i（即如果要在U_i​和V_i之间修建道路，预计费用为W_i），
道路是双向的。现从MM条道路中选择一定数量的道路来修建，使得这些城市之间两两之间可达（可以通过其他城市间接到达），
你需要求出达成上述条件的最少预算*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int p[100005];

struct Edge {
    int u, v, w;
} edge[1000005];

int find(int x) {
    while (x != p[x])
        x = p[x] = p[p[x]];
    return x;
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        p[i] = i;
    }
    for (int i = 0; i < M; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    sort(edge, edge + M, [](Edge a, Edge b) { return a.w < b.w; });
    long long result = 0, count = 0;
    for (int i = 0; i < M && count < N - 1; i++) {
        int pu = find(edge[i].u), pv = find(edge[i].v);
        if (pu != pv) {
            p[pu] = pv;
            result += edge[i].w;
            count++;
        }
    }
    cout << result;
}