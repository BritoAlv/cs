import os
import subprocess
import argparse

cpp_paths = ["./ok.cpp", "./test.cpp", "./checker.cpp"]
exec_paths = ["./ok_solution.out", "./test_solution.out", "./checker.out"]

# Compile files.
for cpp_path, exec_path in zip(cpp_paths, exec_paths):
    subprocess.run(['g++', cpp_path, '-o', exec_path])

text_in = ".in"
text_ans = ".ans"

workdir: str = './'
files: list[str] = os.listdir(workdir)

inputs : list[str] = []
for file in files:
    if file.endswith(text_in):
        inputs.append(file)

inputs.sort()
 
def test(input_path: str) -> bool:
    with open(input_path, 'r') as inp:
        input_text = inp.read()
        file_name = "_" + input_path.split(".")[0]
        # Run the correct solution with the input and save the output
        with open('ok_output' + file_name + text_ans, 'w') as ok_out:
            subprocess.run([exec_paths[0]], input=input_text, text=True, stdout=ok_out)

            # compile test_path, run and save output,
            with open('test_output' + file_name + text_ans, 'w') as test_out:
                subprocess.run([exec_paths[1]], input=input_text, text=True, stdout=test_out)

        with open('ok_output' + file_name + text_ans, 'r') as ok_out:
            with open('test_output' + file_name + text_ans, 'r') as test_out:
                result_ok = ok_out.read()
                result_test = test_out.read()
                if result_ok == result_test:
                    print(f"Test OK ")
                    return True
                else:
                    print(f"Test do not match")
                    print("Expected")
                    print(result_ok)
                    print("Got :")
                    print(result_test)
                    return False

def check(input_path : str):
    # Run the test_solution_output as input to the checker and print result of the checker.
    with open(input_path, 'r') as inp:
        input_text = inp.read()
    file_name = "_" + input_path.split(".")[0]
    with open('test_output' + file_name + text_ans, 'w') as test_out:
        subprocess.run([exec_paths[1]], input=input_text, text=True, stdout=test_out)
    with open('test_output' + file_name + text_ans, 'r') as test_out:
        output_text = test_out.read()
        with open("checker_output" + file_name + text_ans, "w") as checker_out:
            subprocess.run([exec_paths[2]], input=output_text, text=True, stdout = checker_out)
        with open("checker_output" + file_name + text_ans, "r") as checker_out:
            print(checker_out.read())

parser = argparse.ArgumentParser(description='Run tests on competitive programming solutions.')
parser.add_argument('-all', action='store_true', help='Run all test cases')
parser.add_argument('-test', type=str, help='Run a specific test case, it should contain the arg passed in the file name')
parser.add_argument('-checker', action='store_true', help='Run the checker for the test cases')

args = parser.parse_args()

if args.all:
    for i, file in enumerate(inputs):
        print(f"Running Test at file {file}")
        test(file)
        print("-------------------------------")
elif args.test:
    print(f"Running Tests with {args.test} in filename")
    test_expression = args.test
    for i, file in enumerate(inputs):
        name = file.split(".")[0]
        if name == test_expression:
            print(f"Running Test at file {file}")
            test(file)
            print("-------------------------------")
            break
elif args.checker:
    for _, file in enumerate(inputs):
        print(f"Running Test at file {file} vs checker")
        print("Checker Says :")
        check(file)
        print("-------------------------------")
else:
    print("No arguments passed. Running all tests by default until one breaks.")
    for i, file in enumerate(inputs):
        print(f"Running Test at file {file}")
        works = test(file)
        print("-------------------------------")
        if not works:
            break