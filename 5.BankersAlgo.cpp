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
5 3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
3 3 2

Number of processes: 5
Number of resources: 3

Processes	Allocation	Max		Need
P1			0 1 0 		7 5 3 	7 4 3 
P2			2 0 0 		3 2 2 	1 2 2 
P3			3 0 2 		9 0 2 	6 0 0 
P4			2 1 1 		2 2 2 	0 1 1 
P5			0 0 2 		4 3 3 	4 3 1 

The system is in safe state.
Following is the SAFE Sequence:
 P1 P3 P4 P0 P2
 */
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
Number of processes: 5
Number of resources: 4

Processes	Allocation	Max		Need
P1			0 0 1 2 		4 4 2 3 	4 4 1 1 
P2			3 1 2 1 		5 4 7 2 	2 3 5 1 
P3			2 1 0 3 		3 4 1 6 	1 3 1 3 
P4			1 3 1 2 		2 3 2 4 	1 0 1 2 
P5			1 4 3 2 		6 5 6 5 	5 1 3 3 

The system is in safe state.
Following is the SAFE Sequence:
 P3 P0 P2 P4 P1
*/