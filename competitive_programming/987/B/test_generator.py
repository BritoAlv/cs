test_files_to_write = 100

def generate_random_string():
    import random
    import string
    n = 1000
    return ''.join(random.choices(string.ascii_lowercase, k=n))

def generate_test() -> str:
    import random
    n = random.randint(1, 10)
    test = ""
    test += str(n) + "\n"
    l = [i for i in range(1, n+1)]
    random.shuffle(l)
    for i in range(n):
        test += str(l[i]) + " "
    return test

def generate_graph() -> str:
    import random
    n_test_cases = 10000
    test = ""
    test += str(n_test_cases) + "\n"
    for _ in range(n_test_cases):
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

for i in range(1, test_files_to_write+1):
    test_content = generate_test()
    with open(f'{i}.in', 'w') as inp:
        inp.write(test_content)