import subprocess
import os

# Compile the C program with all the necessary files
compile_command = ["gcc", "main.c", "inputfunctions.c", "printfunctions.c", "studentcsv.c", "-o", "program"]
subprocess.call(compile_command)

# Check if the executable exists (on Windows, use program.exe)
if os.path.exists("program.exe"):  # On Windows, check for "program.exe"
    tmp = subprocess.call("./program")  # Run the executable (on Windows, use .exe extension)
    print("Program exited with code:", tmp)
else:
    print("Error: Executable not found.")