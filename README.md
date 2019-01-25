# Needleman–Wunsch algorithm
https://en.wikipedia.org/wiki/Needleman%E2%80%93Wunsch_algorithm

# Errors
Error Log

| Type of error (compiler, runtime, logic) | File | Description | Fix |
| ---------------------------------------- | ---- | ----------- | --- |
|
| compiler: clang | CMakeLists.txt | "linker command failed with exit code 1" | added square.cpp to line 6 |
| compiler: error | square.cpp | "member reference type 'Square *' is a pointer; did you mean to use '->'?" | switched to -> |
| runtime: exit code 11 | square.cpp | accessing vector index out of bounds | Because exit code 11 is so ambiguous, I had to use the debugger to figure out what was going on. I fixed by switching to the push_back() method |


| Type of error (compiler, runtime, logic) | File | Description | Fix |
| ---------------------------------------- | ---- | ----------- | --- |
| Example: compiler: CMake | CMakeLists.txt | "project PROJECT called with incorrect number of arguments" | Added the project name to line 2 |
| compiler: CMake | CMakeLists.txt | "No SOURCES given to target: Errors" | Added the Main.cpp to line 6 |
| compiler: error | spie.h | "unknown type name 'ostream/istream'" | Added "using namespace std" to header |
| compiler: error | spie.h | "unknown type name 'vector'" | Added template <int> |
| compiler: error | main.cpp | "empty parentheses interpreted as a function declaration" | switched from nonexistent game() to game |
| compiler: error | main.cpp | "reference to non-static member function must be called" | added () to print_winning_numbers |
| compiler: error | main.cpp | "'case' statement not in switch statement" | put switch function in brackets |
| compiler: error | main.cpp | "unreachable code" | took out extra brackets |
| compiler: error | main.cpp | "expected }" | added closing bracket |
| compiler: error | main.cpp | "expected ';' after return statement" | added ; |
| compiler: clang | CMakeLists.txt | "linker command failed with exit code 1" | added spie.cpp to line 6 |
| compiler: error | spie.cpp | "expected unqualified-id" | added SPIE_Game:: to constructor |


