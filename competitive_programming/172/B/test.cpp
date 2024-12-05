#include <bits/stdc++.h>

#define doo(a) for (int i_i = 0; i_i < a; i_i++)
#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> A;
    vi q;
    fori(0, n - 1)
    {
        int x;
        cin >> x;
        A[x]++;
    }
    int alice = 1;
    map<int, int> collected;
	fori(1, n){
		forj(1, n){
			if(A[j] >= i)
			{
                q.push_back(j);
            }
        }
	}
	for(int i =0; i < n; i+= 2){
        collected[q[i]]++;
    }
    int ans = collected.size();
	for(auto z : collected){
        ans += (z.second == A[z.first]);
    }
    cout << ans << endl;
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}