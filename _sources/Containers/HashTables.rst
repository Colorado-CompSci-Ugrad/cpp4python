..  Copyright (C)  Jan Pearce
   This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.

Dictionary or Maps
^^^^^^^^^^^^^^^^^^

A Python dictionary lets you associate a *value* with a specific *key*.
Dictionaries have a number of alternate names, including *maps* and *key-value stores*.


A Dictionary or Map can be implemented in a number of ways as you'll learn in later classes.

C++ provides the `<unordered_map>` and `<map>` containers.
Both containers let you add, remove and iterate over items in the container.
The `map` stores keys-value pairs in a way that lets you iterate over the items  *e.g.* from smallest to largest.
Keeping the key-value pairs ordered takes additional time, and
the `unordered_map` stores the data more efficiently but doesn't return them in a specific order (more like a Python dictionary). 

::

  #include <unordered_map>

The syntax for hash table access is much like we might expect
except that instead of using the index of the item for look-up, we
use the key. In both Python and C++, hash tables can be initialized with key-value pairs and
key-value pairs can also be added later as we see in the following example.
In C++, the keyword ``first`` is used for the key, and ``second`` is used for the
associated value.

.. tabbed:: map

    .. tab:: C++

        .. activecode:: map_cpp
            :caption: Using a map C++
            :language: cpp

            // Creates a map that maches 
            // the english word to it's spanish 
            // equivalent, and outputs the size of
            // the table to the console
            #include <iostream>
            #include <unordered_map>
            #include <string>
            using namespace std;

            int main() {
                unordered_map<string, string> spnumbers;

                spnumbers = { {"one", "uno"}, {"two", "dos"} };

                spnumbers["three"] = "tres";
                spnumbers["four"] = "cuatro";

                cout << "one is ";
                cout << spnumbers["one"] << endl;

                cout << spnumbers.size() << endl;
            }

    .. tab:: Python

        .. activecode:: dictionary_py
            :caption: Using a Dictionary

            """Python equivalent 
            of the C++ code """
            def main():
                spnumbers = {"one":"uno","two":"dos"}

                spnumbers["four"]="cuatro"
                spnumbers["three"]="tres"

                print("one is", end=" ")
                print(spnumbers["one"])

                print(len(spnumbers))
            main()


Iterators of an ``unordered_map`` are
implemented using pointers to point to elements of the value type as we see in
the following example.

.. tabbed:: map2

    .. tab:: C++

        .. activecode:: map2_cpp
            :caption: Iterating a map C++
            :language: cpp

            // Creates a hash table that maches 
            // the english word to it's spanish 
            // equivalent, and outputs every item 
            // in the table to the console
            #include <iostream>
            #include <unordered_map>
            #include <string>
            using namespace std;

            int main() {
                unordered_map<string, string> spnumbers;

                spnumbers = { {"one","uno"},{"two","dos"},{"three","tres"},{"four","cuatro"},{"five","cinco"} };

                for (auto i=spnumbers.begin(); i!=spnumbers.end(); i++ ){

                    cout << i->first << ":";
                    cout << i->second << endl;
                }
            }

    .. tab:: Python

        .. activecode:: hashtable2_py
            :caption: Iterating a Dictionary

            """Python equivalent 
            of the C++ code """
            def main():
                spnumbers = {"one":"uno","two":"dos","three":"tres","four":"cuatro","five":"cinco" }

                for key in spnumbers:
                    print(key, end=":")
                    print(spnumbers[key])

            main()

You may want to change the C++ `unordered_map` to a `map` and see the difference.


Hash Tables have both methods and operators. :ref:`Table 7 <tab_hashopers>`
describes them, and the session shows them in action.

.. _tab_hashopers:

.. table:: **Table 7: Important Hash Table Operators Provided in C++**

    ===================== ========================= ================================================================
             **Operator**                   **Use**                                                  **Explanation**
    ===================== ========================= ================================================================
                 ``[ ]``               ``mymap[k]``  Returns the value associated with ``k``, otherwise throws error
                ``count``      ``mymap.count(key)``     Returns ``true`` if key is in ``mymap``, ``false`` otherwise
                ``erase``      ``mymap.erase(key)``                                 Removes the entry from ``mymap``
                ``begin``         ``mymap.begin()``                    An iterator to the first element in ``mymap``
                  ``end``           ``mymap.end()``        An iterator pointing to past-the-end element of ``mymap``
    ===================== ========================= ================================================================


Matching
========
.. dragndrop:: matching_HT
   :feedback: Feedback shows incorrect matches.
   :match_1: [ ]|||Returns the value associated with the key, otherwise throws error.
   :match_2: erase|||Deletes the entry from the hash table.
   :match_3: count|||Returns true if key is in the hash table, and false otherwise.
   :match_4: begin|||An iterator to the first element in the hash table.
   :match_5: end|||An iterator pointing to past-the-end element of the hash table.

    Match the map operations with their corresponding explination.
