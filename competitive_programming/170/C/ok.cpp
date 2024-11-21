#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int maxn = 200010;
ll a[maxn];

int main()
{
	int n, k;
	cin >> n >> k;
	forn cin >> a[i];
	int ans =0;
	sort(a, a + n);
	for(int i = 0; i < n; i++) {
		int apport = 1;
		int different = 1;
		for(int j = i + 1; j < n; j++) {
			if(a[j] == a[j-1]) {
				apport++;
			} else if(different < k && a[j] == a[j-1] + 1) {
				different++;
				apport++;
			} else{break;}
		}
		ans = max(ans, apport);
	}
	cout << ans << endl;
}
