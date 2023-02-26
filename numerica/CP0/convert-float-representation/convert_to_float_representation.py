'''
1.0000000000000001e+100 this number does not exist in float 64 representation,
so a way to obtain that as the desired sum is converting everything to int correctly
(not using int()) because number is first interpreted as float, and that mess everything.
int has unlimited precision in python.

sum is not associative due to the impreccisions after 15th digit of the number.

'''
# convert an positive integer to binary
def convert_int_binary(x, precision=11):
    binary = ""
    while len(binary) < precision:
        binary = str(x % 2) + binary
        x = x // 2
    return binary

# convert from binary positive int to int:


def convert_binary_int(x):
    num = 0
    for i in range(0, len(x)):
        num += int(x[i])*2**(len(x) - i-1)
    return num

# convert fraction to binary:


def convert_small_binary(x, precision=52):
    binary = ""
    while len(binary) < 52:
        if 2*x < 1:
            binary = binary + "0"
            x = x * 2
        else:
            binary = binary + "1"
            x = x*2-1
    return binary


def convert_binary_small(x):
    num = 0
    for i in range(1, len(x)+1):
        num += int(x[i-1])*2**(-i)
    return num


def convert_positive_number_binary(x):
    integer_part = 0
    while x-1 >= 0:
        integer_part += 1
        x = x-1
    result = convert_int_binary(integer_part)
    print(x)
    if x > 0:
        result += "." + convert_small_binary(x)
    return result


def convert_number_binary_positive(x):
    position = len(x)
    if "." in x:
        for i in range(0, len(x)):
            if x[i] == ".":
                position = i
                break
    int_part = convert_binary_int(x[0: position])
    frac_part = 0 if position == len(x) else convert_binary_small(x[position+1: len(x)])
    return int_part + frac_part


def get_exponent_positive_number(x):
    exponent = 0
    if x >= 1:
        while x // 2 >= 1:
            x = x//2
            exponent -= 1
    else:
        while x*2 < 1:
            x = x*2
            exponent += 1
        exponent += 1
    return exponent


def get_float_representation_number(x):
    sign = 0
    if x < 0:
        sign = 1
        x = -x
    exponent = get_exponent_positive_number(x)
    mantissa = x * 2**exponent - 1
    return [str(sign), convert_int_binary(-exponent+1023), convert_small_binary(mantissa)]


print(get_float_representation_number(0.1))


def from_float_to_number(x):
    sign = (-1)**int(x[0])
    exponent = 1023 - convert_binary_int(x[1])
    print(exponent) 
    other_part = 1 + convert_binary_small(x[2])
    print(other_part)
    return sign*other_part*2**(-exponent)


print("{0:.17f}".format(
    from_float_to_number(get_float_representation_number(0.1))))

print("{0:.17f}".format(
    from_float_to_number(get_float_representation_number(0.5))))

print("{0:.17f}".format(
    from_float_to_number(get_float_representation_number(1.0000000000000001*10**100))))
