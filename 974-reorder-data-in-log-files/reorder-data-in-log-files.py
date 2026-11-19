class Solution:
    def reorderLogFiles(self, logs: list[str]) -> list[str]:

        letters = {}
        digits = []
        # kay karotys
        for log in logs:

            cur_identifier = ""

            arr = list(log.split(" "))
            cur_identifier = arr[0]

            if arr[1].isdigit():

                digits.append(log)
            else:
                # string separated by space
                new_s = " ".join(arr[1:])
                letters[(new_s, cur_identifier)] = log

        l = sorted(letters.keys())

        ls = []
        for k in l:
            ls.append(letters[k])

        ls += digits

        return ls
