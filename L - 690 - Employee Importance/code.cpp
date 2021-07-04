/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void DFS(unordered_map<int,Employee*>& m, int& sum, int id)
    {

        sum += m[id]->importance;

        if((m[id] -> subordinates).size() == 0)
        {
            return;
        }
        
        for(auto& s: m[id]->subordinates)
        {
            DFS(m,sum,s);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        if(employees.size() < 1)
        {
            return 0;
        }
        unordered_map<int,Employee*> m;
        for(auto& e:employees)
        {
            m[e->id] = e;
        }

        int sum = 0;
        DFS(m,sum,id);
        return sum;
    }
};