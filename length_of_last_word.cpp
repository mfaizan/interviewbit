int Solution::lengthOfLastWord(const string A) {
    int n = 0;
    int word_ended = true;
    for(int i = 0; i < A.size(); ++i)
    {
        if(A[i] == ' ')
        {
            word_ended = true;
        }
        else if(word_ended)
        {
            n = 1;
            word_ended = false;
        }
        else
        {
            ++n;
        }
    }
    
    return n;
}
