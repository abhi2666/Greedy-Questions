/*
We are given two arrays that represent the arrival and departure times of 
trains that stop at the platform. We need to find the minimum number of 
platforms needed at the railway station so that no train has to wait.

Input: N=6, 
arr[] = {9:00, 9:45, 9:55, 11:00, 15:00, 18:00} 
dep[] = {9:20, 12:00, 11:30, 11:50, 19:00, 20:00}

Output:3
*/

#include <bits/stdc++.h>
using namespace std;

void getData(int a[], int n)
{
    for(int i = 0; i < n; i++) cin>>a[i];
    cout<<endl;
}


int minPlatform(int arr[], int dep[], int n)
{
    int max = 1, platform = 1;

    sort(arr, arr+n);
    sort(dep, dep+n);

    int i, j; // i --> for arrival time and j --> for departure time
    i = 1, j = 0;

    while(i < n && j < n)
    {
        if(arr[i] <= dep[j])
        {
            // new train has arrived
            platform++; // extra 1 platform will be required
            i++;
        }
        else if(arr[i] > dep[j])
        {
            //train will depart and will make a platform free
            platform--;
            j++; // new departure will be processed
        }

        if(platform > max) max = platform;
    }
    return max;
}

int main()
{
    int n;cin>>n;
    int arrival[n], departure[n];
    getData(arrival, n);
    getData(departure, n);
    cout<<minPlatform(arrival, departure, n)<<endl;
    return 0;
}