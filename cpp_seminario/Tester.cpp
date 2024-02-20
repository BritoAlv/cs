#include "Seminario.cpp"
#include <bits/stdc++.h>

// je m appelle Alvaro j ai 21 ans.

using namespace std;

void RealSolve()
{
    int n;
    cin >> n;
    vector<int> my_list;
    while (n > 0)
    {
        char a;
        int t;
        cin >> a >> t;
        if (a == 'i')
        {
            my_list.push_back(t);
        }
        else if (a == 'd')
        {
            int j = 0;
            for (; j < my_list.size(); j++)
            {
                if (my_list[j] == t)
                {
                    break;
                }
            }
            vector<int> new_list;
            for (int l = 0; l < j; l++)
            {
                new_list.push_back(my_list[l]);
            }
            for (int l = j + 1; l < my_list.size(); l++)
            {
                new_list.push_back(my_list[l]);
            }
            my_list = new_list;
        }
        n--;
    }
    for (auto x : my_list)
    {
        cout << x << ' ';
    }
    cout << endl;
    return;
}

void Solve()
{
    int n;
    cin >> n;
    Seminario::DLL<int> my_dll;
    while (n > 0)
    {
        char a;
        int t;
        cin >> a >> t;
        if (a == 'i')
        {
            my_dll.pb({t});
        }
        else if (a == 'd')
        {
            my_dll.rm({t});
        }
        n--;
    }
    my_dll.watch();
    return;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    while (test_cases > 0)
    {
        // RealSolve();
        Solve();
        test_cases--;
    }
    return 0;
}
