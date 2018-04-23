int Solution::maxProfit(const vector<int> &A) 
{
    if(A.size() == 0)
    {
        return 0;
    }
    
    int min = A[0];
    int gain = 0;
    for(int n : A)
    {
        if(n < min)
        {
            min = n;
        }
        
        if(n - min > gain)
        {
            gain = n - min;
        }
    }
    
    return gain;
}

