import os
import subprocess

ok_path = "./ok.cpp"
test_path = "./test.cpp"

ok_exec = 'ok_solution'
test_exec = 'test_solution'
 
def test(index : int, input_path : str, ok_path : str, test_path : str):
    with open(input_path, 'r') as inp:
        input_text = inp.read()

        # Run the correct solution with the input and save the output
        with open('ok_output' + str(index) + '.txt', 'w') as ok_out:
            subprocess.run([ok_path], input=input_text, text=True, stdout=ok_out)

            # compile test_path, run and save ouput,
            with open('test_output' + str(index) + '.txt', 'w') as test_out:
                subprocess.run([test_path], input=input_text, text=True, stdout=test_out)

        with open('ok_output' + str(index) + '.txt', 'r') as ok_out:
            with open('test_output' + str(index) + '.txt', 'r') as test_out:
                result_ok = ok_out.read()
                result_test = test_out.read()
                if result_ok == result_test:
                    print(f"Test {index} OK ")
                    return True
                else:
                    print(f"Test {index} do not match")
                    print("Expected")
                    print(result_ok)
                    print("Got :")
                    print(result_test)
                    return False
        return False


dir = './'
files = os.listdir(dir)

inputs = []
for file in files:
    if file.endswith('.txt') and file.startswith("input"):
        inputs.append(file)



# Compile the correct solution
subprocess.run(['g++', ok_path, '-o', ok_exec])
subprocess.run(['g++', test_path, '-o', test_exec])

for i, file in enumerate(inputs):
    if not test(i, file, "./"+ok_exec, "./"+test_exec):
        break