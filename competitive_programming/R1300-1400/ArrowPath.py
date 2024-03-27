def solve():
    n = int(input())
    board1 = input()
    board2 = input()
    board = [board1, board2]
    cells = [(board[0][i:i + 2], board[1][i:i + 2]) for i in range(0, n, 2)]

    def is_valid(i):
        if cells[i][1][0] == '>':
            return True
        if cells[i][0][1] == '>' and (i == 0 or cells[i - 1][0][1] == '>'):
            return True
        return False

    valid = [is_valid(i) for i in range(0, len(cells))]
    for i in range(0, len(cells)):
        if valid[i] == False:
            print("NO")
            return
    print("YES")


t = int(input())
while t > 0:
    solve()
    t -= 1
