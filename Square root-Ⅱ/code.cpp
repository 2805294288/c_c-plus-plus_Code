class Solution {
public:
    /**
     * 
     * @param x int���� 
     * @return int����
     */
    //��ƽ������ʵ����Ϊ�˿�����ַ���
    
    //�����ڼ����ʱ��Ҫ��mid * mid����� ��mid = x / mid
    //����ͬʱ��ֱ�ӷ���
    //����ͬʱ��ȥ������
    int sqrt(int x) {
        if(x <= 1)
        {
            return x;
        }
        int head = 1;
        int tail = x;
        while(head <= tail)
        {
            int mid = (head + tail) / 2;
            if(mid == x / mid)
            {
                return mid;
            }
            else
            {
                if(mid < x / mid)
                {
                    head = mid + 1;
                }
                else
                {
                    tail = mid - 1;
                }
            }
        }
        return tail;
    }
};