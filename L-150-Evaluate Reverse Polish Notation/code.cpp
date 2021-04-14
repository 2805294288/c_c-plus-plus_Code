class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> Inst;
        int Nleft = 0;
        int Nright = 0;

        for(auto& st:tokens)
        {
            if(st == "+" || st == "-" || st =="*" || st == "/")
            {
                Nright = Inst.top();
                Inst.pop();
                Nleft = Inst.top();
                Inst.pop();

                switch(st[0])
                {
                    case('+'):
                        Inst.push(Nleft+Nright);
                        break;
                    case('-'):
                        Inst.push(Nleft-Nright);
                        break;
                    case('*'):
                        Inst.push(Nleft*Nright);
                        break;
                    case('/'):
                        Inst.push(Nleft/Nright);
                        break;
                }
            }
            else
            {
                Inst.push(stoi(st));
            }
        }
        return Inst.top(); 
    }
};