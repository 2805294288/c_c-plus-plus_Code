class Solution {
public:
    void Func(vector<int>& nums, vector<int>& used)
    {
        if(part.size() == nums.size())
        {
            ret.push_back(part);
            return;
        }

        unordered_set<int> se;
        for(int i = 0; i < nums.size(); i++)
        {
            if( !se.empty() && se.find(nums[i]) != se.end())
            {
                continue;
            }

            if(used[i] == 0)
            {
                se.insert(nums[i]);
                used[i] = 1;
                part.push_back(nums[i]);
                Func(nums,used);
                part.pop_back();
                used[i] = 0;
            }  
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //sort(nums.begin(),nums.end());
        vector<int> used(nums.size(),0);
        Func(nums,used);
        return ret;
    }
private:
        vector<vector<int>> ret;
        vector<int> part;
};