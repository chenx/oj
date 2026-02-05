# DFS
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        def dfs(airport):
            targetAirports = outBound[airport] if airport in outBound else []
            while targetAirports:
                dfs(targetAirports.pop())
            result.append(airport)

        outBound : dict[str, list[str]] = {} 
        for fromAirport, toAirport in tickets:
            if not fromAirport in outBound:
                outBound[fromAirport] = []
            outBound[fromAirport].append(toAirport)
        
        for key in outBound.keys():
            outBound[key].sort(reverse=True)
        
        result = []
        dfs("JFK")
        result.reverse()
        return result


# BFS
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        outBound : dict[str, list[str]] = {} 
        for fromAirport, toAirport in tickets:
            if not fromAirport in outBound:
                outBound[fromAirport] = []
            outBound[fromAirport].append(toAirport)
        
        for key in outBound.keys():
            outBound[key].sort(reverse=True)
        
        result = []
        stack = ["JFK"]
        while stack:
            airport = stack[-1]
            # targetAirports is a reference to outBound[airport]
            targetAirports = outBound[airport] if airport in outBound else []

            if not targetAirports:
                result.append(airport)
                stack.pop()
            else:
                # stack.append(targetAirports[0])
                # targetAirports.pop(0)
                stack.append(targetAirports[-1])
                targetAirports.pop() # pop from end is much faster than from beginning (0)
        
        result.reverse()
        return result

/**
332. Reconstruct Itinerary
Solved
Hard
Topics
conpanies iconCompanies

You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the 
arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". 
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical 
order when read as a single string.

    For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].

You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.
 */
