// Problem: B. Vaccination
// Contest: Codeforces - Nebius Welcome Round (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1804/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Math Proof: vaccination, interval counting
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
using namespace std;

int test_cases;

void Solve()
{
    int number_patients;
    int number_dosis;
    int vaccine_time;
    int paccient_time;
    cin >> number_patients >> number_dosis >> vaccine_time >> paccient_time;
    int a[number_patients];
    for (int i = 0; i < number_patients; i++)
    {
        cin >> a[i];
    }

    int answer = 1;

    int index = 0;
    int start_time = a[index] + paccient_time;
    int end_time = start_time + vaccine_time;
    int vacunated = 0;
    while (index < number_patients)
    {
        if (vacunated == number_dosis || (end_time < a[index]))
        {
            start_time = a[index] + paccient_time;
            end_time = start_time + vaccine_time;
            vacunated = 1;
            answer++;
        }
        else
        {
            vacunated++;
        }
        index++;
    }

    cout << answer << endl;
    return;
}

int main()
{
    cin >> test_cases;
    while (test_cases > 0)
    {
        Solve();
        test_cases--;
    }
    return 0;
}
