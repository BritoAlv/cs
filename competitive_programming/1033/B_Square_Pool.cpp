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
	int n, s;
	cin >> n >> s;
    vector<pi> options = vector<pi>();
    options.push_back(make_pair(0, 0));
    options.push_back(make_pair(0, s));
    options.push_back(make_pair(s, 0));
    options.push_back(make_pair(s, s));
    int ans = 0;
    fori(0, n - 1)
    {
        int dx, dy, x, y;
        cin >> dx >> dy >> x >> y;
        for(auto opt : options)
        {
            int dp1 = x - opt.first;
            int dp2 = y - opt.second;
            dp1 /= dx;
            dp2 /= dy;
            if(dp1 == dp2){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
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
