#include <bits/stdc++.h>

#define doo(a) for(int i_i = 0; i_i < a; i_i++) 
#define fori(a,b) for (int i = a; i <= b; i++)
#define forj(a,b) for (int j = a; j <= b; j++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

vector<vector<char>> a;
int n, m;
map<pi, int> visited;

int good(const int i, const int j) {
	if (i == 0 && a[i][j] == 'U') {
		return 1;
	}
	if (j == 0 && a[i][j] == 'L') {
		return 1;
	}
	if (i == n - 1 && a[i][j] == 'D') {
		return 1;
	}
	if (j == m-1 && a[i][j] == 'R') {
		return 1;
	}
	return 0;
}


map<char, pair<int, int>> D;

int inside(const int x, const int y) {
	return (x >= 0 && x <= n-1 && y >= 0 && y <= m-1);
}

pair<vector<pi>, vector<pi>> neighbours(int i, int j) {
	vector<pi> in;
	vector<pi> out;
	for (const auto key : D ) {
		int dx = i + key.second.first;
		int dy = j + key.second.second;
		if (inside(dx, dy) && a[dx][dy] != '?') {
			if (i == dx + D[a[dx][dy]].first && j == dy + D[a[dx][dy]].second) {
				in.push_back({dx, dy});
			} else {
				out.push_back({dx, dy});
			}
		} else if (inside(dx, dy) && a[dx][dy] == '?') {
			in.push_back({dx, dy});
		}
	}
	return {in, out};
}
int bad(const int i, const int j) {
	if (a[i][j] != '?') return 0;
	const auto ne = neighbours(i, j);
	if (!ne.first.empty()) {
		return 0;
	}
	for (auto out : ne.second) {
		if (!visited[out]) {
			return 0;
		}
	}
	return 1;
}

void dfs(pi A) {
	if (a[A.first][A.second] == '?') {
		return;
	}
	visited[A] = 1;
	auto ne = neighbours(A.first, A.second);
	for (auto z : ne.first) {
		if (!visited[z]) {
			dfs(z);
		}
	}
}

void solve()
{
	cin >> n >> m;
	a = vector<vector<char>>(n, vector<char>(m));
	visited = map<pi, int>();
	fori(0, n-1) forj(0,m-1) cin >> a[i][j], visited[{i, j}] = 0;
	fori(0, n-1) forj(0, m-1) {
		if (good(i, j) && !visited[{i, j}]) {
			dfs({i, j});
		}
	}
	int ans = 0;
	int bads_all = 0;
	int bads_good =0;
	fori(0, n-1) forj(0, m-1) bads_all += !visited[{i ,j}];
	// now I have to remove all the cells that are marked with ? and for any direction assignment
	// still allows escape.
	fori(0, n-1) forj(0, m-1) bads_good += bad(i, j);
	cout << bads_all - bads_good << endl;
}

int main()
{
	D['U'] = {-1, 0};
	D['D'] = {1, 0};
	D['L'] = {0, -1};
	D['R'] = {0, 1};
	int t = 1;
	cin >> t;
	while(t--) solve();	
}