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
    vector<vector<int>> cols(n, vector<int>());
    fori(0, n-1){
        cols[a[i] - 1].push_back(i);
    }
    fori(0, n-1){
        queue<int> odd;
        queue<int> even;
        forj(0, (int)cols[i].size() - 1){
            int check = cols[i][j];
            if (check % 2 == 1)
            {
                if(odd.size() == 0 || odd.front() % 2 == 1 || odd.front() + 1 == check){
                    odd.push(check);
                }
                if(even.size() > 0 && even.front() % 2 == 0){
                    even.push(check);
                }
            }
            else
            {
                if(even.size() == 0 || even.front() % 2 == 0){
                    even.push(check);
                }
                if(odd.size() > 0 && odd.front() % 2 == 1){
                    odd.push(check);
                }
            }
        }
        cout << max(odd.size(), even.size()) << wp;
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
