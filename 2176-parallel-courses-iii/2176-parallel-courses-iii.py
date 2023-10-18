from collections import defaultdict

class Solution:
    def minimumTime(self, n, prerequisites, courseTimes):
        prerequisitesGraph = defaultdict(list)

        for i in range(n + 1):
            prerequisitesGraph[i] = []

        
        for relation in prerequisites:
            prerequisitesGraph[relation[0]].append(relation[1])

        memo = [-1] * (n + 1)  
        maxTime = 0

        
        for course in range(1, n + 1):
            maxTime = max(maxTime, self.dfs(course, memo, prerequisitesGraph, courseTimes))
        return maxTime

    
    def dfs(self, currentCourse, memo, prerequisitesGraph, courseTimes):
        if memo[currentCourse] != -1:
            return memo[currentCourse] 
        maxTime = 0

        
        for prerequisite in prerequisitesGraph[currentCourse]:
            maxTime = max(maxTime, self.dfs(prerequisite, memo, prerequisitesGraph, courseTimes))

        memo[currentCourse] = maxTime + courseTimes[currentCourse - 1]
        return memo[currentCourse]