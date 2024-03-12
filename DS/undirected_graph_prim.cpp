#include <bits/stdc++.h>
using namespace std;

#define INF 9999999

int vertexs, edges;
int graph[15][15];  // 无向图邻接矩阵

int prim() {
    int lowest[15];
    int sum = 0;

    // 1.初始化
    for (int i = 1; i <= vertexs; i++) {
        lowest[i] = INF;
        if (graph[1][i] != INF) {
            lowest[i] = graph[1][i];
        }
    }

    lowest[1] = 0; // 源顶点v1进树
    // 2. 找到距离树最近的顶点，也即是lowest值最小的顶点
    while (1) {
        int min = INF;
        int v;
        for (int i = 1; i <= vertexs; i++) {
            if (lowest[i] != 0 && lowest[i] < min) {  // 如果该顶点不在树中，并且最小
                min = lowest[i];
                v = i;
            }
        }

        if (min == INF) break;  // 未找到满足条件的顶点，算法退出

        // 3. 进树并更新相邻节点的lowest
        sum += lowest[v];
        lowest[v] = 0;

        for (int i = 1; i <= vertexs; i++) {
            if (lowest[i] && lowest[i] > graph[v][i]) {
                lowest[i] = graph[v][i];
            }
        }
    }

    return sum;
}

int main() {
    cin >> vertexs >> edges;

    for (int i = 1; i <= vertexs; i++)
        for (int j = 1; j <= vertexs; j++)
            graph[i][j] = INF;

    int vertex_start, vertex_end, distance;
    for (int i = 0; i < edges; i++) {
        cin >> vertex_start >> vertex_end >> distance;
        graph[vertex_start][vertex_end] = distance;
        graph[vertex_end][vertex_start] = distance;
    }

    cout << prim() << endl;

    return  0;
}
/* 我们的输入是：
    6 8
    1 3 10
    2 3 5
    1 6 100
    1 5 30
    3 4 50
    5 4 20
    4 6 10
    5 6 60
*/