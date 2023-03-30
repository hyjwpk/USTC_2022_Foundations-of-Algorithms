/*在一个工厂货物运输系统中共有N个节点, 编号为1,2,3…N, 节点之间有传送带（单向）连接, 每个传送带都有使用寿命, 
传送带的寿命为一个数字L, 表示在传送完L个单位的货物后, 传送带就会破损无法使用。现在需要从节点S向节点T传送货物, 
求在当前传输系统中, 最多可以顺利传输多少单位的货物从节点S到节点T*/

#include <iostream>
#include <queue>

using namespace std;

int map[505][505];
bool visited[505];
int p[505];


int main(){
    int N, M, S, T;
    int result = 0;
    cin >> N >> M >> S >> T;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            map[i][j] = 0;
        }
    }
    for (int i = 1; i <= M; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        map[u][v] += l;
    }
    while (true) {
        for (int i = 1; i <= N; i++) {
            visited[i] = false;
            p[i] = 0;
        }
        queue<int> q;
        q.push(S);
        visited[S] = true;
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            for (int i = 1; i <= N; i++) {
                if (!visited[i] && map[n][i] > 0) {
                    q.push(i);
                    visited[i] = true;
                    p[i] = n;
                }
            }
        }
        if (!visited[T]) {
            break;
        }
        int cur = 0x7fffffff;
        for (int i = T; i != S; i = p[i]) {
            if (map[p[i]][i] < cur){
                cur = map[p[i]][i];
            }
        }
        for (int i = T; i != S; i = p[i]) {
            map[p[i]][i] -= cur;
            map[i][p[i]] += cur;
        }
        result += cur;
    }
    cout << result;
}