vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    vector<pair<int, int>> C{};
    for(int i = 0; i < A.size(); ++i)
    {
        C.push_back(make_pair(A[i], B[i]));
    }
    
    sort(
        C.begin(), 
        C.end(), 
        [](const pair<int, int>& a, const pair<int, int>& b) 
        { 
            return a.first > b.first;
        });
    
    vector<int> D{};
    for(pair<int, int> elem : C)
    {
        int h = elem.first;
        int n = elem.second;
        
        D.insert(D.begin() + n, h);
    }
    
    return D;
}
