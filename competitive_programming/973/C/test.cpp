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

int do_query(string &s) {
	cout << "? " << s << endl;
	cout.flush();
	int x;
	cin >> x;
	return x;
}

int n;

string guessS( string &prev) {
	if (prev.size() == n) {
		return prev;
	}
	string next2 = prev + "0";
	if (do_query(next2)) {
		return guessS(next2);
	}
	next2[next2.size()-1] = '1';
	return guessS(next2);
}

string guessP( string &prev) {
	if (prev.size() == n) {
		return prev;
	}
	string next2 = "0" + prev;
	if (do_query(next2)) {
		return guessP(next2);
	}
	next2[0] = '1';
	if (do_query(next2)) {
		return guessP(next2);
	}
	return guessS(prev);
}

void solve()
{
	cin >> n;
	string x = "";
	string start = guessP(x);
	cout << "! " << start << endl;
	cout.flush();
}

int main()
{
	int t = 1;
	cin >> t;
	while(t--) solve();	
}
