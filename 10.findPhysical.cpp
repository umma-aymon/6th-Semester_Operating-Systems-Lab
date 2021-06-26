#include <bits/stdc++.h>
using namespace std;
int main()
{
    int seg[100], base[100], limit[100], i, j, len, n, pa, index, la[100];
    string l, s;
    cin >> n; // enter how many segment
    for (i = 0; i < n; i++)
        cin >> seg[i] >> base[i] >> limit[i];
    for (i = 0; i < n; i++)
    {
        cin >> l; //logical address with segment
        len = l.size();
        s = l.substr(1, len);
        index = l[0] - '0';
        la[index] = stoi(s); //entering logical address for respected segment
        s.clear();
        l.clear();
    }
    for (i = 0; i < n; i++)
        if (la[i] <= limit[i])
        {
            pa = la[i] + base[i];
            cout << "Physical address of segment[" << i << "] is: " << pa << endl;
        }
        else
            printf("Physical address is not found for segment[%d] as the length is not legal\n", i);
    return 0;
}

/*
5
0 30 400
1 400 14
2 95 80
3 37 500
4 195 96
048
115
2100
3600
412
Physical address of segment[0] is: 78
Physical address is not found for segment[1] as the length is not legal
Physical address is not found for segment[2] as the length is not legal
Physical address is not found for segment[3] as the length is not legal
Physical address of segment[4] is: 207
*/
