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

int ans;
vi dp;
vi visited;
vector<vi> tree;

void recur_solve( int v ){
    visited[v] = 1;
    priority_queue<int> values;
    for(auto z : tree[v]){
		if(!visited[z]) {
			recur_solve(z);
            values.push(dp[z]);
        }
    }
    ans = max((int)tree[v].size(), ans);
	if(values.size() > 0){
        int big = values.top();
        ans = max(ans, (int)tree[v].size() - 1 + big);
    }
	if(values.size() > 1){
        int big1 = values.top();
        values.pop();
        int big2 = values.top();
        values.push(big1);
        ans = max(ans, big1 + big2 + (int)tree[v].size() - 2);
    }
    dp[v] = tree[v].size() - 1;
    if (values.size() > 0)
    {
        int big1 = values.top();
        dp[v] = max(dp[v], big1 + (int)tree[v].size() - 2);
    }
    //printf("dp[%d] = %d\n", v, dp[v]);
}

void solve()
{
	int n;
	cin >> n;
    dp = vi(n, 0);
    visited = vi(n, 0);
    ans = 1;
    tree = vector<vi>(n, vi());
	fori(0, n-2){
        int a, b;
        cin >> a >> b;
        a--, b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    recur_solve(0);
    cout << ans << endl;
}

int main()
{
	int t = 1;
    cin >> t;
    while (t--)
        solve();
}
