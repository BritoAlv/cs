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

class dsu {
	struct node {
		//int rank;
		int parent;
		int data; // optional if want to store any data in each node
		int size; // size of the set it belongs to
	};

	vector<node> store;

public:
	int number_sets = 0;
	void makeset(int size) {
		number_sets = size;
		store.resize(size + 1); // if indexing is from 1
		for (int i = 0; i <= size; i++) {
			//store[i].rank = 0;
			store[i].parent = i;
			store[i].size = 1;
			store[i].data = i;
		}
	}

	int find(int ele) {
		stack<int> elements;
		while (store[ele].parent != ele) {
			elements.push(ele);
			ele = store[ele].parent;
		}
		while (!elements.empty()) {
			// applying path compression
			store[elements.top()].parent = ele;
			elements.pop();
		}
		return ele;
	}

	void unionset(int a, int b) {
		int aset = find(a);
		int bset = find(b);

		if (aset == bset) return;
		else {
			number_sets--;
			int root = (store[aset].size > store[bset].size) ? aset : bset;
			store[aset].parent = store[bset].parent = root;
			int temp = store[aset].size;
			store[aset].size += store[bset].size;
			store[bset].size += temp;
		}
	}
};

void solve() {
	int n, m;
	cin >> n >> m;
	dsu DSU;
	DSU.makeset(n);
	fori(0, m-1) {
		int ai, di, ki;
		cin >> ai >> di >> ki;
		int cr = ai;
		doo(ki)
		{
			DSU.unionset(cr, cr + di);
			cr += di;
		}
	}
	cout << DSU.number_sets << endl;
}

int main() {
	int t = 1;
	//cin >> t;
	while (t--) solve();
}