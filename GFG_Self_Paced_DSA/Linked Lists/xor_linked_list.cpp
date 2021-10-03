/*
XOR linked lists are memory efficient implementation of doubly linked lists. An ordinary doubly 
linked list requires space for two address fields to store the addresses of previous and nex  nodes.
A memory-efficient version of DLL an be created using only ones space for the address field with
every node. This memory efficient DLL is called XOR linked list or memory efficient linked list as 
the list uses bitwise XOR operations to save space for one address. In the XOR linked list of storing
actual memory addreresses every node stores the XOR of addresses of previous and next nodes.
*/

/*
Ordinary Representation :-
Node A : prev = NULL , next = add(B)    // previous is NULL and next is address of B
Node B : prev = add(A) , next = add(C)    // previous is NULL and next is address of B
Node C : prev = add(B) , next = add(D)    // previous is NULL and next is address of B
Node D : prev = add(C) , next = NULL    // previous is NULL and next is address of B
*/

/*
XOR List Representation : Let us call the address variable in XOR representation as npx 
                                                                (XOR of next and previous)

Node A :
    npx = 0 ^ add(B)  // bitwise XOR of zero and address of B
Node B :
    npx = add(A) ^ add(C)  // bitwise XOR of address of A and address of C
Node C :
    npx = add(B) ^ add(D)  // bitwise XOR of address of  B and address of D
Node D :
    npx = add(C) ^ 0  // bitwise XOR of address of C and zero
*/

// Traversal of XOR Linked List
/*
We can traverse the XOR list in both forward and reverse directions. While traversing the list we 
need to remember the address of the previously accessed node in order to calculate the next node's
address. For example, when we are at node C, we must have the address of B. XOR of add(B) and npx 
of C gives us the add(D). (Uses the properties of the bitwise XOR operator)
*/