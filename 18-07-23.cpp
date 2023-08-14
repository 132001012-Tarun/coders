// Search in a 2D matrix



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int left=0;
        int right=m*n-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            int mid_val=matrix[mid/m][mid%m];      // this is the main line in this code
            if(target==mid_val)
            {
                return true;
            }
            else if(target>mid_val){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return false;
    }
};
