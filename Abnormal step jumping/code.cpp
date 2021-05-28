class Solution {
public:
    int jumpFloorII(int number) {
    vector<int> v(number,1);
    for(int i=1; i < number; i++)
    {
        v[i] = 2*v[i-1];
    }
        return v[number-1];
    }
};