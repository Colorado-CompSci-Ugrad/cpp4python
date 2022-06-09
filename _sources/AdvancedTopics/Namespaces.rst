
.. _RST Namespaces:
Namespaces
~~~~~~~~~~

C++ namespaces are similar to Python packages.

C++ uses namespaces to separate the names of one module or library from another.
For example, two developers may create libraries that use the same name to refer
to a function, data type or other name.

For example, the `dog` library might implement the `bark()` function
and the `tree` library might also implement a `bark()` function.
Namespaces help keep your dogs and trees separate.

The following example shows how to use namespaces to associate the functions with their different name spaces.

.. code-block:: cpp
   :linenos:

    #include <iostream>
    #include <string>

    namespace dog {
        std::string bark() { return "dog bark"; }
    }

    namespace tree {
        std::string bark() { return "tree bark"; }
    }

    namespace dog {
        std::string wag() { return "dog bark"; }
    }

    using namespace std;

    int main()
    {
        cout << "Dog is " << dog::bark() << " and " << dog::wag() << endl;
        cout << "Tree is " << tree::bark() << endl;
        return 0;
    }

This example shows multiple aspects of namespaces:

#. Lines 4 & 8 -- you can start a namespace using the `namespace` keyword to open a block of code associated with a specific namespace (*e.g.* `dog` or `tree`)
#. Line 12 - you can add things to an existing namespace by opening the namespace again ( *e.g.* `namespace dog`)
#. Lines 20 & 21 -- you can refer to code within a namespace by prefixing the namespace method and `::` -- *e.g.* `dog::bark()` and `tree::bark()`
#. Lines 5, 9 & 13 - you've already been using namespaces! The standard library (strings, `cin` / `cout` ) use the `std::` namespace. This example explicitly uses the `std::string` type from the standard library.
#. Line 16 - you can use the `using namespace` syntax to use the specific namespace for the rest of your program file. Thus, function `main()` doesn't need to specify `std::endl` even though `endl` or defined in the `std` library.

In general, you'll use the `std` namespace in your programs but depending on the additional packages or libraries you use, you may use additional namespaces.