//Search in a rotated array


// intuition just think of two cases like wheater mid is greater than l or less than l then inside those contions think of what you need
class Solution {
public:
    int search(vector<int>& nums, int target) {
       
            int s=0;
            int e=nums.size()-1;
            int mid=s+(e-s)/2;
            while(s<=e)
            {
                mid=s+(e-s)/2;
                if(target==nums[mid])
                {
                    return mid;
                }
                if(s==mid){s+=1;continue;}   // if h=l+1 then mid will always be l only so it ios necessary
                if(nums[mid]>nums[s])
                {
                    if(target>=nums[s]&&target<nums[mid])
                    {
                        e=mid-1;
                    }
                    else{
                        s=mid+1;
                    }
                }
                else 
                {
                    if(target>nums[mid] and target<=nums[e])s=mid+1;
                    else e=mid-1;
                }
            }
       return -1;
    }
};
