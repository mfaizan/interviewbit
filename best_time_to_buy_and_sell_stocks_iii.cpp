int Solution::maxProfit(const vector<int> &A) 
{
    if(A.size() == 0 || A.size() == 1)
    {
        return 0;
    }
    
    if(A.size() == 2)
    {
        if(A[1] > A[0])
        {
            return A[1] - A[0];
        }
        else
        {
            return 0;
        }
    }

    int *left_gain = new int[A.size()];
    int min = A[0];
    int gain = 0;
    for(int i = 0; i < A.size(); ++i)
    {
        if(A[i] < min)
        {
            min = A[i];
        }

        if(A[i] - min > gain)
        {
            gain = A[i] - min;
        }

        left_gain[i] = gain;
    }

    int *right_gain = new int[A.size()];
    int max = A[A.size() - 1];
    gain = 0;
    for(int i = A.size() - 1; i >= 0; --i)
    {
        if(A[i] > max)
        {
            max = A[i];
        }

        if(max - A[i] > gain)
        {
            gain = max - A[i];
        }

        right_gain[i] = gain;
    }

    gain = 0;
    for(int i = 0; i < A.size() - 1; ++i)
    {
        if(left_gain[i] + right_gain[i + 1] > gain)
        {
            gain = left_gain[i] + right_gain[i + 1];
        }
    }

    if(left_gain[A.size() - 1] > gain)
    {
        gain = left_gain[A.size() - 1];
    }

    return gain;
}

