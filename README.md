#stringtools

Helpers for common string manipulation tasks in C++.

##Usage

```C++
#include "stringtools/all.hpp"
using namespace str;
std::string text = format("hello %s")("world");
std::vector<std::string> v = split(", ")("hello, world");
std::string hw = join(" ")(v);

print("abc:",1,2,3);
// prints:
// abc: 1 2 3
```
