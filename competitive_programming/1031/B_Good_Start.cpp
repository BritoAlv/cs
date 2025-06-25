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

int w, h, a, b;
int solve(int x1, int y1, int x2, int y2)
{
    if (x1 <= x2 && x1 + a <= x2)
    {
        int spacing = x2 - (x1 + a);
        if (spacing % a == 0)
        {
            return 1;
        }
    }
    if (y1 <= y2 && y1 + b <= y2)
    {
        int spacing = y2 - (y1 + b);
        if (spacing % b == 0)
        {
            return 1;
        }
    }
    return 0;
}

void Solve()
{
    cin >> w >> h >> a >> b;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int flag = (solve(x1, y1, x2, y2) || solve(x2, y2, x1, y1));
    cout << (flag ? "Yes" : "No") << endl;
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
