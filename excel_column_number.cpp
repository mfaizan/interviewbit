int Solution::titleToNumber(string A) {
    int n = 0;
    for(int i = 0; i < A.size(); ++i)
    {
        if(i >= 1)
        {
            n *= 26;
        }
        
        n += A[i] - ('A' - 1);
    }
    
    return n;
}
