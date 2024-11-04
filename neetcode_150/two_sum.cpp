class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v(nums.size());
        for(int i=0;i<nums.size();i++)
        {
           v[i].first=nums[i];
           v[i].second=i;
        }
        sort(v.begin(),v.end());
        int i=0,j=nums.size()-1;

        while(i<j)
        {
            if(v[i].first+v[j].first==target)
            {
                return {min(v[i].second,v[j].second),max(v[i].second,v[j].second)};
            }
            else if(v[i].first+v[j].first<target)i++;
            else j--;
        }

        return {-1};
        
    }
};
