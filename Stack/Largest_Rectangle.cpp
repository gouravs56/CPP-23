#include <bits/stdc++.h>
using namespace std;


// function to find next smaller height building
vector<int> nextSmallerBuilding(vector<int> buildings, int n)
{
    stack<int> st; /* implementing stack */
    st.push(-1); /* initialzing stack with -1 */
    vector<int> nxtSmaller(n); /* To store next smaller value */

    for (int i = n - 1; i >= 0; i--) /* starting form the right side to minimize the comparison */
    {
        int curr = buildings[i];

    //pop the top building from stack when it finds bigger building than the current building 
        while (st.top() != -1 && buildings[st.top()] >= curr)
            st.pop(); 

        nxtSmaller[i] = st.top(); /* storing the top (nxt smaller) into the nxtSmaller array */
        st.push(i); /* storing the currend building into the stack */
    }
    return nxtSmaller;
}


// function to find previous smaller height building
vector<int> prevSmallerBuilding(vector<int> buildings, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> preSmaller(n);
    for (int i = 0; i < n; i++) /* starting form the left side to minimize the comparison */
    {
        int curr = buildings[i];
        while (st.top() != -1 && buildings[st.top()] >= curr)
            st.pop();

        preSmaller[i] = st.top();
        st.push(i);
    }
    return preSmaller;
}

int LargestRectangleArea(vector<int> buildings)
{
    int n = buildings.size(), area = INT_MIN;

    vector<int> next(n);
    next = nextSmallerBuilding(buildings, n); /* function call for nextSmallerBuilding() */

    vector<int> prev(n);
    prev = prevSmallerBuilding(buildings, n);

    for (int i = 0; i < n; i++)
    {
        int length = buildings[i]; /* max rectangle length = current building height */

        if (next[i] == -1) /* for all same height building */
            next[i] = n;
         
        // main formula to calculate breadth of this problem
        int breadth = next[i] - prev[i] - 1;

        int newArea = length * breadth;
        area = max(area, newArea);
    }
    return area;
}

int main()
{
    int n;
    cin >> n;                 /* no of building in the vector */
    vector<int> buildings(n); /* vector of bulinding height */
    for (int i = 0; i < n; i++)
        cin >> buildings[i];
    int result = LargestRectangleArea(buildings);
    cout << result;
    return 0;
}