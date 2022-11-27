/*
Program to find max no. of mettings that can take place in just one room

Approach -->
1. Store metting (start, end, metting_no) in a structure.
2. Sort the struct array on the basis of end time using comparater operator.
3. traverse the list and now compare the mettings start and end time and 
find the max no of meetings.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
    int start;
    int end;
    int pos;
}meet;

void get_data(int a[], int n)
{
    for(int i = 0; i < n; i++) cin>>a[i];
    cout<<endl;
}

bool comp(meet m, meet n)
{
    // sort on the basis of end time 
    // if end time is equal then sort on the basis of position
    if(m.end < n.end) return true;
    else if(m.end > n.end) return false;
    else if(m.pos < n.pos) return true;
    return false;
}

vector<int> maxMettings(int s[] ,int e[], int n)
{
    meet m[n]; // array of structure
    //populate it
    for(int i = 0; i < n; i++)
    {
        m[i].start = s[i];
        m[i].end = e[i];
        m[i].pos = i + 1;
    }

    // sort the struct array on the basis of ending time
    sort(m, m+n, comp); 
    
    // main logic
    vector<int> meets;
    // first meeting will by default held because room is currently free
    int limit = m[0].end;
    meets.push_back(m[0].pos);

    for(int i = 1; i < n; i++)
    {
        if(m[i].start > limit)
        {
            //means meeting can be held in room
            limit = m[i].end;
            meets.push_back(m[i].pos);
        }
    }
    return meets;
}

int main()
{
    int n;cin>>n;
    int start_time[n], end_time[n];
    cout<<"Enter starting time: ";
    get_data(start_time, n);
    cout<<"Enter ending time: ";
    get_data(end_time, n);

    //main logic
    vector<int> res = maxMettings(start_time, end_time, n);

    for(auto i : res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}