int eval(vector<string> &A, int i, int& value)
{
    if((A[i].size() == 1) && (A[i][0] == '*' || A[i][0] == '+' || A[i][0] == '-' || A[i][0] == '/'))
    {
        char op = A[i][0];
        
        int right;
        i = eval(A, i - 1, right);
        
        int left;
        i = eval(A, i, left);
        
        switch(op)
        {
            case '*':
                value = left * right;
                break;
            case '+':
                value = left + right;
                break;
            case '-':
                value = left - right;
                break;
            case '/':
                value = left / right;
                break;
        }
        
        return i;
    }
    else
    {
        value = stoi(A[i]);
        return i - 1;
    }
}

int Solution::evalRPN(vector<string> &A) {
    int value;
    eval(A, A.size() - 1, value);
    
    return value;
}
