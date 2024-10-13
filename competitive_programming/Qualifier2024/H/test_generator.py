max = 100

def generate_random_string():
    import random
    import string
    n = 1000
    return ''.join(random.choices(string.ascii_lowercase, k=n))

def generate_test() -> str:
    import random
    n = random.randint(1, 10)
    test = ""
    test += str(1) + "\n"
    test += str(n) + " " + str(n) + " " + str((n*(n-1))//2)  + "\n" 
    for i in range(1, n+1):
        for j in range(i+1, n+1):
            test += str(i) + " " + str(j) + "\n"
    return test

def generate_graph() -> str:
    import random
    N_Test_Cases = 1
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

iter = 1
while iter <= max:
    iter += 1
    test_content = generate_graph()
    with open(f'input{iter}.txt', 'w') as inp:
        inp.write(test_content)
