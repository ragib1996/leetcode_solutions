

class Solution
{
public:
    int removeDuplicates(vector <int>& nums)
    {
        int i, j, k, l;
        l = 0;
        for (i = 1; i < nums.size(); )
        {
            if (nums[i] == nums[l])
            {
                nums.erase(nums.begin() + i);
            }
            else
            {
                l++;
                i++;
            }
        }
        return l + 1;
    }
};