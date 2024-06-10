Smart Pointers
This directory contains the implementation of shared_ptr and weak_ptr, two commonly used smart pointers in C++. These implementations manage the lifetime of dynamically allocated objects to ensure proper resource management and avoid memory leaks.

Directory Structure
controlBlock.hpp: Header file for the ControlBlock class, which manages the reference counts for shared_ptr and weak_ptr.
controlBlock.tpp: Implementation file for the ControlBlock class.
shared_ptr.hpp: Header file for the shared_ptr class template.
shared_ptr.tpp: Implementation file for the shared_ptr class template.
weak_ptr.hpp: Header file for the weak_ptr class template.
weak_ptr.tpp: Implementation file for the weak_ptr class template.
Smart Pointers
Smart pointers are objects that act as pointers but also manage the lifetime of the dynamically allocated objects they point to. They help ensure proper resource management and prevent memory leaks by automatically deallocating the object when it is no longer needed.

shared_ptr
shared_ptr is a smart pointer that retains shared ownership of an object through a pointer. Multiple shared_ptr instances can share ownership of the same object. The object is destroyed when the last remaining shared_ptr owning it is destroyed or reset.

How it works:

Each shared_ptr maintains a reference count.
When a new shared_ptr is created or assigned to an existing shared_ptr, the reference count is incremented.
When a shared_ptr is destroyed or reset, the reference count is decremented.
When the reference count reaches zero, the managed object is deleted.
weak_ptr
weak_ptr is a smart pointer that holds a non-owning ("weak") reference to an object that is managed by shared_ptr. A weak_ptr can be used to break circular references between shared_ptr instances.

How it works:

weak_ptr does not affect the reference count of shared_ptr.
It can be used to check if the managed object still exists without extending its lifetime.
To access the managed object, a weak_ptr must be converted to a shared_ptr.
How to Use
Include the shared_ptr.hpp and weak_ptr.hpp headers in your project.
Use shared_ptr to manage shared ownership of dynamically allocated objects.
Use weak_ptr to hold non-owning references to objects managed by shared_ptr.
These smart pointers help ensure proper resource management and prevent memory leaks in your C++ projects.