class Solution {
public:
    void Func(vector<int>& candidates, int& target, int state, int sum,vector<bool>&used)
    {
        if(sum == target)
        {
            ret.push_back(path);
            return;
        }

        for(int i = state; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            if(i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false)
            {//如果当前一个和上一个是一样的，且上一个是true代表用过了。在同一个支树上，不影响，如果这个和上一个相同，且上一个为false代表上一个没有在本支树上，则肯定在，同一层上。
                continue;
            }

            path.push_back(candidates[i]);
            used[i] = true;
            Func(candidates,target,i+1,sum + candidates[i],used);
            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);//先将原本开好的空间全部初始化为false，代表没用过。
        sort(candidates.begin(),candidates.end());
        Func(candidates,target,0,0,used);
        return ret; 
    }
private:
    vector<vector<int>> ret;
    vector<int> path;
};