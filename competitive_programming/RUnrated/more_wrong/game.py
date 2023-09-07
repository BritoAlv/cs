import random
def game(n):
    permutation = [i for i in range(1, n+1)]
    random.shuffle(permutation)
    max_coins = 5*n*n
    used_coins = 0
    while used_coins <= max_coins:
        line = input().split(" ")
        answer = -1
        if line[0] == '!':
            answer = int(line[1])
            break
        l = int(line[0])
        r = int(line[1])
        if l == r:
            break
        if used_coins + (r-l)*(r-l) <= max_coins:
            used_coins = used_coins + (r-l)*(r-l)
            inversions = 0
            for i in range(l-1, r):
                for j in range(i+1, r):
                    if permutation[i] > permutation[j]:
                        inversions = inversions + 1
            
            print("Hay", end = " ")
            print(inversions, end = " inversiones. ")
            print("Has usado", end = " ")
            print(used_coins, end = " monedas, ")
            print("de un total de", end = " ")
            print(max_coins)
        else:
            print( "No tienes dinero para hacer esta operación" )

    index = 1
    max = permutation[0]
    for i in range(2, n+1):
        if permutation[i-1] > max:
            max = permutation[i-1]
            index = i
    print("Usaste un total de", end= " ")
    print(used_coins, end = " ")
    print("monedas")
    print("La respuesta es", end = " ")
    print(index)
    print(permutation)        

game(10)
