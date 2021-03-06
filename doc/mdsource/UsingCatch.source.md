<a id="top"></a>

# Using Approval Tests With Catch


toc



## Getting Started With Catch 1 and 2

The [Catch2](https://github.com/catchorg/Catch2) test framework works well with Approval Tests.

This section describes the various ways of using Approval Tests with Catch 2.

These steps also work with the earlier version, Catch 1, which is on the [Catch 1.x branch](https://github.com/catchorg/Catch2/tree/Catch1.x), and is still provided for those on pre-C++11 compilers. (Please note that the Approval Tests library requires C++11 or newer, however). 

Approval Tests requires that a file called `catch.hpp` is found.

### Starter Project

The quickest way to start experimenting with Approval Tests is to:

1. Download the project [ApprovalTests.cpp.StarterProject](https://github.com/approvals/ApprovalTests.cpp.StarterProject) - via the green "Clone or Download" button at the top-right of the project site.
2. Opening the project in the C++ IDE of your choice.

Each time we release a new version of Approval Tests, we update this project, so it always has the latest features. 

### New Project

Create a file `main.cpp` and add just the following two lines:

snippet: catch_2_main

### Existing Project - with CATCH_CONFIG_MAIN

If you have a Catch (1 or 2) project with your own `main.cpp` that contains the following lines, you will need to replace them with the code in the previous section.

```cpp
#define CATCH_CONFIG_MAIN // remove these lines, and replace with Approval Tests lines
#include "catch.hpp"
```

<!-- todo: document use of sections -->

### Existing Project - with your main()

If you have [supplied your own `main()` for Catch](https://github.com/catchorg/Catch2/blob/master/docs/own-main.md#top), you will need to teach it how to supply test names to Approval Tests.

There is not yet a streamlined way of doing this.

For now, please see the code in [ApprovalTests/Catch2Approvals.h](/ApprovalTests/integrations/catch/Catch2Approvals.h) for the code you will need to add to your `main.cpp`.

If it would be helpful for us to provide an easier way to do this, please let us know, via the contact details in [Contributing to ApprovalTests.cpp](/doc/Contributing.md#top). 


---

[Back to User Guide](/doc/README.md#top)
