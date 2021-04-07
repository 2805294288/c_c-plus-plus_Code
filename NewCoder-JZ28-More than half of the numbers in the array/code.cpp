class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    sort(numbers.begin(),numbers.end());
    int mid = numbers.size() / 2; 
    int number = numbers[mid];
    int count = 0;
        for(auto& n: numbers)
        {
            if(number == n)
            {
                count++;
            }
            if(count > numbers.size()/ 2)
            {
                return number;
            }
        }
        return 0;
    }
};