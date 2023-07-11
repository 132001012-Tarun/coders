//CONTAINER WITH MOST WATER


// first think of brute force method it is possible in o(n*n)
// then try to optimize it think of o(nlog(n)) this is also not possible as it innvolves some kind of sorting techniques sorting will change the indexing 
//here so it is not possible think of o(n) it may be possible less than that is not possible as we have to iterate through each height so o(n) might be the best optimization

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;int j=height.size()-1;
        int max_area=0;
        while(i<j)
        {
            if(height[i]<height[j])
            {
                max_area=max(max_area+0LL,(j-i)*(height[i])*1LL);
                i++;
            }
            else
            {
                max_area=max(max_area+0LL,(j-i)*(height[j])*1LL);
                j--;
            }
        }
        return max_area;
    }
};
