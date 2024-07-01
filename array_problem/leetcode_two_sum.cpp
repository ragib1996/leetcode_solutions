class Solution
{
public:
    vector <int> twoSum(vector <int> num, int target)
    {
        vector <int> v;
        int n = num.size();
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                s = num[i] + num[j];
                if (s == target)
                {
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
            }
        }


        return v;
    }



};