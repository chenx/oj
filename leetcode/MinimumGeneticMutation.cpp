// Identical to the WordLadder problem. Only difference is return step instead of 1+step.
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene) return 1;

        unordered_set<string> geneBank;
        for (auto& gene : bank) geneBank.insert(gene);

        queue<pair<string, int>> q; // <gene, length>
        q.push(pair<string, int>(startGene, 1));

        set<string> visited;
        visited.insert(startGene);

        vector<char> options = {'A', 'C', 'G', 'T'};

        while (!q.empty()) {
            string gene = q.front().first;
            int step = q.front().second;
            q.pop();

            for (int i = 0; i < gene.length(); ++ i) {
                char c = gene[i];
                for (char j : options) {
                    if (c == j) continue;
                    gene[i] = j;

                    if (geneBank.contains(gene) && !visited.contains(gene)) {
                        if (gene == endGene) return step;
                        q.push(pair<string, int>(gene, 1 + step));
                        visited.insert(gene);
                    }
                }
                gene[i] = c;
            }
        }
        return -1;
    }
};

/**
433. Minimum Genetic Mutation

A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation 
is defined as one single character changed in the gene string.

    For example, "AACCGGTT" --> "AACCGGTA" is one mutation.

There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid 
gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations 
needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.
 */
