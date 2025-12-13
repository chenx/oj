// Time: O(n + k log(k)), k = number of valid coupons.
// Space: O(n)
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<vector<string>> result;

        int n = code.size();
        for (int i = 0; i < n; ++ i) {
            if (isValidCode(code[i]) && isValidBusLine(businessLine[i]) && isActive[i]) {
                result.push_back({code[i], businessLine[i]});
            }
        }

        auto comp = [&](const vector<string>& a, const vector<string>& b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        };
        sort(result.begin(), result.end(), comp);

        vector<string> ans;
        for (const auto& item : result) {
            ans.push_back(item[0]);
        }
        return ans;
    }

    bool isValidBusLine(string& line) {
        return line == "electronics" || line == "grocery" || line== "pharmacy" || line == "restaurant";
    }

    bool isValidCode(string& code) {
        if (code.empty()) return false;
        for (char ch : code) {
            if (! (isalnum(ch) || ch == '_')) return false;
        }
        return true;
    }
};


/**
3606. Coupon Code Validator
Solved
Easy
Topics
Hint

You are given three arrays of length n that describe the properties of n coupons: code, businessLine, and isActive. The ith coupon has:

    code[i]: a string representing the coupon identifier.
    businessLine[i]: a string denoting the business category of the coupon.
    isActive[i]: a boolean indicating whether the coupon is currently active.

A coupon is considered valid if all of the following conditions hold:

    code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).
    businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
    isActive[i] is true.

Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order within each category.

 

Example 1:

Input: code = ["SAVE20","","PHARMA5","SAVE@20"], businessLine = ["restaurant","grocery","pharmacy","restaurant"], isActive = [true,true,true,true]

Output: ["PHARMA5","SAVE20"]
 */
