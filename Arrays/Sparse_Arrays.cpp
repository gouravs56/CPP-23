#include <bits/stdc++.h>
using namespace std;

vector<int> matchingStrings(vector<string> queries, vector<string> strings)
{
    unordered_map<string, int> map;
    // storing the 'strings' vector into the map
    for (int i = 0; i < strings.size(); i++)
    { 
        map[strings[i]]++;
    }
    vector<int> result;
    for (int i = 0; i < queries.size(); i++)
    {
      // if that query is not present in the string it will reach the end and will be stored zero
        if (map.find(queries[i]) == map.end())
            result.push_back(0);
        else
            result.push_back(map[queries[i]]);  /* else, store its occurence in the result vector */
    }
    return result;
}

int main()
{
    int size_of_query, size_of_string;

    vector<string> queries, strings;

    cin >> size_of_string;
    cin.ignore(); /* to ignore newline char of input buffer */
    for (int i = 0; i < size_of_string; i++)
    {
        string s;
        getline(cin, s);
        strings.push_back(s);
    }

    cin >> size_of_query;
    cin.ignore(); 
    for (int i = 0; i < size_of_query; i++)
    {
        string str;
        getline(cin, str);
        queries.push_back(str);
    }

    vector<int> result = matchingStrings( queries, strings);
    
    // range base loop for printing outpu
    for (auto &value : result)
    {
        cout << value << endl;
    }

    return 0;
}
