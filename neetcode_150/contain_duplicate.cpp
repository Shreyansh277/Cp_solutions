class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int > mp;
        for(auto z: nums)
        {
            if(mp[z]>0)return true;
            mp[z]++;
        }

        return false;
    }
};
