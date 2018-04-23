int Solution::maxProfit(const vector<int> &A)
{
    int profit = 0;
    int buy = 0;
    for(int i = 1; i < A.size(); ++i)
    {
        if(A[i] < A[i - 1])
        {
            profit += A[i - 1] - A[buy];
            buy = i;
        }
    }

    if(A.size() == 0)
    {
        return 0;
    }
    
    profit += A[A.size() - 1] - A[buy];

    return profit;
}

