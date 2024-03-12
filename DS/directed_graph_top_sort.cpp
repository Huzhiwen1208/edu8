#include <bits/stdc++.h>
using namespace std;

#define INF 9999999

int vertexs, edges;
int graph[15][15];  // 有向图邻接矩阵

void top_sort() {
    int indegree[15];
    int visited[15];

    // 1. 初始化indegree 与 visited
    for (int i = 1; i <= vertexs; i++) {
        visited[i] = 0;
        indegree[i] = 0;
    }

    for (int i = 1; i <= vertexs; i++)
        for (int j = 1; j <= vertexs; j++)
            if (graph[i][j] != INF) 
                // i-->j的一条边
                indegree[j] ++;
    
    // 2. 找到未被访问过且入度为0的顶点
    while (1) {
        int v = -1;
        for (int i = 1; i <= vertexs; i++) {
            if (visited[i] == 0 && indegree[i] == 0) {
                v = i;
                break;
            }
        }

        if (v == -1) break; // 没找到符合条件的顶点，退出
        
        // 3. 打印并且更新与v相邻的顶点Indegree值
        cout << v << ' ';
        visited[v] = 1;

        for (int i = 1; i <= vertexs; i++)
            if (visited[i] == 0 && graph[v][i] != INF)
                indegree[i] --;
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

    top_sort();

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