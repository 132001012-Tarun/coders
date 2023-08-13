// PALINDROMIC PARTIONING


class Solution {
public:
  bool is_palindrome(string a, int start,int end){
      int f=start;
      int l=end;
      while(f<=l)
      {
          if(a[f]!=a[l])
          {
              return false;
          }
          f++;
          l--;
      }
      return true;
  }
  void solve(int ind,vector<vector<string>>&ans,vector<string>&temp,string s){
     if(ind==s.size())
     {
         ans.push_back(temp);   // IF THE IND IS EQUAL TO SIZE THAT MEANS ALL ELEMENTS ARE COVERED SO U CAN PUSH THAT 
         return;
     }
     for(int i=ind;i<s.size();i++)
     {
         if(is_palindrome(s,ind,i))   // CHECKING IF THE SUBSTRING IS PALINDROME
         {
             temp.push_back(s.substr(ind,i-ind+1));   // PUSHING THE SUBSTRING IN THE TEMP
             solve(i+1,ans,temp,s);
             temp.pop_back();
         }
     }
     return;
  }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        if(s.empty())return ans;
        vector<string>temp;
        solve(0,ans,temp,s);
        return ans;
    }
};
