/*************************************************************************
	> File Name: 4281.c
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年10月23日 星期二 20时49分30秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

#define MAX_K 20
#define MAX_N 500000

struct Edge {
    int32_t v, n;
} g[MAX_N << 1];

int head[MAX_N + 5] = {0}, cnt = 0;

inline void add(int32_t a, int32_t b) {
    g[++cnt].v = b;
    g[cnt].n = head[a];
    head[a] = cnt;
    return ;
}

int gas[MAX_N][MAX_K] = {0}, dep[MAX_N] = {0};

void dfs(int32_t u, int32_t father) {
    gas[u][0] = father;
    dep[u] = dep[father] + 1;
    for (int i = 1; i < MAX_K; i++) {
        gas[u][i] = gas[gas[u][i - 1]][i - 1];
    }
    for (int32_t i = head[u]; i ; i = g[i].n) {
        if (g[i].v == father) continue;
        dfs(g[i].v, u);
    }
    return ;
}

int lca(int32_t a, int32_t b) {
    if (dep[b] < dep[a]) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    int l = dep[b] - dep[a];
    for (int i = 0; i < MAX_K; i++) {
        if (l & (1 << i)) b = gas[b][i];
    }
    if (a == b) return a;
    for (int i = MAX_K - 1; i >= 0; i--) {
        if (gas[a][i] != gas[b][i]) a = gas[a][i], b = gas[b][i];
    }
    return gas[a][0];
}

int main() {
    int32_t N, M, a, b, x, y, z, point;
    scanf("%d %d", &N, &M);
    for (int32_t i = 1; i < N; i++) {
        scanf("%d %d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, 0);
    for (int32_t i = 0; i < M; i++) {
        scanf("%d %d %d", &x, &y, &z);
        if (dep[lca(x, y)] >= dep[lca(x, z)]) {
            if (dep[lca(x, y)] >= dep[lca(y, z)]) {
                point = lca(x, y);
            } else {
                point = lca(y, z);
            }
        } else {
            if (dep[lca(x, z)] >= dep[lca(y, z)]) {
                point = lca(x, z);
            } else {
                point = lca(y, z);
            }
        }
        printf("%d %d\n", point, dep[x] + dep[y] + dep[z] - dep[lca(x, y)] - dep[lca(x, z)] - dep[lca(y, z)]);
    }
}
