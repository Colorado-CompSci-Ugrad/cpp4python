..  Copyright (C)  Jan Pearce
    This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike
    4.0 International License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/4.0/.

Sequences
---------

Python sequences type are `:xref:strings, bytestrings, lists, tuples (pairs, *etc*) and ranges <https://docs.python.org/3/library/stdtypes.html#sequence-types-list-tuple-range>`_ .
Elements in a python sequence have *positions* and you can *iterate* over the sequence.

C++ uses :ref:Arrays as a basic sequence type, but arrays have many limitations - they have a fixed size and accessing data outside the range of the array is not checked and causes errors.

We will examine two C++ sequences provided by linearies: vectors and lists.
C++ sequences are more like Python lists - they let you iterate over the contained items, append items, *etc*
but like C++ arrays, the elements of a C++ vector or list must be *homogeneous* ( all of the same type ).

Vectors
=======

A C++ `vector` is efficient - it is implemented using a C++ array but while a C++ array is a fixed size, you can add or remove items in a C++ `vector`.

Vectors are provided by the Standard Template Library (STL).
Let's compare a C++ array to the C++ vector class using an example.
We allocate an array, initialize it to have 5 elements and iterate
over those elements:

.. activecode:: arrayIteration1
   :language: cpp
   :sourcefile: ArrayIteration.cpp

   #include <iostream>
   using namespace std;

   int main() {
       int nums[] = {1,3,6,2,5};
       //Divide the size of the array (in bytes) by the size of a single element (in bytes)
       // to get the total number of elements in the array.
       int numsSize = sizeof(nums)/sizeof(nums[0]); // Get size of the nums array

       for (int index=0; index<numsSize; index++) {
           cout << nums[index] << endl;
       }

  	return 0;
   }
The above loop assigns the variable ``index`` to be each successive value from 0 to numsSize.
Then, the value at that index in the array is printed to the console.

The following shows the syntax using C++ vectors:

.. activecode:: vectorIteration1
   :language: cpp
   :sourcefile: VectorIteration.cpp

    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
      vector<int> nums{1,3,6,2,5};

      nums.pusb_back(99); // add one item to the end

        for (auto index = 0; index < nums.size(); index++) {
            cout << nums[index] << endl;
        }

    return 0;
    }

In modern C++11, you can simplify this using a C++ iteraor notation:

.. activecode:: vectorIteration2
   :language: cpp
   :sourcefile: VectorIterator.cpp

    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
      vector<int> nums{1,3,6,2,5};

        for (auto item : nums ) {
            cout << item << endl;
        }

    return 0;
    }

The `auto` keyword ensures the type of `item` is the time of items in the container (*e.g.* `int` in this example).

.. _tbl_vectorbasics:

.. table:: **Common C++ Vector Operators**


    ===================== ============================= ====================================================
     **Vector Operation**                       **Use**                                      **Explanation**
    ===================== ============================= ====================================================
                  ``[ ]``               ``myvector[i]``                   access value of element at index i
                   ``at``            ``myvector.at(i)``           checked access value of element at index i
                    ``=``         ``myvector[i]=value``                   assign value to element at index i
            ``push_back``    ``myvect.push_back(item)``            Appends item to the far end of the vector
             ``pop_back``         ``myvect.pop_back()``      Deletes last item (from  far end) of the vector
               ``insert``    ``myvect.insert(i, item)``                           Inserts an item at index i
                ``erase``           ``myvect.erase(i)``                       Erases an element from index i
                 ``size``             ``myvect.size()``             Returns the actual size used by elements
             ``capacity``         ``myvect.capacity()``       Returns the size of allocated storage capacity
              ``reserve``    ``myvect.reserve(amount)``               Request a change in capacity to amount
    ===================== ============================= ====================================================


A very common programming task is to grow a vector using the ``push_back()`` method to append to the vector.
Vectors may allocate extra storage to accommodate for possible growth (*e.g.* from ``push_back()``),
and typically have an actual *capacity* greater than the storage *size* (the number of items in the vector).

You can substitute a vector for an array using the `myvect[i]` notation, but this doesn't check that references are within the array bounds, just as for a C++ array.
Alternatively, you can use the `myvect.at(i)` notation -- this is slightly slower but it throws a C++ `:xref:out of range exception <https://cplusplus.com/reference/stdexcept/out_of_range/>`_;
exceptions are an "advanced" topic (see :ref:`Exception Handling` ).

.. activecode:: vectorIteration1
   :language: cpp
   :sourcefile: VectorIteration.cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main()
    {
        vector<int> nums{1, 3, 6, 2, 5};

        nums.push_back(99); // add one item to the end

        for (auto index = 0; index < nums.size(); index++)
        {
            cout << nums[index] << endl;
        }

        cout << "This reference causes error " << nums.at(10) << endl;

        return 0;
    }
    

Matching
^^^^^^^^
.. dragndrop:: matching_vectors
   :feedback: Feedback shows incorrect matches.
   :match_1: [ ]|||Accesses value of an element.
   :match_2: =||| Assigns value to an element.
   :match_3: push_back|||Appends item to the end of the vector.
   :match_4: pop_back||| Deletes last item of the vector.
   :match_5: insert|||Injects an item into the vector.
   :match_6: erase|||Deletes an element from the choosen index.
   :match_7: size|||Returns the actual capacity used by elements.
   :match_8: capacity|||Returns the ammount of allocated storage space.
   :match_9: reserve||| Request a change in space to amount

    Match the Vector operations with their corresponding explination.

