#include <bits/stdc++.h>
using namespace std;

#define INF 9999999

int vertexs, edges;
int graph[15][15];  // 无向图邻接矩阵
bool visited[15]; // 顶点访问标记位

// 从该图的vertex顶点出发开始遍历，如果是连通的，则只需要执行一次。
void dfs(int vertex) {
    printf("We visit vertex: [%d]\n", vertex);
    for (int i = 1; i <= vertexs; i++) {
        if (visited[i] == false && i != vertex && graph[vertex][i] != INF) {
            // 找到该顶点的下一个顶点: 未被访问过且存在vertex->i的路径
            visited[i] = true;
            dfs(i);
        }
    }
}

// 遍历图
void DFS() {
    for (int i = 0; i < 15; i++) {
        visited[i] = false;
    }

    for (int i = 1; i <= vertexs; i++) {
        if (visited[i] == false) {
            visited[i] = true;
            dfs(i);
        }
    }
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

    DFS();

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