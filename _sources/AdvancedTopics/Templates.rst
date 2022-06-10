
.. _RST Templates:
Templates
~~~~~~~~~

A *template* is a mechanism to define a pattern from which functions (or classes) can be generated.

For example, let's assume you want to define a `GetMax` function that returns the maximum of two arugments
but we want `GetMax` to work on both `int` and `std::string` data types.

In Python, we just need to define a single function and *dynamic typing* will select the operations appropriate to the type (*e.g.* comparisons).
However, dynamic typing is prone to errors that you'll only find when your program is executing. But, the ability to write a single function
to handle multiple types is appealing.

Using :ref:`Function Overloading` we can define two functions that have different types for their arguments:

.. code-block:: cpp
   :linenos:

    #include <iostream>
    using namespace std;

    int GetMax(int a, int b) { return (a > b) ? a : b; }
    string GetMax(string a, string b) { return (a > b) ? a : b; }

The two functions only differ in the type of data they operate on (`int` vs. `string`).
When you use the `GetMax` function, the C++ compiler will select one function or the other based on the supplied arguments.

While this lets us use the same function name, it's silly to repeat the body of the `GetMax` function each time.
This is where *templates* come in -- we can specify sketch the code but specify that a specific type
needs to be specified; once that's done, the code sketched out in the template is repeated for each type.

For example, we can define a single template that will then handle both the `int` and `string` variants:


 .. activecode:: template_cpp
    :caption: Basic Arithmetic Operators C++
    :language: cpp

    #include <iostream>
    using namespace std;

    template <class T>
    T GetMax (T a, T b) { return (a>b)? a : b; }

    int main () {
        int i=5, j=6, k;
        string one("one");
        string two("two");

        k=GetMax<int>(i,j);
        string n=GetMax<string>(one, two);
        
        cout << k << endl;
        cout << n << endl;
        return 0;
    }

The :ref:`Container Data Types` (*e.g.* `vector`, `list` and `unordered_map`) are implemented using templates -- you can define a vector of `int` or `string` and the code is automatically duplicated to handle each data type.

Even though this is a section on "advanced topics", templates have a number of featues and complexities that go beyond this book.
More details can be found at this `templates tutoial <https://cplusplus.com/doc/oldtutorial/templates/>`_ .
