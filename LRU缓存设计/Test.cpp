class Solution {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    void set(int& key, int& value)
    {
        auto Mit = _Map.find(key);
        if(Mit == _Map.end())
        {
            if(_List.size() >= _CapaCity)
            {
                auto MMit = _Map.find(_List.front().first);
                _Map.erase(MMit);
                _List.pop_front();
            }
            _List.push_back(make_pair(key, value));
            _Map[key] = --_List.end();
        }
        else
        {
            auto Lit = Mit->second;
            Lit->second = value;
            
            _List.splice(_List.end(), _List, Lit);
            _Map[key] = --_List.end();
        }
    }
    int get(int& key)
    {
        auto Mit = _Map.find(key);
        if(Mit == _Map.end())
        {
            return -1;
        }
        
        auto Lit = Mit->second;
        _List.splice(_List.end(), _List, Lit);
        _Map[key] = --_List.end();
        
        return Lit->second;
    }
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        _CapaCity = k;
        vector<int> ret;
        for(auto& ve:operators)
        {
            if(ve[0] == 1)
            {
                set(ve[1],ve[2]);
            }
            else
            {
                ret.push_back(get(ve[1]));
            }
        }
        return ret;
    }
private:
    list<pair<int,int>> _List;
    unordered_map<int, list<pair<int,int>>::iterator> _Map;
    int _CapaCity;
};