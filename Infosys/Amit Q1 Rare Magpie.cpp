#include<bits/stdc++.h>
using namespace std;

int calc(int N, int M, vector<string> maze) {
    int n = N, m = M;
    vector<string> a = maze;
    vector<vector<bool>> seen(n, vector<bool>(m, false));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    pair<int, int> s, g;

    auto mark = [&](int i, int j, int di, int dj) {
        for (i += di, j += dj; i >= 0 && j >= 0 && i < n && j < m; i += di, j += dj) {
            if (a[i][j] == '#' || string("^v<>").find(a[i][j]) != string::npos) break;
            seen[i][j] = true;
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'S') s = {i, j};
            if (a[i][j] == 'G') g = {i, j};
        }
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (a[i][j] == '>') mark(i, j, 0, 1);
        if (a[i][j] == '<') mark(i, j, 0, -1);
        if (a[i][j] == 'v') mark(i, j, 1, 0);
        if (a[i][j] == '^') mark(i, j, -1, 0);
    }

    queue<tuple<int, int, int>> q;
    q.push({s.first, s.second, 0});
    vis[s.first][s.second] = true;

    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    while (!q.empty()) {
        auto [x, y, d] = q.front(); q.pop();
        if (make_pair(x, y) == g) return d;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny]) continue;
            if (a[nx][ny] == '#' || seen[nx][ny] || string("^v<>").find(a[nx][ny]) != string::npos) continue;
            vis[nx][ny] = true;
            q.push({nx, ny, d + 1});
        }
    }

    return -1;
}

int main() {
	int n, m; cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	auto ans = calc(n, m, a);
	cout << ans << endl;
}
