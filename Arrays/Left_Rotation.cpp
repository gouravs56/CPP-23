#include <bits/stdc++.h>
using namespace std;

vector<int> left_rotate(vector<int> V, int d)
{
    vector<int> result;
    for (auto it = V.begin() + d; it != V.end(); it++)
    {
        result.emplace_back(*it); /* inserting the value of this position */
    }
    for (auto it = V.begin(); it != V.begin() + d; it++)
    {
        result.emplace_back( *it );
    }
    return result;
}

int main()
{
    system("cls");
    int n, d;
    cin >> n >> d;
    vector<int> V(n); /* initializing a n size vector V, not an array*/

    for (int i = 0; i < n; i++)
    {
        cin >> V[i];
    }

    vector<int> result = left_rotate(V, d);
    
    for (int i = 0; i < n; i++)
    {
        cout << result[i] <<" ";
    }
    return 0;
}