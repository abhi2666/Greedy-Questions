/*
struct 
{
    int id;
    int dead; // deadline
    int profit
};
*/

bool comp(job a, job b)
{
    if(a.profit > b.profit) return true;
    return false;
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       //Job is a structure
       // sort the job(array of structure)
       sort(arr, arr+n, comp);
       int maxDead = arr[0].dead;
       for(int i = 1; i < n; i++)
       {
           maxDead = max(maxDead, arr[i].dead);
       }
       int total_profit = 0, countJobs = 0;
       vector<int> check(maxDead + 1, -1);
       
       for(int i = 0; i < n; i++)
       {
            for(int j = arr[i].dead; j > 0; j--)
            {
                if(check[j] == -1)
                {
                    //add profit
                    check[j] = i;
                    total_profit += arr[i].profit;
                    countJobs += 1;
                    break;
                }
            }
       }
       //final answer
       vector<int> ans;
       ans.push_back(countJobs);
       ans.push_back(total_profit);
       
       return ans;
       
    }
     
};