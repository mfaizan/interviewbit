int memoizedNumDecodings(int *d, string A, int r);

int numDecodings(int *d, string A, int r)
{
	if (r == 0)
	{
		return 1;
	}

	if (r == 1)
	{
		if (A[r - 1] == '0')
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	
	int decodings = 0;
	if (A[r - 2] == '1' || (A[r - 2] == '2' && A[r - 1] <= '6'))
	{
	    decodings += memoizedNumDecodings(d, A, r - 2);
	}
	
    if(A[r - 1] != '0')
    {
        decodings += memoizedNumDecodings(d, A, r - 1);
    }

    return decodings;
}

int memoizedNumDecodings(int *d, string A, int r)
{
	if (d[r] == 0)
	{
		d[r] = numDecodings(d, A, r);
	}

	return d[r];
}

int Solution::numDecodings(string A) 
{
    int *d = new int[A.size() + 1]{ 0 };
	return memoizedNumDecodings(d, A, A.size());
}

