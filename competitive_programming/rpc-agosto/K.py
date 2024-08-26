# press the shift key costs 1
p = 1
while p > 0:
        ans = 0
        s = input()
        shift_on = False

        i = 0
        while i < len(s):
            pt = i
            while pt < len(s) and s[i].lower() == s[pt].lower():
                if s[pt].isupper() and not shift_on:
                    ans += 1
                    shift_on = True
                if s[pt].islower() and shift_on:
                    shift_on = False
                pt += 1
            ans += 1
            i = pt        
        print(ans)
        p -= 1