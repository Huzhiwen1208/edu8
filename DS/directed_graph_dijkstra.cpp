#include <bits/stdc++.h>
using namespace std;

#define INF 9999999

int vertexs, edges;
int graph[15][15];  // 有向图邻接矩阵

/**
 * 求解从vertex顶点出发的单源最短路径。
*/
void Dijkstra(int vertex) {
    int set[15];
    int distance[15];
    // 1. 初始化
    for (int i = 1; i <= vertexs; i++) {
        set[i] = 0;
        distance[i] = INF;

        if (graph[vertex][i] != INF) {  // 更新与源顶点相邻的顶点Distance值
            distance[i] = graph[vertex][i];
        }
    }

    set[vertex] = 1; // 源顶点入集合
    distance[vertex] = 0;

    // 2. 寻找一个距离当前顶点最短的相邻顶点
    while (1) {
        printf("vertex: %d\n", vertex);
        for (int i = 1; i <= vertexs; i++)
            cout << distance[i] << ' ';
        cout << endl;
        int min = INF;
        int v;
        for (int i = 1; i <= vertexs; i++) {
            if (set[i] == 0 && i != vertex && graph[vertex][i] < min) {
                min = graph[vertex][i];
                v = i;
            }
        }

        printf("找到下一个顶点：[%d, %d]\n", vertex, v);

        if (min == INF) break; //未找到，程序退出
        // 3. 找到了，入集合并更新
        set[v] = 1;
        for (int i = 1; i <= vertexs; i++) {
            if (set[i] == 0 && i != v && distance[v] + graph[v][i] < distance[i]) {
                distance[i] = distance[v] + graph[v][i];
            }
        }

        // 变更源顶点
        vertex = v;
    }

    // 最终结果打印
    printf("[");
    for (int i = 1; i <= vertexs; i++) {
        if (distance[i] == INF)
            cout << "INF";
        else
            cout << distance[i];
        printf("%s", i == vertexs ? "": ",");
    }
    printf("]");
    cout << endl;
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

    Dijkstra(1);

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