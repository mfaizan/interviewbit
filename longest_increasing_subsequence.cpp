int Solution::lis(const vector<int> &A) 
{
    if (A.size() == 0)
	{
		return 0;
	}

	int *l = new int[A.size()]{ 1 };

	for (int i = 1; i < A.size(); ++i)
	{
		int max = 1;
		for (int j = 0; j < i; ++j)
		{
			if (A[j] < A[i] && l[j] + 1 > max)
			{
				max = l[j] + 1;
			}
		}

		l[i] = max;
	}

	int max = 1;
	for (int i = 0; i < A.size(); ++i)
	{
		if (l[i] > max)
		{
			max = l[i];
		}
	}

	return max;
}
