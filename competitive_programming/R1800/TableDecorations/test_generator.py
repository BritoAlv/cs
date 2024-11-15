max = 100

def generate_random_string():
    import random
    import string
    n = 1000
    return ''.join(random.choices(string.ascii_lowercase, k=n))

def generate_test() -> str:
    import random
    test = str(100) + "\n"
    for _ in range(100):
        a = random.randint(1, 100)
        b = random.randint(1, 100)
        c = random.randint(0, 2*(a+b) - 1)
        test += str(a) + " " + str(b) + " " + str(c) + "\n"
    return test

def generate_graph() -> str:
    import random
    N_Test_Cases = 10000
    test = ""
    test += str(N_Test_Cases) + "\n"
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

iter = 0
while iter <= max:
    iter += 1
    test_content = generate_test()
    with open(f'input{iter}.txt', 'w') as inp:
        inp.write(test_content)
