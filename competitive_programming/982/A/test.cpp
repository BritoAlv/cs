#include <bits/stdc++.h>

#define forn for (int i = 0; i < n; i++)
#define endl '\n'
#define wp ' '
#define ll long long
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pi> values(n);
    forn
    {
        cin >> values[i].first >> values[i].second;
    }
    sort(values.begin(), values.end(), greater<pi>());
    int max_x = values[0].first;
    int cx = values[0].first;
    int cy = values[0].second;
    int sum = max_x + cy;
    forn
    {
        if(values[i].second >  cy) {
            sum += cx - values[i].first;
            sum += values[i].second - cy;
            cx = values[i].first;
            cy = values[i].second;
        }
    }
    sum += cx + cy;
    cout << sum << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) solve();
}