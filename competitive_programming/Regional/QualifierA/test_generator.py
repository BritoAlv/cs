max = 10

def generate_random_string():
    import random
    import string
    n = 1000
    return ''.join(random.choices(string.ascii_lowercase, k=n))

def generate_test() -> str:
    import random
    n = 1000
    test = ""
    test += str(n) + "\n" 
    for _ in range(n):
        test += generate_random_string() + "\n"
    return test



iter = 1
while iter <= max:
    iter += 1
    test_content = generate_test()
    with open(f'input{iter}.txt', 'w') as inp:
        inp.write(test_content)
