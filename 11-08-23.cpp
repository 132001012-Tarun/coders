// string to integer(atoi)


class Solution {
public:
    int myAtoi(string s) {
        int sz=s.size();
        double num=0;
        int i=0;
        bool positive=false;
        bool negative=false;
        while(s[i]==' ')
        {
            i++;
        }
        if(s[i]=='+')
        {
            positive =true;
            i++;
        }
        else if(s[i]=='-')
        {
            negative=true;
            i++;
        }
        while(i<sz&&s[i]>='0'&&s[i]<='9')
        {
            num=num*10+(s[i]-'0');
            i++;
        }
        if(negative)
        {
            num=-1*num;
        }
        if(num>INT_MAX)
        {
            num=INT_MAX;
        }
        else if(num<INT_MIN)
        {
            num=INT_MIN;
        }
        return int(num);
    }
};
