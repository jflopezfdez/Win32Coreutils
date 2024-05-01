# Win32 Coreutils Re-implementation in C++

This project is a re-implementation of the GNU `coreutils` utilities on Windows
written in C++20.[^eventually-footnote]

I originally got the idea for this project years ago after reading the
`coreutils` source code for the first time. I had originally intended to try to
learn more about how real-world projects in C are written, but it became
immediately clear that the priority for the `coreutils` project was not ease of
understanding for beginners but rather correctness, performance, and broad
platform compatibility. While my plan is no longer explicitly letting beginners
learn by reading implementation code directly, I've wanted to re-implement
these utilities for years.

My thinking is that while preprocessor macros and somewhat esoteric code may
have been necessary to achieve the project's goals even five or ten years ago,
the C++ standardization efforts have brought us to the point where intelligible
code and correct, performant, and cross-platform code are no longer mutually
exclusive.

## Usage

Running the utilities works exactly the same way as it does on *nix platforms,
at least for the simplest use cases.

For instance, this is a sample command invocation of the `cat` utility on my
local Pylint configuration file.

```
C:\Users\jflop\source\repos\Win32Coreutils\x64\Debug>cat.exe %USERPROFILE%\.pylintrc
# This Pylint rcfile contains a best-effort configuration to uphold the
# best-practices and style described in the Google Python style guide:
#   https://google.github.io/styleguide/pyguide.html
#
# Its canonical open-source location is:
#   https://google.github.io/styleguide/pylintrc

[MAIN]

# Files or directories to be skipped. They should be base names, not paths.
ignore=third_party

# Files or directories matching the regex patterns are skipped. The regex
# matches against base names, not paths.
ignore-patterns=
...
```

Note that the output was truncated for brevity.

[^eventually-footnote]: Or, at least it will be, once I'm finished.
