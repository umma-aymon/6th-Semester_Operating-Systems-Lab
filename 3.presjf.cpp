#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, in = 0, complete = 0, mx = 0;
    cin >> n;
    cout << "Number of process: " << n << endl;
    int at[n + 1], bt[n + 1], tmp[n], wt2[n], pr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pr[i] >> at[i] >> bt[i];
        tmp[i] = bt[i];
    }
    bt[n] = 99999;
    double wt = 0, tat = 0;
    for (int i = 0; complete != n; i++)
    {
        in = n;
        for (int j = 0; j < n; j++)
            if (at[j] <= i && bt[j] < bt[in] && bt[j] > 0) // current time theke at choto kina & ei bt theke ager select kra in er bt choto kina & ei bt>0 kina mane task incomplete kina
                in = j;
        bt[in]--;
        if (bt[in] == 0)
        {
            complete++;
            mx = i + 1; //completed time
            wt += mx - at[in] - tmp[in];
            wt2[in] = mx - tmp[in] - at[in];
            tat += mx - at[in];
        }
        //cout << i << " " << in << " " << bt[in] << " " << mx << " " << wt << endl;
    }
    cout << "Processes   Burst_time   Waiting_time\n";
    for (int i = 0; i < n; i++)
        cout << "\tp" << i + 1 << "\t\t\t" << tmp[i] << "\t\t\t" << wt2[i] << endl;
    cout << "Average waiting time = " << wt / (n * 1.0) << endl;
    cout << "Average turn around time = " << tat / (n * 1.0) << endl;
    return 0;
}
/*
4
0 7
2 4
4 1
5 4
Average waiting time = 3
Average turn around time 7
*/