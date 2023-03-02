#include <bits/stdc++.h>
using namespace std;

struct gasStation
{
    int gas;
    int nextStationDist;
};

int main()
{
    int N; /* no of station */
    cin >> N;

    queue<gasStation> stations;
    for (int i = 0; i < N; i++)
    {
        struct gasStation gs;
        cin >> gs.gas >> gs.nextStationDist;
        stations.push(gs);
    }
    int startingStation = 0, passedStation = 0, gasInTank = 0;
    while (passedStation < N)
    {
        struct gasStation gs = stations.front(); /* storing the current station data in the structure*/
        gasInTank += gs.gas;

        if (gasInTank >= gs.nextStationDist) /* for sucessful tour to nxt station */
        {
            passedStation += 1;
            gasInTank -= gs.nextStationDist; /* gasUsed == nextStationDist */
        }
        else
        {  /* for unsucessful tour resetting the value and now startingStation = next passing station */
            startingStation += passedStation + 1;
            passedStation = 0;
            gasInTank = 0;
        }
        // removing the current station to store the nxt station value in struct gs
        stations.pop();
        stations.push(gs); /* storing the current station value at the end/rear of the queue as it is removed from the front */
    }
    cout << startingStation << endl;

    return 0;
}
