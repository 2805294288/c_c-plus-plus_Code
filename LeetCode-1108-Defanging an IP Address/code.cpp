//首先最能想到的用字符串替换。
//先找到.然后进行替换。
class Solution {
public:
    string defangIPaddr(string address) {
        for (int i = 0; i < address.length(); i++) {//遍历字符串
            if (address[i] == '.') {//找到.
                address.replace(i, 1, "[.]");//找到.以后进行替换成"[.]";
                i = i + 2;
            }
        }
        return address;
    }
};