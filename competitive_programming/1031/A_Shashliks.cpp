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

int opt(int total, int less_than, int cost){
    int ans = 0;
    if (total < less_than)
        return 0;
    ans += (total - less_than) / cost + 1;
    
    return ans;}

    void Solve()
    {
        int k, a, b, x, y;
        cin >> k >> a >> b >> x >> y;
        int option1 = opt(k, max(a, b), x);
        int option2 = opt(k, max(a, b), y);
        int rem1 = k - x * option1;
        int rem2 = k - y * option2;
        vector<int> candidates;
        if (min(a, b) == a)
        {
            candidates.push_back(option1 + opt(rem1, a, x));
            candidates.push_back(option2 + opt(rem2, a, x));
        }
        if (min(a, b) == b)
        {
            candidates.push_back(option1 + opt(rem1, b, y));
            candidates.push_back(option2 + opt(rem2, b, y));
        }
        sort(candidates.begin(), candidates.end());
        cout << candidates.back() << endl;
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
