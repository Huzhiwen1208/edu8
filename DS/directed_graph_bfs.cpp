#include <bits/stdc++.h>
using namespace std;

#define INF 9999999

int vertexs, edges;
int graph[15][15];  // 有向图邻接矩阵
bool visited[15]; // 顶点访问标记位

// 从某一顶点开始，进行一次广度优先遍历
void bfs(int vertex) {
    queue<int> q; // 队列
    visited[vertex] = 1;
    q.push(vertex);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int u = q.front();
            q.pop();

            cout << u << ' ';
            for (int i = 1; i <= vertexs; i++) {
                if (visited[i] == 0 && graph[u][i] != INF) {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
}

void BFS() {
    // 如果是连通图，则只需要一次bfs
    for (int i = 1; i <= vertexs; i++) {
        if (visited[i] == 0)
            bfs(i);
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
    }

    BFS();

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