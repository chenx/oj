
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;

        map<string, set<string>> map; // <email, adjacent_emails>
        for (auto e : accounts) {
            string email = e[1];
            for (int i = 2; i < e.size(); ++ i) {
                map[email].insert(e[i]);
                map[e[i]].insert(email);
            }
        }

        set<string> used;
        for (auto e : accounts) {
            string name = e[0];
            string email = e[1];
            if (used.contains(email)) continue;

            vector<string> act;
            dfs(map, act, email, used);

            sort(act.begin(), act.end());
            act.insert(act.begin(), name);
            ans.push_back(act);
        }
        return ans;
    }

    void dfs(map<string, set<string>>& map, vector<string>& a, string& email, set<string>& used) {
        a.push_back(email);
        used.insert(email);

        for (string next : map[email]) {
            if (! used.contains(next)) {
                dfs(map, a, next, used);
                used.insert(next);
            }
        }
    }
};

/**
721. Accounts Merge
Medium

Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, 
and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to 
both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the 
same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the 
rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.
 */
