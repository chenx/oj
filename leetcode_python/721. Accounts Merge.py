# DFS
# Time: O(NKlogNK), n is number of accounts, K is max number of emails in an account. log is from sorting.
# Space: O(NK)
class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        def dfs(row, graph, used, email):
            row.append(email)
            used.add(email)

            if email in graph:
                for nextEmail in graph[email]:
                    if not nextEmail in used:
                        dfs(row, graph, used, nextEmail)


        graph : dict[str, set(str)] = {}
        for account in accounts:
            if account[1] not in graph:
                graph[account[1]] = set()
            for i in range(2, len(account)):
                if account[i] not in graph:
                    graph[account[i]] = set()
                graph[account[1]].add(account[i])
                graph[account[i]].add(account[1])
        
        result = []
        used = set()
        for account in accounts:
            name = account[0]
            email = account[1]
            if email in used:
                continue
            
            row = []
            dfs(row, graph, used, email)

            row.sort()
            row.insert(0, name)
            result.append(row)
        
        return result


/**
721. Accounts Merge
Solved
Medium
Topics
conpanies iconCompanies
Hint

Given a list of accounts where each element accounts[i] is a list of strings, where the first element 
accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there 
is some common email to both accounts. Note that even if two accounts have the same name, they may 
belong to different people as people could have the same name. A person can have any number of accounts 
initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each 
account is the name, and the rest of the elements are emails in sorted order. The accounts themselves 
can be returned in any order.

 

Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
 */
