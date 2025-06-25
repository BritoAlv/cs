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

int ans(int l1, int b1, int l2, int b2, int l3, int b3)
{
    if (l1 == l2 && l2 == l3)
    {
        if (b2 + b3 + b1 == l1)
        {
            return 1;
        }
    }
    if (l2 + l3 == l1 && b2 == b3 && b1 + b2 == l1)
    {
        return 1;
    }
    return 0;
}

void Solve()
{
    int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if(ans(l1, b1, l2, b2, l3, b3) || ans(b1, l1, b2, l2, b3, l3))
    {
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
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
