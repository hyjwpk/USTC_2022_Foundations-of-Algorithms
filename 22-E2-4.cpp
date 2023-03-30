/*现有若干危险品需要放置在A,B两个仓库。
当两种特定的危险品放置在相同地点时即可能产生危险。我们用危险系数\alpha_{i,j}表示危险品i,j放置在一起的危险程度。
一些危险品即使放置在一起也不会产生任何危险，此时\alpha_{i,j}=0，还有一些危险品即使单独放置也会产生危险，此时\alpha_{i,i}>0。
定义两个仓库整体的危险系数为\max(\max_{i,j\in A}\alpha_{i,j},\max_{i,j\in B}\alpha_{i,j})，
即放置在一起的所有危险品两两组合的危险系数的最大值。现在对于一组给定的危险系数，需要设计方案使得整体危险系数最小。
*/

// Disjoint set
#include <iostream>
#include <algorithm>
using namespace std;

struct Dangerous {
    int i, j;
    int alaph;
};

struct Disjointset{
    int x,y;
};

int find(Disjointset *s, int x) {
    if (s[x].x != x) {
        s[x].x = find(s, s[x].x); // 路径压缩
    }
    return s[x].x;
}

int cmp(Dangerous a, Dangerous b) {
    return a.alaph > b.alaph;
}

int main(void) {
    int n;
    int m;
    cin >> n >> m;
    Disjointset *disjointset = new Disjointset[n];
    Dangerous *dangerous = new Dangerous[m];
    for (int i = 0; i < m; i++) {
        cin >> dangerous[i].i >> dangerous[i].j >> dangerous[i].alaph;
    }
    sort(dangerous, dangerous + m, cmp);
    for (int i = 0; i < n; i++) {
        disjointset[i].x = i;
        disjointset[i].y = 0;
    }
    int max = 0;
    for (int i = 0; i < m; i++) {
        int x = find(disjointset, dangerous[i].i);
        int y = find(disjointset, dangerous[i].j);
        if (x != y) {
            if(disjointset[y].y > 0){
                disjointset[x].x = find(disjointset, disjointset[y].y);
            }
            if(disjointset[x].y > 0){
                disjointset[y].x = find(disjointset, disjointset[x].y);
            }
        } else {
            max = dangerous[i].alaph;
            break;
        }
        disjointset[dangerous[i].i].y = y;
        disjointset[dangerous[i].j].y = x;
    }
    cout << max;
    return 0;
}