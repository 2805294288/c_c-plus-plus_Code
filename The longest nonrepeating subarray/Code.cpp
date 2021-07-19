
//双指针法
class Solution {
public:
    /**
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
    
    //
    int maxLength(vector<int>& arr) {
        if(arr.size() <= 1)
        {
            return 1;
        }
        
        int head = 0;
        int j = 0;
        int size = 0;
        int tail = 1;
        for(tail = 1; tail < arr.size(); tail++)
        {
            
            for(j = head; j < tail; j++)
            {
                if(arr[j] == arr[tail])
                {
                    break;
                }
            }
            
            if(j != tail)
            {
                size = max(size,tail-head);
                head = j + 1;
            }
        }
        
        size = max(size,tail-head);
        return size;
    }
};