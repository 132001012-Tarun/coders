//product of array except self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>l_product;
        int clp=1;
        for(int i=0;i<nums.size();i++)
        {
            clp=clp*nums[i];   
            l_product.push_back(clp); // storing the product from the left
        }
        int crp=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(i-1==-1)
            {
               nums[i]=crp;
                break;
            }
            int temp=nums[i];
            nums[i]=crp*l_product[i-1];
            crp*=temp;  // updating the right product by multiplying with the element
            
        }
       return nums; 
    }
};
