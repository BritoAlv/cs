// Problem: C. Minimizing the Sum
// Contest: Codeforces - Educational Codeforces Round 165 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1969/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;
vector<int> arr;
class dsu
{
    struct node
    {
        // int rank;
        int parent;
        int data; // optional if want to store any data in each node
        int size; // size of the set it belongs to
    };

    vector<node> store;

  public:
    void makeset(int size)
    {
        store.resize(size + 1); // if indexing is from 1
        for (int i = 0; i <= size; i++)
        {
            // store[i].rank = 0;
            store[i].parent = i;
            store[i].size = 1;
            store[i].data = i;
        }
    }

    int find(int ele)
    {
        stack<int> elements;
        while (store[ele].parent != ele)
        {
            elements.push(ele);
            ele = store[ele].parent;
        }
        while (!elements.empty())
        { // applying path compression
            store[elements.top()].parent = ele;
            elements.pop();
        }
        return ele;
    }

    void unionset(int a, int b)
    {
        int aset = find(a);
        int bset = find(b);

        if (aset != bset)
        {
            int root = (store[aset].size > store[bset].size) ? aset : bset;
            store[aset].parent = store[bset].parent = root;
            int temp = store[aset].size;
            store[aset].size += store[bset].size;
            store[bset].size += temp;
        }

        int pr = find(a);
        int minn = -1;
        for (int i = 0; i < arr.sz; i++)
        {
            if (find(i) == pr)
            {
                if (minn == -1 || minn > arr[i])
                {
                    minn = arr[i];
                }
            }
        }
        for (int i = 0; i < arr.sz; i++)
        {
            if (find(i) == pr)
            {
                arr[i] = minn;
            }
        }
    }
};

void Solve()
{
    int n, k;
    cin >> n >> k;
    arr = vector<int>(n);
    forn
    {
        cin >> arr[i];
    }
    dsu b;
    b.makeset(n);
    for (int i = 0; i < k && n > 1; i++)
    {
        vector<pi> diferences;
        for (int j = 0; j < n - 1; j++)
        {
            diferences.pb({abs(arr[j] - arr[j + 1]), max(arr[j], arr[j + 1])});
        }
        sort(diferences.begin(), diferences.end());
        reverse(diferences.begin(), diferences.end());
        b.unionset(diferences[0].second, diferences[0].second + 1);
    }
    ull ans = 0;
    forn
    {
        ans += arr[i];
    }
    cout << ans << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
