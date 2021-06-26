/*FCFS->calculate waiting time for each process & their average waiting time*/
/*ekta process er waiting time hcche oi process start howar ag prjnto jto process hoise 
oder burst time er summation
jmn p1 k wait kra lge nai so wt of p1=0
wt of p2=bt of p1
wt of p3=bt of p1+bt of p2=24+3=27
jdi p4 thakto tar wt hoito= bt of(p1+p2+p3)=......*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cout << "Number of process: " << n << endl;
    int bt[n], wt[n], total = 0;
    // for (int i = 0; i < n; i++)
    for (auto &el : bt)
        cin >> el;
    //sort(bt, bt + n);// for Shortest Job First but not original sjf
    wt[0] = 0; //first process always 0 theke start hbe
    //calculating waiting time for each process
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
        total += wt[i];
    }
    //cout << total << endl;
    cout << "Processes  Burst_time  Waiting_time\n";
    for (int i = 0; i < n; i++)
        cout << "\tP" << i + 1 << "\t\t" << bt[i] << "\t\t\t" << wt[i] << endl;
    cout << "Average waiting time = " << total / (n * 1.0);
    return 0;
}
/*
Input:
3
24 3 3

Output:
Number of process: 3
Processes Burst_time  Waiting_time
	P1		24			0
	P2		3			24
	P3		3			27
Average waiting time = 17
*/