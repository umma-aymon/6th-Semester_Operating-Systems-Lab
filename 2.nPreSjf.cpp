#include <bits/stdc++.h>
using namespace std;
multimap<int, int> mp;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int pt, bt;
        cin >> pt >> bt;
        mp.insert(pair<int, int>(bt, pt));
        //mp[bt] = pt; //burst time er ghhore process k rakhsi
    }
    cout << "Order in which process gets executed\n";
    for (auto el : mp)
        cout << "Process No: " << el.second << " Burst Time: " << el.first << endl;
    int tat[n], wt[n], totalWT = 0, totalTAT = 0, j = 1;
    wt[0] = 0;
    //calculating waiting time
    for (auto el : mp)
    {
        int b = el.first;
        wt[j] = b + wt[j - 1];
        j++;
    }
    //calculating turn around time
    j = 0;
    for (auto el : mp)
    {
        tat[j] = el.first + wt[j];
        j++;
    }
    for (int i = 0; i < n; i++)
    {
        totalWT += wt[i];
        totalTAT += tat[i];
    }
    cout << "Processes   Burst_time   Waiting_time   Turn_around_time\n";
    j = 0;
    for (auto el : mp)
    {
        cout << "\t" << el.second << "\t\t\t" << el.first << "\t\t\t " << wt[j] << "\t\t\t " << tat[j] << endl;
        j++;
    }
    cout << "Average waiting time = " << totalWT / (n * 1.0) << endl;
    cout << "Average turn around time = " << totalTAT / (n * 1.0) << endl;
    return 0;
}

/*
4
1 21
2 3
3 6
4 2 
Order in which process gets executed
Process No: 4 Burst Time: 2
Process No: 2 Burst Time: 3
Process No: 3 Burst Time: 6
Process No: 1 Burst Time: 21
Processes   Burst_time   Waiting_time   Turn_around_time
        4                       2                        0                       2
        2                       3                        2                       5
        3                       6                        5                       11
        1                       21                       11                      32
Average waiting time = 4.5
Average turn around time = 12.5
*/