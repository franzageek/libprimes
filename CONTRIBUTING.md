# Contributing to libprimes

## Table of contents

- [General information](#general-information)
- [Conventions](#conventions)
- [Development environment setup](#development-environment-setup)

---



## General information

libprimes is still a small project, so I really appreciate the fact that you're willing to contribute! You are more than welcome to lend us a hand in the development of libprimes!

libprimes' code is published under the MIT License, so by contributing to the project, you agree to the license and copyright terms therein and release your contribution under these terms, unless you have my permission of publishing it under a different license.

We accept contributions as pull request on the GitHub repo.
Make sure to provide a clear description of the pull request, of the feature you're adding, as well as the impact and priority from your perspective. Describe the way it should be built, and how it should integrate with the rest of the project.

Also make sure to clearly describe each commit, while still trying to limit the size of the first line.

Before submitting the code, make sure it has been thoroughly tested. Check that it passes the currently available tests (if applicable) and submit any test executable you have developed/adopted for that matter.

## Conventions

The code you submit as a contribution must follow the conventions described below:

1. **C Standard:** the code must comply with the C99 standard.
2. **Indentation:** use exactly 4 spaces for indentation.
3. **Braces:** place opening braces on the line after the statement. Do not place statements after closing braces.
4. **Single line statement body:** make sure to drop braces if the statement body is 1 line long.
5. **EOF line:** always leave an empty line at the end of every file.
6. **Naming:** use `snake_case` for variable & function names.

```c
if (!condition)
{ // <-- opening braces go on on a new line
    wtf_is_this += 2;
    printf("just like this");
} // <-- don't put statements here, use the next line
else // <-- yeah right here
    printf("drop braces for 1-line statement bodies");
// leave empty line at the bottom

```

> [!IMPORTANT]
>
> Always try to keep your code consistent across multiple files. Make sure to adopt all of the above conventions.

## Development environment setup

You can start off by forking the franzageek/libprimes repository and create your own copy.

Then you can create a new branch with the name of the feature you're going to implement.

Make sure to keep your copy of repository updated with the main repository - there could be mismatches if you miss updates on the main repo.

The preferred build method is CMake, although you can choose a different one, I'll take care of linking it to the top-level build system.

Then you're gonna open a pull request in which you have to detailedly describe how your code is supposed to be integrated into the libprimes library, how it is built, features, improvements, basically everything that was mentioned in [General Information](#general-information).

Thanks again for wanting to help in the project!
