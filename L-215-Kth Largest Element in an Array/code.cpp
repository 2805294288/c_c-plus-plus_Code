class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //sort(nums.begin(),nums.end());
        //return nums[nums.size()-k];

        // priority_queue<int> p(nums.begin(),nums.end());

        // for(int i=1; i<k; i++)
        // {
        //     p.pop();
        // }

        // return p.top();

        // priority_queue< int, vector<int>, greater<int> > q(nums.begin(),nums.begin()+k);

        // for(int i=k; i<nums.size(); i++)
        // {
        //     if(nums[i] > q.top())
        //     {
        //         q.pop();
        //         q.push(nums[i]);
        //     }
        // }
        // return q.top();
    }
};