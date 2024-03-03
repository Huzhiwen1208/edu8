#include <bits/stdc++.h>
using namespace std;

#define INF 9999999

int graph[15][15];  // 有向图邻接矩阵

int main() {
    int vertexs, edges;
    cin >> vertexs >> edges;

    for (int i = 1; i <= vertexs; i++)
        for (int j = 1; j <= vertexs; j++)
            graph[i][j] = INF;

    int vertex_start, vertex_end, distance;
    for (int i = 0; i < edges; i++) {
        cin >> vertex_start >> vertex_end >> distance;
        graph[vertex_start][vertex_end] = distance;
    }

    for (int i = 1; i <= vertexs; i++) {
        for (int j = 1; j <= vertexs; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }

    return  0;
}