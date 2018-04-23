void explore(const vector<vector<int>> &A, int& counter, int x, int y)
{
	int M = A.size();
	int N = A[0].size();

	if (x < 0 || y < 0 || x >= M || y >= N)
	{
		return;
	}

	if (A[x][y])
	{
		return;
	}

	if (x == M - 1 && y == N - 1)
	{
		++counter;
	}
	else
	{
		explore(A, counter, x, y + 1);
		explore(A, counter, x + 1, y);
	}
}


int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) 
{
    int counter = 0;
	explore(A, counter, 0, 0);

	return counter;
}

