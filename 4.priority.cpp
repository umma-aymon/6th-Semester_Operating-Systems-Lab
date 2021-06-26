#include <bits/stdc++.h>
using namespace std;
struct schedule
{
    int pid, at, bt, pt, st, ct, tat, wt, rt;
};
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    struct schedule p[100];
    double avg_tat, avg_wt, avg_rt, cpu;
    int tot_tat = 0, tot_wt = 0, tot_rt = 0, tot_it = 0;
    float throughput;
    int is_completed[100];
    memset(is_completed, 0, sizeof(is_completed));
    cout << setprecision(2) << fixed;
    cin >> n;
    cout << "Number of processes: " << n << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].at >> p[i].bt >> p[i].pt;
        p[i].pid = i + 1;
    }
    int current_time = 0, completed = 0, prev = 0;
    while (completed != n)
    {
        int idx = -1, mx = -1;
        for (int i = 0; i < n; i++)
            if (p[i].at <= current_time && is_completed[i] == 0)
            {
                if (p[i].pt > mx)
                {
                    mx = p[i].pt;
                    idx = i;
                }
                if (p[i].pt == mx)
                    if (p[i].at < p[idx].at)
                    {
                        mx = p[i].pt;
                        idx = i;
                    }
            }
        if (idx != -1)
        {
            p[idx].st = current_time;
            p[idx].ct = p[idx].st + p[idx].bt;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].rt = p[idx].st - p[idx].at;
            tot_tat += p[idx].tat;
            tot_wt += p[idx].wt;
            tot_rt += p[idx].rt;
            tot_it += p[idx].st - prev;
            is_completed[idx] = 1;
            completed++;
            current_time = p[idx].ct;
            prev = current_time;
        }
        else
            current_time++;
    }
    int min_at = 1000000, max_ct = -1;
    for (int i = 0; i < n; i++)
    {
        min_at = min(min_at, p[i].at);
        max_ct = max(max_ct, p[i].ct);
    }
    cout << "#P\tAT\tBT\tPRI\tST\tCT\tTAT\tWT\tRT\t" << endl;
    for (int i = 0; i < n; i++)
        cout << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].pt << "\t" << p[i].st << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\t" << p[i].rt << "\t" << endl;
    cout << "Average Turnaround Time = " << tot_tat / (n * 1.0) << endl;
    cout << "Average Waiting Time = " << tot_wt / (n * 1.0) << endl;
    cout << "Average Response Time = " << tot_rt / (n * 1.0) << endl;
    cout << "CPU Utilization = " << ((max_ct - tot_it) / (max_ct * 1.0)) * 100 << "%" << endl;
    cout << "Throughput = " << (n * 1.0) / (max_ct - min_at) << " process/unit time" << endl;
}
/*
3
2 1 3
5 4 1
4 6 2
Number of processes: 3
#P	AT	BT	PRI	ST	CT	TAT	WT	RT	
1	2	1	3	2	3	1	0	0	
2	5	4	1	10	14	9	5	5	
3	4	6	2	4	10	6	0	0	
Average Turnaround Time = 5.33
Average Waiting Time = 1.67
Average Response Time = 1.67
CPU Utilization = 78.57%
Throughput = 0.25 process/unit time

*/