//Maximum Product Subarray

// checking from both left and right helps to maximize from both if you are confused then just think of a negative number in between array

class Solution {
public:
    int maxProduct(vector<int>& nums) {

       int left = INT_MIN, right = INT_MIN;
      int x = 1, y=1;

      for(int i=0;i<nums.size();i++)
      {

         x*=nums[i];
          left = max(left, x);
         if(x==0) x =1;
      }

      for(int i=(nums.size()-1); i>=0;i--)
      {
        y*=nums[i];
         right = max(right, y);
        if(y==0) y=1;
       
      }

      return max(left, right);
        
    }
};
