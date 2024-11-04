class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);
        if(s.size()!=t.size())return false;
        else
        {
            for(int i=0;i<s.size();i++)
            {
                v[s[i]-'a']++;
                v[t[i]-'a']--;
            }

            for(auto z: v)if(z)return false;

            return true;
        }
    }
};
