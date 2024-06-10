#ifndef Unique_ptr_HPP
#define Unique_ptr_HPP

#include <utility>

template <typename T>
class Unique_ptr {
public:
    explicit Unique_ptr(T* ptr = nullptr) noexcept;
    ~Unique_ptr();

    Unique_ptr(const Unique_ptr&) = delete;
    Unique_ptr& operator=(const Unique_ptr&) = delete;

    Unique_ptr(Unique_ptr&& other) noexcept;
    Unique_ptr& operator=(Unique_ptr&& other) noexcept;

    void swap(Unique_ptr& other) noexcept;

    T* get() const noexcept;
    T* release() noexcept;
    void reset(T* ptr = nullptr) noexcept;

    T& operator*() const noexcept;
    T* operator->() const noexcept;
    operator bool() {
        return m_ptr;
    }

private:
    T* m_ptr;
};


#include "unique_ptr.tpp"

#endif // Unique_ptr_HPP
