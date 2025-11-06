// From https://leetcode.com/problems/accounts-merge/editorial/
class Solution {
    HashSet<String> visited;
    Map<String, List<String>> adjacent;
    
    private void DFS(List<String> mergedAccount, String email) {
        visited.add(email);
        mergedAccount.add(email);
        
        if (!adjacent.containsKey(email)) return;
        
        for (String neighbor : adjacent.get(email)) {
            if (!visited.contains(neighbor)) {
                DFS(mergedAccount, neighbor);
            }
        }
    }
    
    public List<List<String>> accountsMerge(List<List<String>> accountList) {
        visited = new HashSet<>();
        adjacent = new HashMap<String, List<String>>();

        for (List<String> account : accountList) {
            // Building adjacency list for emails.
            String accountFirstEmail = account.get(1);
            for (int j = 2; j < account.size(); j++) {
                String accountEmail = account.get(j);
                
                adjacent.putIfAbsent(accountFirstEmail, new ArrayList<String>());
                adjacent.get(accountFirstEmail).add(accountEmail);
                
                adjacent.putIfAbsent(accountEmail, new ArrayList<String>());
                adjacent.get(accountEmail).add(accountFirstEmail);
            }
        }
        
        // Traverse over all the accounts to store components
        List<List<String>> mergedAccounts = new ArrayList<>();
        for (List<String> account : accountList) {
            String accountName = account.get(0);
            String accountFirstEmail = account.get(1);
            
            // If email is visited, then it's a part of different component
            // Hence perform DFS only if email is not visited yet
            if (!visited.contains(accountFirstEmail)) {
                List<String> mergedAccount = new ArrayList<>();
                // Adding account name at the 0th index
                mergedAccount.add(accountName);
                
                DFS(mergedAccount, accountFirstEmail);
                Collections.sort(mergedAccount.subList(1, mergedAccount.size())); // !!!
                mergedAccounts.add(mergedAccount);
            }
        }
        
        return mergedAccounts;
    }
}


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
