#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    int vertex;
    int distance;
} Node;

vector<vector<Node>> graph;  // 有向图邻接表

int main() {
    int vertexs, edges;
    cin >> vertexs >> edges;

    for (int i = 0; i <= vertexs; i++) {
        vector<Node> empty;
        graph.push_back(empty);
    }

    int vertex_start, vertex_end, distance;
    for (int i = 0; i < edges; i++) {
        cin >> vertex_start >> vertex_end >> distance;
        Node n = {vertex_end, distance};
        graph[vertex_start].push_back(n);
    }

    for (int i = 1; i <= vertexs; i++) {
        printf("[V%d]", i);
        for (int j = 0; j < graph[i].size(); j++) {
            printf("->[V%d, %d]", graph[i][j].vertex, graph[i][j].distance);
        }
        cout << endl;
    }

    return  0;
}