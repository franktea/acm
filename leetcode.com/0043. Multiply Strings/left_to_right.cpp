// 在字符数串s的第index个字符上加上val，可能会产生进位
void add_char(string& s, int index, int val)
{
    int tmp = s[index] - '0' + val;
    s[index] = tmp % 10 + '0';
    if(tmp / 10 > 0) // 进位，再加一次
        add_char(s, index - 1, tmp / 10);
}

// 模拟珠算乘法，从左往右算
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        
        // result的位数最多是num1的长度加上num2的长度，或是len(num1) + len(num2) - 1
        // 先按照最大长度分配内存，最后在去掉前导的0
        string result(num1.size() + num2.size(), '0');
        
        // 从左往右算
        for(int i = 0; i < num1.size(); ++i) // 这里其实是乘数
        {
            for(int j = 0; j < num2.size(); ++j) // 这里是被乘数
            {
                int tmp = (num1[i] - '0') * (num2[j] - '0');
                add_char(result, i + j + 1, tmp);
            }
        }
        
        // 去掉前导的一个0
        if(result[0] == '0')
            result.erase(0, 1);
        
        return result;
    }
};
