class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int newsize = 0;//jilu新vector的个数
        int k=0;
        int number = 0;

        for(int i=0; i<nums.size()-1; i+=2)//对每一对前一个频率进行相加得到newszie
        {
            newsize += nums[i];
        }
        
        vector<int> Newnums(newsize,0);//新vector容器

        for(int i=1,j=0; i<nums.size(); i+=2,j+=2)//将解压缩编码列表存储在新容器之中
        {
            number = nums[j];
            while(number)
            {
                Newnums[k++] = nums[i];
                number--;
            }
        }

        return Newnums;
    }
};