// Referse a set of number in Array
#include <bits/stdc++.h>
using namespace std;

vector<int> reverseArray(vector<int> arr)
{
    int temp = 0;
    int n = arr.size();
    for (int i = 0; i < n / 2; ++i)
    {
        temp = arr[n - i - 1]; /* temp storing from the last value of the vector */
       
        arr[n - i - 1] = arr[i]; /* ininial and ending value swaping... */
        arr[i] = temp;
    }
    return arr;
}
int main()
{
    system("cls");
    int n;
    cin >> n;
    vector<int> arr(n);
    // taking input of the array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> result = reverseArray(arr);
    // output of the array
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}


