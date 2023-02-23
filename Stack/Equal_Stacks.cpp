#include <bits/stdc++.h>
using namespace std;

int Equal_Stack(vector<int> cylinder_heights_1, vector<int> cylinder_heights_2, vector<int> cylinder_heights_3)
{
    stack<int> s1, s2, s3;
    int s1Height = 0, s2Height = 0, s3Height = 0;

    // storing the value in such way that top of the stack store sum of total element
    for (int i = cylinder_heights_1.size() - 1; i >= 0; i--)
    {
        s1Height += cylinder_heights_1[i];
        s1.push(s1Height);
    }

    for (int i = cylinder_heights_2.size() - 1; i >= 0; i--)
    {
        s2Height += cylinder_heights_2[i];
        s2.push(s2Height);
    }

    for (int i = cylinder_heights_3.size() - 1; i >= 0; i--)
    {
        s3Height += cylinder_heights_3[i];
        s3.push(s3Height);
    }

    while (1)
    {
        // output for failing to equal the stack
        if (s1.empty() || s2.empty() || s3.empty())
            return 0;

        // setting sHeight as top of s stack
        s1Height = s1.top();
        s2Height = s2.top();
        s3Height = s3.top();

        // for equal stack height
        if (s1Height == s2Height && s1Height == s3Height)
            return s1Height;

        // removing the top element from greatest height stack
        if (s1Height >= s2Height && s1Height >= s3Height)
            s1.pop();
        else if (s2Height >= s1Height && s2Height >= s3Height)
            s2.pop();
        else
            s3.pop();
    }
}
int main()
{
    int n1, n2, n3; // no of cylinders in stack 1 , 2 & 3
    cin >> n1 >> n2 >> n3;

    vector<int> cylinder_heights_1(n1), cylinder_heights_2(n2), cylinder_heights_3(n3);

    // taking inputs
    for (int i = 0; i < n1; i++)
        cin >> cylinder_heights_1[i];

    for (int i = 0; i < n2; i++)
        cin >> cylinder_heights_2[i];

    for (int i = 0; i < n3; i++)
        cin >> cylinder_heights_3[i];

    int result = Equal_Stack(cylinder_heights_1, cylinder_heights_2, cylinder_heights_3);
    cout << result;
    return 0;
}