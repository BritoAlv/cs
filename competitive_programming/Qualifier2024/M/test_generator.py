max = 100

def generate_random_string():
    import random
    import string
    n = 5000
    return ''.join(random.choices(string.ascii_lowercase, k=n))

def generate_test() -> str:
    import random
    N_Test_Cases = 1000
    test = ""
    for _ in range(N_Test_Cases):
        n = random.randint(1, 10)
        m = random.randint(1,5)
        test += str(n) + " " + str(m) + "\n" 
        for i in range(n):
            st = random.randint(1, 10)
            ed = random.randint(st+1, st + 20)
            d = random.randint(1, ed -st)
            test += str(d) + " " + str(st) + " " + str(ed)   +"\n"
    test += "0" + "\n"
    return test

def generate_graph() -> str:
    import random
    N_Test_Cases = 1000
    test = ""
    for _ in range(N_Test_Cases):
        n = random.randint(2, 5)
        g = random.randint(1, n)
        edges = set()
        for _ in range(n*(n-1)//2):
            one = random.randint(1, n-1)
            two = random.randint(one+1, n)
            edges.add( (one, two) )

        test += str(n) + " " + str(g) + " " + str(len(edges))  + "\n" 
        for pair in edges:
            test += str(pair[0]) + " " + str(pair[1]) + "\n"
    return test

iter = 1
while iter <= max:
    iter += 1
    test_content = generate_test()
    with open(f'input{iter}.txt', 'w') as inp:
        inp.write(test_content)
