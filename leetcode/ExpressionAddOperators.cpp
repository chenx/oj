// Works. Tested. Slightly improved from Solution.
class Solution2 {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        get(ans, num, target, 0, "", 0, 0);
        return ans;
    }
    
    void get(vector<string> &ans, string num, int target, 
            int pos, string path, long cur, long prev) {
        if (pos == num.length()) {
            if (cur == target) ans.push_back(path);
            return;
        }
        
        for (int i = pos; i < num.length(); ++ i) {
            if (num[pos] == '0' && i > pos) return;
            
            string str = num.substr(pos, i-pos+1);
            long val = stol(str);
            
            if (pos == 0) {
                get(ans, num, target, i+1, str, val, val);
            }
            else {
                get(ans, num, target, i+1, path+"+"+str, cur+val, val);
                get(ans, num, target, i+1, path+"-"+str, cur-val, -val);
                get(ans, num, target, i+1, path+"*"+str, cur-prev+val*prev, val*prev);
            }
        }
    }
};

// Works. From: https://leetcode.com/discuss/83351/recommend-beginners-implementation-detailed-explanation
// DFS.
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.size() == 0) return result;
        help(result, "", num, target, 0, 0, 0);
        return result;
    }

    void help(vector<string> &result, string path, string num, int target, int pos, long cur, long prev){
        if (pos == num.size()) {
            if (cur == target) result.push_back(path);
            return;
        }
        for (int i = pos; i < num.size(); ++ i){
            /*** corner-case-added-code: e.g., 1*05 is not valid. ***/
            if(num[pos] == '0' && i > pos) break;
            //if(num[pos] == '0' && i > pos && pos < num.size()) break; // this works too. should be this.
            string _str = num.substr(pos, i-pos+1);
            long _value = stol(_str);
            if (pos == 0) {
                help(result, path+_str, num, target, i+1, _value, _value);
            }
            else {
                help(result, path+"+"+_str, num, target, i+1, cur+_value, _value);
                help(result, path+"-"+_str, num, target, i+1, cur-_value, -_value);
                help(result, path+"*"+_str, num, target, i+1, cur-prev+prev*_value, prev*_value);
            }
        }
    }
};

/**
Expression Add Operators
Difficulty: Hard

Given a string that contains only digits 0-9 and a target value, 
return all possibilities to add binary operators (not unary) +, 
-, or * between the digits so they evaluate to the target value.

Examples:

"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []

 */
