class Solution2:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        result = []

        map : dict[nominator, set(tuple(denominator, value))] = {}
        for i in range(len(equations)):
            if equations[i][0] not in map:
                map[equations[i][0]] = set()
            if equations[i][1] not in map:
                map[equations[i][1]] = set()
            map[equations[i][0]].add((equations[i][1], values[i]))
            map[equations[i][1]].add((equations[i][0], 1.0 / values[i]))

        for query in queries:
            start = query[0]
            end = query[1]

            if start not in map:
                result.append(-1.0)
                continue
            if start == end:
                result.append(1.0)
                continue

            q = collections.deque( [(start, 1.0)] )
            used = set([start]) # must use [], otherwise set("aa") = {"a"} !!!

            found = False
            while q:
                var, val = q.popleft()
                print(f"var = {var}")
                
                for nextVar, nextVal in map[var]:
                    if nextVar not in used:
                        if nextVar == end:
                            result.append(val * nextVal)
                            found = True
                            break
                        q.append( (nextVar, val * nextVal) )
                        used.add(nextVar)
                
                if found:
                    break

            if not found:
                result.append(-1.0)

        return result


class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        result = []

        map : dict[nominator, set(tuple(denominator, value))] = {}
        for i in range(len(equations)):
            if equations[i][0] not in map:
                map[equations[i][0]] = set()
            if equations[i][1] not in map:
                map[equations[i][1]] = set()
            map[equations[i][0]].add((equations[i][1], values[i]))
            map[equations[i][1]].add((equations[i][0], 1.0 / values[i]))

        for query in queries:
            start = query[0]
            end = query[1]

            if start not in map:
                result.append(-1.0)
                continue
            if start == end:
                result.append(1.0)
                continue

            q = collections.deque()
            used = set(start)
            for var, val in map[start]:
                q.append( (var, val) )
                used.add( var )

            found = False
            while q:
                var, val = q.popleft()
                if var == end:
                    result.append(val)
                    found = True
                    break
                
                for nextVar, nextVal in map[var]:
                    if nextVar not in used:
                        q.append( (nextVar, val * nextVal) )
                        used.add(nextVar)
                    
            if not found:
                result.append(-1.0)

        return result
      

/**
399. Evaluate Division
Solved
Medium
Topics
conpanies iconCompanies
Hint

You are given an array of variable pairs equations and an array of real numbers values, 
where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. 
Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query 
where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not 
result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the 
answer cannot be determined for them.
 */
