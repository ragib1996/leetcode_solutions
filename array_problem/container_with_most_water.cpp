class Solution
{
public:
    int maxArea(vector<int>& height) 
    {
        int left, right, c_area, maxarea = 0;
        left = 0; right = height.size() - 1;
        
        while (left < right)
        {
            c_area = (right - left) * min( height[left] , height[right] );
            if (c_area > maxarea )
            {
                maxarea = c_area;
            }

            if ( height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxarea;
    }
};