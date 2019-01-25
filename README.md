# Errors
Error Log

# Logging Errors
Every time you fix a bug, log it in the README file here:

| Type of error (compiler, runtime, logic) | File | Description | Fix |
| ---------------------------------------- | ---- | ----------- | --- |
|
| compiler: clang | CMakeLists.txt | "linker command failed with exit code 1" | added square.cpp to line 6 |
| compiler: error | square.cpp | "member reference type 'Square *' is a pointer; did you mean to use '->'?" | switched to -> |
| runtime: exit code 11 | square.cpp | accessing vector index out of bounds | switched to push_back() method |


