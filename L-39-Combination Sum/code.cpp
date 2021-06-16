class Solution {
public:
//经典回溯算法题，既然可以复用自身 则每次都从自身开始
//如果是组合则就是无序的，即只能往后走。
    void Func(vector<int>& candidates, int& target, int sum,int state)
    {
        if(sum > target)
        {
            return;//当和已经大于目标数字则返回。剪枝。
        }
        if(sum == target)
        {
            ret.push_back(path);
            return;
        }

        for(int i = state; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);//保存当前路径
            Func(candidates,target,sum+candidates[i],i);//每次从i开始即复用了自己
            path.pop_back();//回溯
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        int state = 0;
        Func(candidates,target,sum,state);
        return ret;
    }
 private:
    vector<vector<int>> ret;
    vector<int> path;
};