#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int p, r;
    cin >> p >> r;
    int alloc[p][r], max[p][r], avail[r];
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            cin >> alloc[i][j];

    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            cin >> max[i][j];

    for (int j = 0; j < r; j++)
        cin >> avail[j];

    int request[p], rqst[p][r + 1];
    cin >> request[0] >> request[1];
    cout << "New request on process no: " << request[0] << " " << request[1] << endl;
    cout << "New request's value:\n";
    for (int i = 0; i < 2; i++)
    {
        cout << "New request: " << request[i] << ": ";
        for (int j = 0; j < r; j++)
        {
            cin >> rqst[i][j];
            cout << rqst[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < r; j++)
        {
            if (rqst[i][j] > avail[j])
            {
                cout << "Cannot process.\nRequest is greater than available";
                return 0;
            }
            else
            {
                avail[j] -= rqst[i][j];
                alloc[request[i]][j] += rqst[i][j];
            }
        }
    cout << "New requst will be accepted\n";

    int seq[p], need[p][r], in = 0, pr = p, completed[p] = {0};
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    cout << "Number of processes: " << p << endl;
    cout << "Number of resources: " << r << endl;
    cout << "\nProcesses\tAllocation\tMax\t\tNeed\n";
    for (int i = 0; i < p; i++)
    {
        cout << "P" << i + 1 << "\t\t\t";
        for (int j = 0; j < r; j++)
            cout << alloc[i][j] << " ";
        cout << "\t\t";
        for (int j = 0; j < r; j++)
            cout << max[i][j] << " ";
        cout << "\t";
        for (int j = 0; j < r; j++)
            cout << need[i][j] << " ";
        cout << endl;
    }

    while (pr)
    {
        bool safe = false;
        for (int i = 0; i < p; i++)
        {
            if (completed[i] == 0) //process incomplete
            {
                int flag = 0;
                for (int j = 0; j < r; j++)
                    if (need[i][j] > avail[j])
                    {
                        flag = 1; //unsafe
                        break;
                    }

                if (flag == 0) //safe
                {
                    seq[in++] = i;              //process sequence
                    for (int k = 0; k < r; k++) // new availability
                        avail[k] += alloc[i][k];
                    completed[i] = 1; // process completed
                    safe = true;
                    pr--;
                }
            }
        }
        if (!safe)
        {
            cout << "\nThe system is in unsafe state.\n";
            return 0;
        }
    }
    cout << "\nThe system is in safe state.\nFollowing is the SAFE Sequence:" << endl;
    for (int i = 0; i < p; i++)
        cout << " P" << seq[i];
    return 0;
}
/*
5 4
0 0 1 2
3 1 2 1
2 1 0 3
1 3 1 2
1 4 3 2

4 4 2 3
5 4 7 2
3 4 1 6
2 3 2 4
6 5 6 5

3 2 2 4

2 3
1 0 1 2
0 0 1 1

New request on process no: 2 3
New request's value:
New request: 2: 1 0 1 2 
New request: 3: 0 0 1 1 

New requst will be accepted
Number of processes: 5
Number of resources: 4

Processes	Allocation	Max		Need
P1			0 0 1 2 		4 4 2 3 	4 4 1 1 
P2			3 1 2 1 		5 4 7 2 	2 3 5 1 
P3			3 1 1 5 		3 4 1 6 	0 3 0 1 
P4			1 3 2 3 		2 3 2 4 	1 0 0 1 
P5			1 4 3 2 		6 5 6 5 	5 1 3 3 

The system is in safe state.
Following is the SAFE Sequence:
 P3 P2 P4 P0 P1
 */
