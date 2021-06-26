#include <bits/stdc++.h>
using namespace std;
int i, j, n, a[50], frame[10], no, k, avail, cnt;
int main()
{
    cin >> n >> no;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    cout << "The number of pages: " << n << endl;
    cout << "The number of frames: " << no << endl;
    cout << "Reference string:\n";
    for (i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    for (i = 0; i < no; i++)
        frame[i] = -1;
    j = 0;
    cout << "\tRef string - Page - frames\n";
    for (i = 1; i <= n; i++)
    {
        cout << a[i] << "\t\t";
        avail = 0;
        for (k = 0; k < no; k++)
            if (frame[k] == a[i])
                avail = 1;
        if (avail == 0)
        {
            frame[j] = a[i];
            j = (j + 1) % no;
            cnt++;
            for (k = 0; k < no; k++)
                cout << frame[k] << "\t\t ";
        }
        cout << endl;
    }
    cout << "Page Fault Is: " << cnt;
    return 0;
}
/*
8 3
2 3 4 2 3 5 6 2
The number of pages: 8
The number of frames: 3
Reference string:
2 3 4 2 3 5 6 2
        Ref string - Page - frames
2               2                -1              -1
3               2                3               -1
4               2                3               4
2
3
5               5                3               4
6               5                6               4
2               5                6               2
Page Fault Is: 6
*/
