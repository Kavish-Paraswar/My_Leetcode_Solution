import heapq


class Solution:
    def minGroups(self, intervals: list[list[int]]) -> int:
        intervals.sort()

        heap = []
        
        # heap[0] is smallest value or heap is empty 
        for start,end in intervals:
            if heap and heap[0] < start:
                heapq.heappop(heap)
            
            heapq.heappush(heap,end)
                
        return len(heap)
