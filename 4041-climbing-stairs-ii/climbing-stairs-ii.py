class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        dp = [-1] * (n + 1)
        dp[0] = 0

        def rec(i):
            if i == 0:
                return 0
            if i < 0:
                return float("inf")
            if dp[i] != -1:
                return dp[i]

            take_one = float("inf")
            take_two = float("inf")
            take_three = float("inf")

            if i - 1 >= 0:
                take_one = rec(i - 1) + costs[i - 1] + 1
            if i - 2 >= 0:
                take_two = rec(i - 2) + costs[i - 1] + 4
            if i - 3 >= 0:
                take_three = rec(i - 3) + costs[i - 1] + 9

            dp[i] = min(take_one, take_two, take_three)
            return dp[i]

        return rec(n)
