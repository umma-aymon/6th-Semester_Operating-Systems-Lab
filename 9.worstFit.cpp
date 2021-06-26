#include <bits/stdc++.h>
using namespace std;
int main()
{
    int bsz, psz;
    cin >> bsz >> psz;
    int block[bsz], process[psz], alloc[bsz];
    memset(alloc, -1, sizeof(alloc));
    for (auto &el : block)
        cin >> el;
    for (auto &el : process)
        cin >> el;
    for (int i = 0; i < psz; i++)
    {
        int wstin = -1;
        for (int j = 0; j < bsz; j++)
            if (block[j] >= process[i])
            {
                if (wstin == -1)
                    wstin = j;
                else if (block[wstin] < block[j])
                    wstin = j;
            }
        if (wstin != -1)
        {
            alloc[i] = wstin;
            block[wstin] -= process[i];
        }
    }
    cout << "P. No\tP. Size\tBlock no.\n";
    for (int i = 0; i < psz; i++)
    {
        cout << " " << i + 1 << "\t\t" << process[i] << "\t\t";
        if (alloc[i] != -1)
            cout << alloc[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
    return 0;
}
/*
5 4
100 500 200 300 600
212 417 112 426
*/