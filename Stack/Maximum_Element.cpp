#include <bits/stdc++.h>
using namespace std;

int main()
{
    int no_of_querry, querry_type, inserted_element, current_max = INT_MIN;
    cin >> no_of_querry;
    // first int for stack list, second to store the list of max from the stack
    stack<pair<int, int>> st;
    while (no_of_querry--) /* no_of_querry to 0 loop*/
    { 
        cin >> querry_type;
        switch (querry_type)
        {
        case 1: /* for inserting element */
            cin >> inserted_element;
            current_max = max(inserted_element, current_max);
            // storing the element in first of the pair and max in the second
            st.push(make_pair(inserted_element, current_max));
            break;
        case 2:
            st.pop();
            if (!st.empty())
                /* if stack is not empty then after pop() the second most element of the max list is current max  */
                current_max = st.top().second;
            else
                /* for empty stack current max will be INT_MIN */
                current_max = INT_MIN;
            break;
        case 3: /* for printing the current max value row wise */
            cout << current_max << endl;
        default:
            break;
        }
    }

    return 0;
}
