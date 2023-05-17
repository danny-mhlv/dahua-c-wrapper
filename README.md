# Dahua SDK/API Wrapper

⚠️ Attention! This wrapper is still under construction, so use with caution! ⚠️

### HELP WANTED

***Important!***

Before compiling this wrapper-library make sure
that `dhnetsdk.h` and `dhconfigsdk.h` do not overlap!
Known issue is `#define` macros and `typedef`s overlapping each other in mentioned files.
There is no workaround, unfortunately :(

## Build
1. Install Dahua SDK libraries via official Dahua download page
2. Clone the code
```shell
git clone https://github.com/danny-mhlv/dahua-c-wrapper.git dahua-wrapper
```
3. Build the wrapper
```shell
cd dahua-wrapper
mkdir build && cd build
cmake .. && cmake --install .
```

## Wrapper

The goal this wrapper-library tries to achieve - is to remove
dumb and unnecessary complexity and poor documentation of original Dahua SDK/API.

Some functions of the wrapper purely serve as syntactic sugar, and some have underlying
implementation. Both are trying to make the life of the programmer easier. 

Examples:

```C
```

For now, it is `C` **only!**

## TODO

There are plans to make this wrapper (sugary part of it at least)
compatible with C++ code too.