.. tabbed:: intro_vector

  .. tab:: C++

    .. activecode:: introvector_cpp
        :caption: Using a vector in C++
        :language: cpp

        // function that uses a vector to square
        // every number from 0 to 49
        // uses the reserve operation to save space in memory
        #include <iostream>
        #include <vector>
        using namespace std;

        int main(){

            vector<int> intvector;
            intvector.reserve(50);

            for (int i=0; i<50; i++){
                intvector.push_back(i*i);
                cout << intvector.at(i) << endl;
            }
            return 0;
        }

  .. tab:: Python

    .. activecode:: introvector_py
        :caption: Using a Python list

        """Uses a list to square every
        number from 0 to 49 """
        def main():
            intlist=[]
            for i in range(50):
                intlist.append(i*i)
                print(intlist[i])

        main()


In the above example, the use of ``reserve`` was optional. However, it is a good
idea to use it before growing a vector in this way because it will save time.
When the vector size needs to increase the data may need to be copied, which slows things down.

In a typical implementation, the capacity is doubled each time as in this example:

.. activecode:: vector_no_reserve_cpp
    :caption: With use of ``reserve``
    :language: cpp

    // function that uses a vector to square
    // every number from 0 to 49
    // and does not use reserve.
    // shows amount of space used
    #include <iostream>
    #include <vector>
    using namespace std;

    int main(){

        vector<int> intvector;
        // without intvector.reserve(50);

        for (int i=0; i<50; i++){
            intvector.push_back(i*i);
            cout << intvector.at(i) << endl;
            cout << "capacity: " << intvector.capacity() << endl;
        }
        return 0;
    }


Remembering that C++ is designed for speed, not protection,
we will likely not be surprised by the following:

.. tabbed:: vector_errors

  .. tab:: C++

    .. activecode:: vector_errors_cpp
        :caption: Vectors out of bounds
        :language: cpp

        // Note: counting always starts at 0
        // This demonstrates what happens when
        // accessing data outside of your vector

        #include <iostream>
        #include <vector>
        using namespace std;

        int main(){

            vector<int> intvector;
            intvector.reserve(10);

            for (int i=0; i<10; i++){
                intvector.push_back(i);
            }

            for (int i=0; i<=10; i++){   // Note use of <= vs. < earlier
                cout << "intvector[" << i << "]="
                <<intvector[i] << endl;
            }

            return 0;
        }

  .. tab:: Python

    .. activecode:: vector_errors_py
        :caption: Python list out of bounds

        """Demonstrates python's protections
        against iterating outside of a list"""
        def main():
            intlist=[]
            for i in range(10):
                intlist.append(i)

            for i in range(11):
                print("intlist[" + str(i) + "]=" + str(intlist[i]))

        main()

You should use the `myvect.at(i)` notation if possible even if it's slower - it doesn't matter how fast a program is if it's wrong.

.. mchoice:: mc_array_vector
   :answer_a: Vectors can change size.
   :answer_b: Vectors offer all of the features and protections of Python lists
   :answer_c: Vectors don't use contiguous memory, so elements can be inserted.
   :answer_d: more than one of the above
   :answer_e: none of the above
   :correct: a
   :feedback_a: Right! Good job!
   :feedback_b: Not all of the protections of lists are offered by vectors; one can still iterate off of either end.
   :feedback_c: No. Although elements can be inserted in vectors, they do require contiguous memory.
   :feedback_d: No. Only one of the above is correct.
   :feedback_e: One of the above is indeed correct.

   Which of the following is the biggest difference between a C++ array and a C++ vector?

.. mchoice:: mc_vector1
   :answer_a: Nothing. It is completely optional.
   :answer_b: Using it will save time if you know the maximum size needed.
   :answer_c: It is required so memory can be allocated.
   :answer_d: none of the above
   :correct: b
   :feedback_a: It is optional but it does serve a purpose. Try again.
   :feedback_b: Right!
   :feedback_c: It is not required.
   :feedback_d: One of the above is indeed correct.

   What good is the ``reserve`` method in a vector?

Lists
=====

A C++ `list` is similar to a `vector` but it is implemeneted using a *linked list*.
This makes it more efficient to add or remove items from the front, back or middle of the container;
however, you can't access an arbitrary item in the list using the index notation ( `[i]` or `at(i)`)
to remind you that accessing an arbitrary list element is slow.

Instead, you must use the pointers notation (see :ref:`Pointers` ) or the item access pattern as shown below:

.. tabbed:: list_example

  .. tab:: C++

    .. activecode:: list_example_cpp
        :caption: List sequence example
        :language: cpp


        #include <iostream>
        #include <list>
        using namespace std;

        int main() {
            list<int> nums{1,3,6,2,5};
            nums.push_front(20);
            nums.push_back(99);

            for (auto ptr = nums.begin(); ptr != nums.end(); ptr++) {
                cout<< *ptr <<endl;
            }

            for (auto item : nums) {
                cout << item << endl;
            }

        return 0;
        }

  .. tab:: Python

    .. activecode:: list_example_py
        :caption: Python list examples

        """Comparable Python list"""
        def main():
            intlist=[]
            for i in range(10):
                intlist.append(i)

            for i in range(10):
                print( intlist[i] )

            for item in intlist:
                print( item )

        main()

So, although C++ lists share the same name as Python lists, the C++ vector may be a more direct substitution when converting a Python program to C++.