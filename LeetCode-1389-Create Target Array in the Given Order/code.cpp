class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> ret;
        int it=0;
        
        while(it < index.size())
        {
            ret.insert(ret.begin()+index[it],nums[it]);
            it++;
        }
        return ret;
    }
};