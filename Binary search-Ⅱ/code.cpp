class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * ���Ŀ��ֵ���ڷ����±꣬���򷵻� -1
     * @param nums int����vector 
     * @param target int���� 
     * @return int����
     */
    int search(vector<int>& nums, int target) {
        if(nums.size() <= 0)
        {
            return -1;
        }
        
        int head = 0;
        int tail = nums.size() - 1;
        while(head <= tail)
        {
            int mid = (head + tail) / 2;
            if(nums[mid] >= target)
            {
                tail = mid - 1;
            }
            else
            {
                head = mid + 1;
            }
        }
        if(nums[head] == target)
        {
            return head;
        }
        return -1;
    }
};