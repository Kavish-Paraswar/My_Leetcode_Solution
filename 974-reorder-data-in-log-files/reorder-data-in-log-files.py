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
        # let2 own kit dig
        # key = own kit dig , we will store all  spaces = 4,8
        # we will push ownkitdig , rather than own kit dig

        l = sorted(letters.keys())
        # dict valyes cant be sorted direclty
        #  are bhai type cast kelela ki re asa kay karotys 
        # we need
        ls = []
        for k in l:
            ls.append(letters[k])

        ls += digits

        return ls
