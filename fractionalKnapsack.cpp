/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double profit = 0;
        int i = 0;
        while(W || n)
        {
            //check 
            if(arr[i].weight < W)
            {
                // include that whole element
                profit += arr[i].value;
                W -= arr[i].weight;
            }
            else
            {
                // if you can't take the full element
                profit += (float) (arr[i].value/arr[i].weight)*W;
                W = 0;
            }
            i++;
        }
        return profit;
    }
        
};
