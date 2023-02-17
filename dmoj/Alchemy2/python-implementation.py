# this solution is accepted but needs refactoring, 
def excercise(N, numbers):
    # count how many times each b_is appear.
    count_bis = [0 for i in range(0, N)]
    count_biss = [0 for i in range(0,N)]
    result = [0 for i in range(0, N)]  # final results.
    # index to map element if need reachability of b_i.
    b_is = [-1 for i in range(0, N)]
    first_multiple = [0 for i in range(0, N)]
    # four array are zero indexed, and our exercise is 1-index, what a shit.

    # first for
    for i in range(0, N):
        n = int(numbers[i])  # parse to int.

        if n == 1:
            result[i] = i+1
        elif b_is[n-1] != -1:
            result[i] = b_is[n-1]
        count_bis[n-1] = count_bis[n-1]+1
        count_biss[n-1] = count_biss[n-1]+1
        if count_bis[n-1] == 1:
            first_multiple[n-1] = i+1
        if count_bis[n-1] == n:
            result[first_multiple[n-1]-1] = i+1
            count_bis[n-1] = 0
            count_biss[n-1] = 0
        b_is[n-1] = i+1

    # second for:
    for i in range(0, N):
        n = int(numbers[i])
        if n == 1:
            continue
        # at this point each key has been documented, option one key-1 is present
        elif b_is[(n-1) - 1] != -1:
            result[i] = b_is[(n-1)-1]
        else:
            # at this point what do we do?
            # how do we stop the process? or it repeats itself,
            # is clear that if for some key the count of b_is is not multiple of the key we should break this thing.
            if count_bis[n-1] % n != 0:
                print(-1)
                return
            else:
                count_biss[n-1] = count_biss[n-1]+1
                if count_biss[n-1] == 1:
                    first_multiple[n-1] = i+1
                if count_biss[n-1] == n:
                    result[first_multiple[n-1]-1] = i+1
                    count_biss[n-1] = 0 
            result[i] = b_is[n-1]
            b_is[n-1] = i+1

    for value in result:
        print(value, end=" ")


#excercise(11, ["3", "3", "3", "5", "5", "3", "5","5"])
N = int(input())
numbers = input().split(" ")
excercise(N, numbers)
