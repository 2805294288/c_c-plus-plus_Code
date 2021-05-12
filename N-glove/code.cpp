class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        int left_sum = 0;
        int right_sum = 0;
        int left_min = INT_MAX;
        int right_min = INT_MAX;
        int sum = 0;
        
        for(int i=0; i<n; i++)
        {
            if(left[i]*right[i] == 0)
            {
                sum += (left[i] + right[i]);
            }
            else
            {
                left_sum += left[i];
                right_sum += right[i];
                left_min = min(left_min, left[i]);
                right_min = min(right_min, right[i]);
            }
        }
        return sum + min(left_sum - left_min + 1,  right_sum - right_min + 1) + 1;
    }
};