# Needleman–Wunsch algorithm
https://en.wikipedia.org/wiki/Needleman%E2%80%93Wunsch_algorithm

# Style
- Egyptian braces
- Snake case 
- RME documentation
- Variables without prefixes

# Errors
Error Log

| Type of error (compiler, runtime, logic) | File | Description | Fix |
| ---------------------------------------- | ---- | ----------- | --- |
| compiler: clang | CMakeLists.txt | "linker command failed with exit code 1" | added square.cpp to line 6 |
| compiler: error | square.cpp | "member reference type 'Square *' is a pointer; did you mean to use '->'?" | switched to -> |
| runtime: exit code 11 | square.cpp | accessing vector index out of bounds | Because exit code 11 is so ambiguous, I had to use the debugger to figure out what was going on. I fixed by switching to the push_back() method |


