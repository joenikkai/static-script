int add() {
    int a = 5;
    int b = 10;
    int sum = a + b;
    write "The sum of "  a  " and "  b  " is "  sum;
    return 0;
}

/*
Types are:
    character
    integer
    real
    imaginary
    boolean
    string
    float
    object
    null
*/

/*
arithmetic operators:
    +
    -
    *
    /
    %
    ++
    --
*/

/*
arithmetic operations can happen between:
    integer and integer
    real and real
    float and float
    integer and real (result is real)
    integer and float (result is float)
    real and float (result is float)
    character and character (result is integer, based on ASCII values)
    other wise if done on strings and objects, they are done on pointer addresses and not the values themselves, and the result is an integer
*/

/*
objects can be created using the 'object' keyword, and they can have properties and methods. They can also be instantiated using the 'new' keyword. For example:
if objects are made with keyword struct, they are value types and are stored on the stack, and if they are made with keyword class, they are reference types and are stored on the heap. They can also have constructors and destructors. They can also have inheritance and polymorphism.
we can use pointers of the vm's virtual memory where values are stored to manipulate objects and other data types. We can also use pointers to create dynamic data structures like linked lists, trees, and graphs. We can also use pointers to create dynamic arrays and other data structures that can grow and shrink in size at runtime. We can also use pointers to create dynamic memory allocation and deallocation, which allows us to manage memory more efficiently and avoid memory leaks.

*/