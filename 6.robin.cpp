#include <bits/stdc++.h>
using namespace std;
int n, qt, current_time, completed, tot_wt;
struct schedule
{
    int pid, at, bt, remaining_bt, wt;
};
schedule p[100];
bool compare(schedule a, schedule b)
{
    if (a.at < b.at)
        return 1;
    return 0;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    cout << "Number of processes: " << n << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].at >> p[i].bt;
        p[i].pid = i + 1;
        p[i].remaining_bt = p[i].bt;
    }
    cin >> qt;
    cout << "Quantam Time: " << qt << endl;
    sort(p, p + n, compare);
    cout << "\n-------------------Gantt Chart-------------------\n";
    while (completed < n) //jtokhn prjnto shb task shesh nah hoy
    {
        bool done = true;
        for (int i = 0; i < n; i++)
        {
            if (p[i].remaining_bt != 0)
                cout << "||" << current_time << "->P";
            if (p[i].at <= current_time && p[i].remaining_bt > 0)
            {
                done = false;
                if (p[i].remaining_bt <= qt)
                {
                    completed++; //ekta process cmplt
                    current_time += p[i].remaining_bt;
                    p[i].wt = current_time - p[i].at - p[i].bt;
                    tot_wt += p[i].wt;
                    p[i].remaining_bt = 0;
                    cout << i + 1 << "<-" << current_time;
                }
                else
                {
                    current_time += qt;
                    p[i].remaining_bt -= qt;
                    cout << i + 1 << "<-" << current_time;
                }
            }
        }
        if (done == true)
            break;
    }
    cout << "\n\nP.No\tArrival\t\tBurst\tWaiting\t" << endl;
    for (int i = 0; i < n; i++)
        cout << "P" << p[i].pid << "\t\t" << p[i].at << "\t\t\t" << p[i].bt << "\t\t" << p[i].wt << "\t" << endl;
    cout << "\nAverage Waiting Time = " << tot_wt / (n * 1.0) << endl;
    return 0;
}
/*
4
0 53
1 17
2 68
3 24
20
Number of processes: 4
Quantam Time: 20

-------------------Gantt Chart-------------------
||0->P1<-20||20->P2<-37||37->P3<-57||57->P4<-77||77->P1<-97||97->P3<-117||117->P4<-121||121->P1<-134||134->P3<-154||154->P3<-162

P.No	Arrival		Burst	Waiting	
P1		0			53		81	
P2		1			17		19	
P3		2			68		92	
P4		3			24		94	

Average Waiting Time = 71.5
*/