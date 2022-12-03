#include <bits/stdc++.h>
using namespace std;

pair<int, int> twoSum(int a[], int n, int value)
{
    pair<int, int> p;
    int i = 0, j = n - 1;
    int sum = 0;
    while(i < j)
    {
        sum = a[i] + a[j];
        if(sum == value)
        {
            p.first = i;
            p.second = j;
            return p;
        }
        else if(sum > value)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return p;
}
int main()
{
    int n, target;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    cin>>target;

    pair<int, int> res = twoSum(a, n, target);
    cout<<res.first<<" "<<res.second<<endl;

    return 0;
}