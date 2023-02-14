#include<bits/stdc++.h>
using namespace std;


vector<int> dynamicArray(int n, vector<vector<int>> queries)
{
    vector<vector<int>> seqList(n);
    vector<int> ans;
    int lastAnswer = 0;
    for (int i = 0; i < queries.size(); i++)
    {
                                    /* As per input format */
     int queryType = queries[i][0]; /* First column = Query Type  */
             int x = queries[i][1]; /* Second column = X  */
             int y = queries[i][2]; /* Third column = Y  */

        // [idx] = (x XOR lastAnswer) % n
        int index = (x ^ lastAnswer) % n;

        if (queryType == 1)
        // Query type 1: Appends the integer 'y' to the seqList at index ('idx')
        {
            seqList[index].push_back(y);
        }
        else if (queryType == 2)
        // Query type 2: Assigns the value 'y' to the seqList at index ('idx')
        {
            int size = seqList[index].size();
            lastAnswer = seqList[index][y % size]; /* 'y % size' is the position of the element that we want to retrieve in the seqlist...  */
            ans.push_back(lastAnswer);        /* modulo fn returns remainder, using this ensures that y % size is always a valid index in the seqlist */
        }
    }
    return ans;
}

int main()
{
    // n is size of seqList and q is no of queries in the program
    int n, q;
    cin >> n >> q;
    // initializing 2d vector where column = 3 and row is dynamic 
    vector<vector<int>> queries(q, vector<int>(3));
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> queries[i][j];
        }
    }
    // calling that dynamicArray fn
    vector<int> result = dynamicArray(n, queries);
    // printing result
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}