#include<bits/stdc++.h>
using namespace std;

typedef struct point {
    int x, y;
} point;

char cheese[10][10];
int n, m;
int dirx[2] = {0, 1};
int diry[2] = {1, 0};
int visited[10][10] = {0};
bool isValid(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= m;
}

void dfs(int x, int y, vector<point>& path) {
    if (x == n && y == m) {
        cout<<"[1,1]";
        for (point item : path) {
            cout<<"->["<<to_string(item.x)<<","<<to_string(item.y)<<"]";
        }
        cout<<endl;
        return;
    }

    for (int i = 0; i < 2; i++) {
        int nx = x + dirx[i];
        int ny = y + diry[i];
        if (isValid(nx, ny) && visited[nx][ny] == 0) {
            visited[nx][ny] = 1;
            path.push_back({nx,ny});
            dfs(nx, ny, path);
            visited[nx][ny] = 0;
            path.pop_back();
        }
    }
}

int main() {
	cin>>n>>m;
    visited[1][1] = 1;
    vector<point> path;
    dfs(1, 1, path);
    return 0;
}