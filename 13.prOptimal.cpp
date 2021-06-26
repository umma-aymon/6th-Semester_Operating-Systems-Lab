#include <bits/stdc++.h>
using namespace std;
int main()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    cin >> no_of_pages >> no_of_frames;
    cout << "Number of pages: " << no_of_pages << endl;
    cout << "Number of frames: " << no_of_frames << endl;
    for (i = 0; i < no_of_pages; ++i)
        cin >> pages[i];
    cout << "Reference string:\n";
    for (i = 0; i < no_of_pages; ++i)
        cout << pages[i] << " ";
    cout << endl;
    for (i = 0; i < no_of_frames; ++i)
        frames[i] = -1;
    cout << "\tRef string - Page - frames\n";
    for (i = 0; i < no_of_pages; ++i)
    {
        cout << pages[i] << "\t\t";
        flag1 = flag2 = 0;
        for (j = 0; j < no_of_frames; ++j)
            if (frames[j] == pages[i])
            {
                flag1 = flag2 = 1;
                break;
            }
        if (flag1 == 0)
            for (j = 0; j < no_of_frames; ++j)
                if (frames[j] == -1)
                {
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
        if (flag2 == 0)
        {
            flag3 = 0;
            for (j = 0; j < no_of_frames; ++j)
            {
                temp[j] = -1;
                for (k = i + 1; k < no_of_pages; ++k)
                    if (frames[j] == pages[k])
                    {
                        temp[j] = k;
                        break;
                    }
            }
            for (j = 0; j < no_of_frames; ++j)
                if (temp[j] == -1)
                {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            if (flag3 == 0)
            {
                max = temp[0];
                pos = 0;
                for (j = 1; j < no_of_frames; ++j)
                    if (temp[j] > max)
                        max = temp[j], pos = j;
            }
            frames[pos] = pages[i];
            faults++;
        }
        if (flag1 == 0 || flag2 == 0)
            for (j = 0; j < no_of_frames; ++j)
            {
                if (frames[j] != -1)
                    cout << frames[j] << "\t\t ";
            }
        else
            cout << "No page fault";
        cout << endl;
    }
    cout << "\nPage fault is: " << faults;
    return 0;
}
/*
8 3
Number of pages: 8
Number of frames: 3
2 3 4 2 3 5 6 2
Reference string:
2 3 4 2 3 5 6 2
        Ref string - Page - frames
2               2
3               2                3
4               2                3               4
2               No page fault
3               No page fault
5               2                5               4
6               2                6               4
2               No page fault

Page fault is: 5
*/
