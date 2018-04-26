string add(string A, string B)
{
    string s = "";
    
    int carry = 0;
    int i = A.size() - 1;
    int j = B.size() - 1;
    
    while(i >= 0 || j >= 0 || carry)
    {
        int z = 0;
        
        if(i >= 0)
        {
            z += A[i] - '0';
        }
        
        if(j >= 0)
        {
            z += B[j] - '0';
        }
        
        z += carry;
        
        s = to_string(z % 10) + s;
        
        carry = z / 10;
        
        --i;
        --j;
    }
    
    return s;
}

string multiplySingle(string A, int d)
{
    string s = "";
    
    int carry = 0;
    int i = A.size() - 1;
    
    while(i >= 0 || carry)
    {
        int z = 0;
        
        if(i >= 0)
        {
            z += (A[i] - '0') * d;
        }
        
        z += carry;
        
        s = to_string(z % 10) + s;
        
        carry = z / 10;
        
        --i;
    }
    
    return s;
}

string Solution::multiply(string A, string B) {
    string s = "";
    for(int i = B.size() - 1; i >= 0; --i)
    {
        string temp = multiplySingle(A, B[i] - '0');
        for(int j = i; j < B.size() - 1; ++j)
        {
            temp += "0";
        }
        
        s = add(s, temp);
    }
    
    if(s.size() > 0)
    {
        int i = 0;
        for(; i < s.size() - 1 && s[i] == '0'; ++i);
        
        s.erase(s.begin(), s.begin() + i);
    }
    
    return s;
}
