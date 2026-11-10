class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        costs = [0] + costs
        dp = [-1] * (n + 1)

        def rec(i):
            if i == n:
                return 0

            if dp[i] != -1:
                return dp[i]

            take_one = float("inf")
            take_two = float("inf")
            take_three = float("inf")

            if i + 1 <= n:
                take_one = rec(i + 1) + costs[i + 1] + 1

            if i + 2 <= n:
                take_two = rec(i + 2) + costs[i + 2] + 4

            if i + 3 <= n:
                take_three = rec(i + 3) + costs[i + 3] + 9

            dp[i] = min(take_one, take_two, take_three)

            return dp[i]

        return rec(0)
