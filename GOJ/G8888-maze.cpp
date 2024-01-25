#include<bits/stdc++.h>
using namespace std;


int n, m, res;
typedef struct point {
    int x, y;
} point;

char g[15][15];
int dirx[4] = {0,1,0,-1};
int diry[4] = {1,0,-1,0};
int visited[15][15] = {0};
bool isValid(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= m;
}

void dfs(int x, int y, vector<point>& path) {
    if (x == n && y == m) {
        cout<<res++<<":1,1";
        for (point item : path) {
            cout<<"->"<<to_string(item.x)<<","<<to_string(item.y);
        }
        cout<<endl;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dirx[i];
        int ny = y + diry[i];
        if (isValid(nx, ny) && visited[nx][ny] == 0 && g[nx][ny] != '#') {
            visited[nx][ny] = 1;
            path.push_back({nx,ny});
            dfs(nx, ny, path);
            visited[nx][ny] = 0;
            path.pop_back();
        }
    }
}

int main() {
    res = 1;
	cin>>n>>m;
    cin.get();
    string val;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin>>g[i][j];
        }
    }

    visited[1][1] = 1;
    vector<point> path;
    dfs(1, 1, path);
    return 0;
}