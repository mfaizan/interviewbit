int match(char *cur, char *prev, char *prev2, const string& A, const string& B, int i, int j)
{
    if(i == A.size() && j == B.size())
    {
        return 1;
    }

    if(i == A.size() || j == B.size())
    {
        return 0;
    }

    if((A[i] == B[j] || B[j] == '.') && B.size() - j >= 2 && B[j + 1] == '*')
    {
        int x;
        for(x = i; x < A.size() && (A[x] == B[j] || B[j] == '.'); ++x)
        {
            if(prev2[x])
            {
                return 1;
            }
        }

        if(x == A.size() && prev2[A.size()])
        {
            return 1;
        }

        return cur[i + 1];
    }

    if(A[i] != B[j] && B.size() - j >= 2 && B[j + 1] == '*')
    {
        return prev2[i];
    }

    if(A[i] == B[j] || B[j] == '.')
    {
        return prev[i + 1];
    }

    return 0;
}

int Solution::isMatch(const string A, const string B) 
{
    char *cur = new char[A.size() + 1];
    char *prev = nullptr;
    char *prev2 = nullptr;
    for(int j = B.size(); j >= 0; --j)
    {
        for(int i = A.size(); i >= 0; --i)
        {
            cur[i] = match(cur, prev, prev2, A, B, i, j);
        }

        if(prev2)
        {
            delete prev2;
        }

        prev2 = prev;
        prev = cur;

        if(!j)
        {
            return cur[0];
        }

        cur = new char[A.size() + 1];
    }

    return 0;
}
