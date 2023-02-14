#include <bits/stdc++.h>

using namespace std;

int hourglassSum(vector<vector<int>> arr)
{
    int result = INT_MIN;   /* INT_MIN is equal to -2147483647 which is the smallest value that can be stored in a 32-bit int variable. */

    for (int row = 0; row <= 3; row++)
    {
        for (int col = 0; col <= 3; col++)
        {
                /* here we indexing the 1st hourglass with row=0,col=0 */
            int sum_of_a_hourglass = arr[row][col] + arr[row][col + 1] + arr[row][col + 2] 
                                                    + arr[row + 1][col + 1]
                                  + arr[row + 2][col] + arr[row + 2][col + 1] + arr[row + 2][col + 2];

            result = max(result, sum_of_a_hourglass);  /* max fuction for getting the max hourglass */
        }
    }
    return result;
}

int main()
{

    vector<vector<int>> arr(6, vector<int>(6));
    // 6 row | each row with int vector size of 6 means the no of col 6

    /*  more explaination: The 'arr' vector is a two-dimensional vector, where each element of the vector represents a single row in the 'arr'. The size of each std::vector<int> element represents the number of columns in that row. */

    for (int row = 0; row < 6; row++)
    {
        for (int col = 0; col < 6; col++)
        {
            cin >> arr[row][col];
            /* Here we dont need push_back coz its a fixed  vector if we need more value that his fixed size then we should use push_back */
        }
    }

    int result = hourglassSum(arr);

    cout << result << "\n";

    return 0;
}
