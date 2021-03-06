    void printLastKLines(char* fileName) {
        const int K = 10;
        ifstream file(fileName);
        string L[K];
        int size = 0;

        /* read file line by line into circular array */
        /* peek() so EOF following a line ending is not considered a separate line */
        while (file.peek() != EOF) {
            getline(file, L[size % K]);
            size++;
        }

        /* compute start of circular array and the size of it */
        int start = size > K ? (size % K): 0;
        int count = min(K, size);

        /* print elements in order */
        for (int i = 0; i < count; i++) {
            cout << L[(start+i) % K] << endl;
        }
    }

    void reverse(char* str) {
        int end = 0;

        while (*(str)) {
            end++;
        }

        for (int i = 0; i < end; i++) {
            char tmp = str[end-i-1];
            str[end-i-1] = str[i];
            str[i] = tmp;
        }
    }

/*

Hash Table vs STL Map
In a hash table a value is stored by calling a hash function on a key. Values are not stored in sorted order. Additionally,
since hash tables use the key to find the index that will store the value, an insert or lookup can be done in amortized
0(1) time (assuming few collisions in the hash table). In a hash table, one must also handle potential collisions. This is
often done by chaining, which means to create a linked list of all the values whose keys map to a particular
index. On the other hand, an STL map inserts the key/value pairs into a binary search tree based on the keys. There is no
need to handle collisions, and, since the tree is balanced,the insert and lookup time is guaranteed to be 0(log N).
If the number of inputs is small, then the STL map is best to use.

Virtual Function
A virtual function depends on a "vtable" or "Virtual Table:' If any function of a class is declared to be virtual, a
vtable is constructed which stores addresses of the virtual functions of this class. The compiler also adds a hidden vptr
variableinallsuchclasseswhichpointstothevtableofthatclass.Ifavirtualfunctionisnot overridden in the derived class, the
vtable of the derived class stores the address of the function in its parent class. The vtable is used to resolve the
address of the function when the virtual function is called. Dynamic binding in C++ is performed through the vtable
mechanism. Thus, when we assign the derived class object to the base class pointer, the vptr variable points to the
vtable of the derived class. This assignment ensures that the most derived virtual function gets called.

Shallow vs Deep Copy
A shallow copy copies all the member values from one object to another. A deep copy does all this and also deep copies any
pointer objects. Note that sha11ow_copy may cause a lot of programming runtime errors, especially with the creation and
deletion of objects. Shallow copy should be used very carefully and only when a programmer really understands what he wants
to do. In most cases, shallow copy is used when there is a need to pass information about a complex structure without
actual duplication of data. One must also be careful with destruction of objects in a shallow copy. In real life, shallow
copy is rarely used. Deep copy should be used in most cases, especially when the size of the copied  structure is small.

Volatile
The keyword volatile informs the compiler that the value of variable it is applied to can change from the outside, without
ny update done by the code. This may be done by the operating system, the hardware, or another thread. Because the value
can change unexpectedly, the compiler will therefore reload the value each time from memory. Volatile variables are also
useful when multi-threaded programs have global variables and any thread can modify these shared variables. We may not
want optimization on these variables.

Virtual Destructor
We want to ensure that the destructor for the most derived class is called, so that the base class' destructor isn't
only called.

*/











