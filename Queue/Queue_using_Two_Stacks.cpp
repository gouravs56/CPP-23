#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> inputStk, outputStk;
    int Q;
    cin >> Q; /* no of Querry */

    while (Q--)
    {
        int querryType, element;
        cin >> querryType;

        if (querryType == 1) /* for insert/enqueue querry */
        {
            cin >> element;
            inputStk.push(element);
        }
        else /* for querry type 2&3 means dequeue and print there is some same logic for empty output stack */
        {
            if (outputStk.empty()) /* for empty output stack ,input stack's value would be shited into output stack until inputStk becomes empty */
            {
                while (!inputStk.empty())
                {
                    outputStk.push(inputStk.top());
                    inputStk.pop();
                }
            }
            if (!outputStk.empty())
            {
                if (querryType == 2)
                    outputStk.pop(); /* dequeue/pop in FIFO */
                if (querryType == 3)
                    cout << outputStk.top() << endl;
            }
        }
    }

    return 0;
}
