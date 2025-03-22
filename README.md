# EECS348 Lab 7

This is a template for Lab 7 with continuous integration testing set up in a
[GitHub Actions workflow](https://docs.github.com/en/actions/about-github-actions/understanding-github-actions).
When you push code to this repository, it will automatically be compiled and
ran through a set of test cases, and the results will be reported back to you.
This should give you an opportunity to verify that your code is compiling and
behaving as expected before you submit it.

## Viewing the workflow report

If you click on the red X that currently appears to the right of the latest
commit message in this repo and click on details, you will be taken to a log
of the workflow that ran for that commit. This will report any errors during
compilation of your project, and if compilation succeeded, all passing or
failing test cases. From here you will be able to get a better idea of what is
working in your code and what you still need to fix before you submit.

The test cases for this lab are contained in the folder named `tests/tests.cpp`.
These are written with [GoogleTest](https://github.com/google/googletest). The
test cases included in this repository at the start won't be enough to
guarantee your code works for our input file, so it may be a good idea to write
some of your own following the documentation at that link.

You shouldn't have to modify any of the files named `CMakeLists.txt`. These are
used for building your project for the Github Action and running the tests.

## To begin

Create a [fork](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/working-with-forks/fork-a-repo)
of this repository through GitHub then clone it locally and start working.

### Starting files

You begin with all source and header files you will need for the lab. For help
working with multiple C source files and compiling them, you can refer back to
my write-up for the [Makefiles](https://people.eecs.ku.edu/~h054w684/lab3.html)
lab.

You should keep code that handles user input for each part of the lab in each 
part's respective `main` file, and code that implements functionality in
`football.c` or `temperature.c`.

#### Temperature

Write any functions you need in `temperature.c` and call them from your main
function in `temperature_main.c`. The function signatures for converting
temperatures are already in `temperature.h` but you will need to add a
signature for your characterize function.

#### Football scores

Write any functions you need in `football.c` and call them from
`football_main.c`. The function signatures you need to implement are already
given in `football.h`.

#### Makefile

You will also have to write your own Makefile to build your code. The file is
included already but starts out mostly blank.
