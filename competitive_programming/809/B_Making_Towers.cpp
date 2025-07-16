// je m appelle Alvaro Brito. J ai 22 ans.
#include <bits/stdc++.h>

#define fori(a, b) for (int i = a; i <= b; i++)
#define forj(a, b) for (int j = a; j <= b; j++)
#define wp " "
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define ll long long
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>

template <typename T> void print(const T &container)
{
    for (const auto &element : container)
    {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

template <typename K, typename V> void print(const std::map<K, V> &m)
{
    for (const auto &[key, value] : m)
    {
        std::cout << key << ": " << value << "\n";
    }
}

int test_cases;
using namespace std;

void Solve()
{
	int n;
	cin >> n;
	vl a(n);
	fori(0, n-1) cin >> a[i];
    vector<vi> dp(n, vi());
    fori(0, n-1){
        dp[a[i] - 1].push_back(i);
    }
    fori(0, n-1){
        int last_even = -1;
        int last_odd = -1;
        vi dp2((int)dp[i].size(), 0);
        int maxx = 0;
        forj(0, (int)dp[i].size() - 1)
        {
            int cur = dp[i][j];
            if(cur % 2 == 0){
                if(last_odd != -1){
                    dp2[j] = 1 + dp2[last_odd];
                } else{
                    dp2[j] = 1;
                }
                last_even = j;
            } else{
                if(last_even != -1){
                    dp2[j] = 1 + dp2[last_even];
                } else{
                    dp2[j] = 1;
                }
                last_odd = j;
            }
            maxx = max(maxx, dp2[j]);
        }
        cout << maxx << wp;
    }
    cout << endl;
}

int main()
{
    cin >> test_cases;
    while (test_cases--)
    {
        Solve();
    }
    return 0;
}