#include <bits/stdc++.h>

#define doo(a) for(int i_i = 0; i_i < a; i_i++) 
#define fori(a,b) for (int i = a; i <= b; i++)
#define forj(a,b) for (int j = a; j <= b; j++)
#define forn  for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int maxn = 600010;
ll a[maxn];

void solve()
{
	int n;
	cin >> n;
	set<pi> A;
	forn{
	int x;
	cin >> x;
	A.insert({x, i});
	}
	while (A.size() >= 2) {
		auto top1 = A.begin();
		A.erase(top1);
		auto top2 = A.begin();
		A.erase(top2);
		A.insert( {(top1->first + top2->first)/2, top1->second });
	}
	cout << A.begin()->first << endl;

}

int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}