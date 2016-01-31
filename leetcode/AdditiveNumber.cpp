class Solution {
public:
    bool isAdditiveNumber(string num, string last1, string last2) {
         if ((num[0] == '0' && num.length() > 1) || 
             (last1[0] == '0' && last1.length() > 1) || 
             (last2[0] == '0' && last2.length() > 1))
        return false;
    
        long long sum = stoll(last1) + stoll(last2);
        int len = (int)log10(sum) + 1;
        if (sum != stoll(num.substr(0, len))) return false;
        //if (num.substr(len).length() == 0) return true;
        if (len == num.length()) return true;
        
        return isAdditiveNumber(num.substr(len), last2, num.substr(0, len));
    }
    
    bool isAdditiveNumber(string num) {
        for (int i = 1; i < num.length(); ++ i) {
            for (int j = 1, lenj = num.length() - i; j < lenj; ++ j) {
                if (isAdditiveNumber(num.substr(i + j), num.substr(0, i), num.substr(i, j)))
                    return true;
            }
        }
    
        return false;
    }
};

