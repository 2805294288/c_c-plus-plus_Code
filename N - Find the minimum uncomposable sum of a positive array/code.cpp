class Solution {
public:
	/**
	 *	正数数组中的最小不可组成和
	 *	输入：正数数组arr
	 *	返回：正数数组中的最小不可组成和
	 */
    vector<vector<int>> ret;
    vector<int> path;
    
    void Func(vector<int>& arr,int state)
    {
        ret.push_back(path);
        if(state >= arr.size())
        {
            return;
        }
        
        for(int i = state; i < arr.size(); i++)
        {
            path.push_back(arr[i]);
            Func(arr,i+1);
            path.pop_back();
        }
    }
    
	int getFirstUnFormedNum(vector<int> arr, int len) {
        sort(arr.begin(),arr.end());
        int min = arr[0];
        int max = 0;
        for(auto& n: arr)
        {
            max += n;
        }
        
        ret.clear();
        path.clear();
        
        Func(arr,0);
        vector<int> Vsum;
        int sum = 0;
        for(auto& v: ret)
        {
            sum = 0;
            if(v.size() != 0)
            {
                for(auto& n: v)
                {
                    sum += n;
                }
                Vsum.push_back(sum);
            }
        }
        
        
        int i = 0;
        int j = 0;
        for(i = min; i <= max; i++)
        {
            for(j = 0; j < Vsum.size(); j++)
            {
                if(Vsum[j] == i)
                {
                    break;
                }
            }
            if(j == Vsum.size())
            {
                return i;
            }
        }
        
        return max + 1;
    }
};

























