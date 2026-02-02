class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        if startGene == endGene:
            return 1
        
        bankSet = set(bank)
        choices = ['A', 'C', 'G', 'T']

        q = collections.deque([startGene])
        used = set([startGene])

        steps = 0
        while q:
            steps += 1
            for i in range(len(q)):
                gene = q.popleft()
                # for each letter of gene, try all possibilities

                for j in range(len(gene)):
                    for choice in choices:
                        if gene[j] == choice:
                            continue
                        nextGene = gene[:j] + choice + gene[j+1:]
                        if nextGene in bankSet and not nextGene in used:
                            if nextGene == endGene:
                                return steps
                            q.append(nextGene)
                            used.add(nextGene)

        return -1


/**
433. Minimum Genetic Mutation
Solved
Medium
Topics
conpanies iconCompanies

A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where 
one mutation is defined as one single character changed in the gene string.

    For example, "AACCGGTT" --> "AACCGGTA" is one mutation.

There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make 
it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of 
mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.
 */
