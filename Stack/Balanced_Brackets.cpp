#include <bits/stdc++.h>
using namespace std;

// setting an unorderd map globally with brackets and value for not using multiple bracket if condition in future
unordered_map<char, int> symbols = {{'[', -3},{'{', -2},{'(', -1},  {']', 3},{'}', 2},{')', 1}};

string balenced_brackets(string str)
{
    stack<char> st; /* stack of brackets */

    for (char brackets : str)
    {
        if (symbols[brackets] < 0) /* if the symbol value is negative then its opening bracket */
            st.push(brackets);     /* storing the opening brackets  */
       
        else  /* else if its value is positive then its a closing bracket */
        {
            if (st.empty()) /* if stack is empty */
                return "NO";

            char top_value = st.top(); /* storing the top value and checking if that is Matching with current closing bracket*/
            if (symbols[top_value] + symbols[brackets] != 0)
                return "NO"; 

            st.pop(); /* The opening bracket will be popped if both bracket matches mean sum=0 occurred */
        }
    }

    if (st.empty()) /* after all matches is stack become empty then its a balance bracket stack */
        return "YES";

    return "NO";   /* else return no */
}

int main()
{
    int t;
    cin >> t; /* no of testcases */
    string str;
    while (t--)
    {
        cin >> str;
        cout << balenced_brackets(str) << endl;
    }
    return 0;
}