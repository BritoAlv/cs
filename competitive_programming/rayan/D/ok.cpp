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

vector<pi > ops;
vi a;
int n;

void solve() {
	ops = vector<pi >();
	cin >> n;
	a = vi(n);
    int sum = 0;
    set<int> pos2;
	set<int> pos1;
	fori(0, n-1) {
		cin >> a[i];
		sum += a[i];
		if (a[i] > 0 && a[i] == 2) {
			pos2.insert(i);
		}
		if (a[i] > 0 && a[i] == 1) {
			pos1.insert(i);
		}
	}

	auto use = [&sum, &pos1, &pos2] (int i, int use) {
		sum--;
		a[i]++;
		if (use == 1) {
			int top = *pos1.begin();
			pos1.erase(pos1.begin());
			a[top]--;
			ops.push_back({i+1, top+1});
		} else {
			int top = *pos2.begin();
			pos2.erase(pos2.begin());
			a[top]--;
			pos1.insert(top);
			ops.push_back({i+1, top+1});
		}
	};

    for (int i = n - 1; i >= 0; i--)
    {
        int to_r = a[i];
		if (sum > i + 1) {
			// element at position i, should necessarily be a two.
			while (a[i] != 2) {
				use(i, a[i] + 1);
			}
		} else{
			// at this point only care about ordering.
			if ( a[i] == 0 && (!pos1.empty() && *pos1.begin() < i)) {
				use(i, 1);
			}
			if ( a[i] == 1 && (!pos2.empty() && *pos2.begin() < i)) {
				use(i, 2);
			}
		}
		sum -= to_r;
		if (sum == 0) {
			break;
		}
    }
    cout << ops.size() << endl;
	for (const auto z: ops) {
		cout << z.first << wp << z.second << endl;
	}
}

int main() {
	int t = 1;
	cin >> t;
	while (t--) solve();
}
