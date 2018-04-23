int match(char *cur, char *prev, const string& A, const string& B, int i, int j)
{
	if (i == A.size() && j == B.size())
	{
		return 1;
	}

	if (i == A.size())
	{
		for (int x = j; x < B.size(); ++x)
		{
			if (B[x] != '*')
			{
				return 0;
			}
		}

		return 1;
	}

	if (j == B.size())
	{
		return 0;
	}

	if (B[j] == '?')
	{
		return prev[j + 1];
	}

	if (B[j] == '*')
	{
		return prev[j + 1] || prev[j] || cur[j + 1];
	}

	if (A[i] == B[j])
	{
		return prev[j + 1];
	}

	return 0;
}

int Solution::isMatch(const string A, const string B)
{
	char *cur = new char[B.size() + 1];
	char *prev = nullptr;
	for (int i = A.size(); i >= 0; --i)
	{
		for (int j = B.size(); j >= 0; --j)
		{
			cur[j] = match(cur, prev, A, B, i, j);
		}

		if (prev)
		{
			delete prev;
		}

		prev = cur;
		if (!i)
		{
			return cur[0];
		}
		else
		{
			cur = new char[B.size() + 1];
		}
	}

	return 0;
}

