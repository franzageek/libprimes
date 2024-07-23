![](https://img.shields.io/github/license/franzageek/libprimes)
![](https://img.shields.io/github/v/release/franzageek/libprimes)
![](https://img.shields.io/github/last-commit/franzageek/libprimes)
![](https://img.shields.io/github/issues/franzageek/libprimes)

# libprimes
A C library containing various functions related to prime numbers. 

## Introduction
_**libprimes**_ is a C library whose aim is to provide a bunch of useful functions to allow C/C++ programmers to deal with prime numbers with more ease.

Its first version, as of July 23rd 2024, includes:
-  a primimality-check function;
-  a prime factorization algorithm.

I'm planning to keep on adding more & more features to it, in the hope for it to be adopted from more & more people.

## Building
Just download the source code, extract it somewhere comfortable, then open a command prompt in that folder and run the following command:

- If you're on Linux, run:
```bash
$ ./configure.sh
```
- Or, if you run Windows:
```batch
> configure.bat
```
> **NOTE:** I haven't tested configure.bat yet, but it _should_ work, cause it is pretty much the same code as configure.sh.

You can customize various properties of the build, such as the build folder path, the build configuration & whether or not to run tests before installing.

To edit these properties, simply open the `configure.{sh|bat}` file in a text editor and search for the property you want to edit. These properties are defined at the top of the file. 

You'll just have to edit the `BUILD_DIR`, the `BUILD_CONFIG` and the `RUN_TESTS` variable according to your preferences. These variables will be passed to CMake when building the project.

## Additional info
To know more about libprimes itself, please check the [wiki](https://github.com/franzageek/libprimes/wiki).

To discover how to take part in the project by contributing, check [CONTRIBUTING](https://github.com/franzageek/libprimes/CONTRIBUTING.md).



