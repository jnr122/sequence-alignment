# Needleman–Wunsch algorithm
https://en.wikipedia.org/wiki/Needleman%E2%80%93Wunsch_algorithm

Skeleton of the algorithm

# Style

I prefer egyptian braces because it is what I originally learned, so now it is much more comfortable for me to read.  For case I prefer consistency, and because c++ uses builtin methods such as push_back(), I default to snake in c++. I prefer RME docs because I find them more helpful then top of file, and I prefer variables without prefixes because personally I don't find that prefixes make the code any more tracable


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


