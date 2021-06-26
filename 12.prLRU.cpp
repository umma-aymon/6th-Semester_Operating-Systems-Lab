#include <bits/stdc++.h>
using namespace std;
int i, frame_no, string_len, input_string[50], frame[10], frame_size, k, times[100], cnt, avail, pos, faults;
bool f;
int tracker(int n)
{
    int i, minimum = times[0], pos = 0;
    //cout << minimum << endl;
    for (i = 1; i < n; ++i)
        if (times[i] < minimum)
            minimum = times[i], pos = i;
    //cout << "min=" << minimum << "," << pos << endl;
    return pos;
}

int main()
{
    cin >> string_len >> frame_size;
    for (i = 0; i < string_len; i++)
        cin >> input_string[i];
    cout << "The number of pages: " << string_len << endl;
    cout << "The number of frames: " << frame_size << endl;
    cout << "Reference string:\n";
    for (i = 0; i < string_len; i++)
        cout << input_string[i] << " ";
    cout << endl;
    for (i = 0; i < frame_size; i++)
        frame[i] = -1;
    frame_no = -1;
    cout << "Ref_string - Page_frames\n";
    for (i = 0; i < string_len; i++)
    {
        cout << input_string[i] << "\t\t\t ";
        f = false;
        for (k = 0; k < frame_size; k++)
            if (frame[k] == input_string[i])
            {
                cnt++;
                times[k] = cnt;
                f = true;
                break;
            }
        if (!f)
        {
            pos = tracker(frame_size);
            cnt++;
            faults++;
            frame[pos] = input_string[i];
            times[pos] = cnt;
            // cout << "p=" << pos << " " << times[pos] << endl;
        }
        if (!f)
            for (int j = 0; j < frame_size; ++j)
                cout << frame[j] << "\t\t ";
        else
            cout << "No page fault";
        cout << endl;
    }
    cout << "Page Fault Is: " << faults;
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
5               2                3               5
6               6                3               5
2               6                2               5

Page fault is: 6
*/
