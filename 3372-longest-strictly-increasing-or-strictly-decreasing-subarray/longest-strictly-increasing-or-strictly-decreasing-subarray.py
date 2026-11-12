class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        ans = 1

        i = 0
        cnt = 0
        while i < len(nums) - 1:
            cnt = 1
            if nums[i] < nums[i + 1]:
                while i < len(nums) - 1 and nums[i] < nums[i + 1]:
                    cnt += 1
                    i += 1
                    # if nums[
            elif nums[i] > nums[i + 1]:
                while i < len(nums) - 1 and nums[i] > nums[i + 1]:
                    cnt += 1
                    i += 1

            ans = max(ans, cnt)
            if cnt > 1:
                i -= 1
            i += 1
        return ans
