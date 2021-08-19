class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<int> arr1(0);
        int ret = 0;
        for(auto& x1: points)
        {
            ret = 0;
            for(auto& x2: x1)
            {
                ret += x2*x2;
            }
            arr1.push_back(ret);
        }

        vector<int> arr2(0);
        for(auto& x3:arr1)
        {
            arr2.push_back(x3);
        }

        sort(arr2.begin(),arr2.end());

        vector<vector<int>> result;
        int i=0,j=0;
        for(i=0; i<k; i++)
        {
            for(j=0; j<arr1.size(); j++)
            {
                if(arr2[i]==arr1[j])
                {
                    vector<int> arr3(0);
                    arr3.push_back(points[j][0]);
                    arr3.push_back(points[j][1]);
                    result.push_back(arr3);
                    break;
                }    
            }
            arr1[j]=0;
        }
        return result;
    }
};