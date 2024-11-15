#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

int sq(const int x) {
	const int m = static_cast<int>(sqrt(x));
	for(int i = m-2; i <= m+2; i++) {
		if(x == i * i) {
			return 1;
		}
	}
	return 0;
}

int main()
{

}