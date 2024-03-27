#Python3 Code @BritoAlv
# D. Tandem Repeats?


def largest_consecutive(arr):
    ans = 0
    n = len(arr)
    i = 0
    while (i < n):
        start = i
        end = i
        while end + 1 < n and arr[end + 1] == arr[end] + 1:
            end += 1
        ans = max(ans, end - start + 1)
        i = end + 1
    return ans


def get_tandem(a):
    ans = 0
    for dist in range(2, len(a) + 1, 2):
        arr = []
        d = dist // 2
        for l in range(0, len(a)):
            r = l + d
            if r < len(a) and ((a[l] == a[r]) or ('?' in [a[l], a[r]])):
                arr.append(l)
        larg = largest_consecutive(arr)
        if larg >= d:
            ans = d
    return 2 * ans


t = int(input())
while t > 0:
    print(get_tandem(input()))
    t -= 1
