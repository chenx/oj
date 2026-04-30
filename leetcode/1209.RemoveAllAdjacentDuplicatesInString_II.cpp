class Solution2 {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;

        for (int i = 0; i < s.length(); ++ i) {
            if (! st.empty() && s[i] == st.back().first) {
                if (st.back().second == k-1) {
                    st.pop_back();
                } else {
                    st.back().second ++;
                }
            } else {
                st.push_back({s[i], 1});
            }
        }

        string ans;
        for (int i = 0; i < st.size(); ++ i) {
            char t = st[i].first;
            int ct = st[i].second;
            ans = ans + string(ct, t);
        }
        return ans;
    }
};


class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for (int i = 0; i < s.length(); ++ i) {
            if (! st.empty() && s[i] == st.top().first) {
                if (st.top().second == k-1) {
                    st.pop();
                } else {
                    st.top().second ++;
                }
            } else {
                st.push({s[i], 1});
            }
        }

        string ans;
        while (! st.empty()) {
            char t = st.top().first;
            int ct = st.top().second;
            ans = string(ct, t) + ans;
            st.pop();
        }
        return ans;
    }
};


/**
1209. Remove All Adjacent Duplicates in String II
Medium

You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, 
causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.
 */
