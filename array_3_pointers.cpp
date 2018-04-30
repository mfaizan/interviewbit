int f(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int min_max = -1;
    
    int j = 0;
    int k = 0;
    for(int i = 0; i < A.size(); ++i)
    {
        for(; j < B.size() - 1 && B[j + 1] <= A[i]; ++j);
        for(; k < C.size() - 1 && C[k + 1] <= B[j]; ++k);
        
        int m = max({abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])});
        
        min_max = min_max == -1 ? m : min(min_max, m);
    }
    
    return min_max;
}

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
     return min({f(A, B, C), f(A, C, B), f(B, A, C), f(B, C, A), f(C, A, B), f(C, B, A)});
}
