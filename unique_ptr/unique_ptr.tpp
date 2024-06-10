#ifndef Unique_ptr_TPP
#define Unique_ptr_TPP

template <typename T>
Unique_ptr<T>::Unique_ptr(T* ptr) noexcept : m_ptr(ptr) {}

template <typename T>
Unique_ptr<T>::~Unique_ptr() {
    delete m_ptr;
}

template <typename T>
Unique_ptr<T>::Unique_ptr(Unique_ptr&& other) noexcept : m_ptr(other.m_ptr) {
    other.m_ptr = nullptr;
}

template <typename T>
Unique_ptr<T>& Unique_ptr<T>::operator=(Unique_ptr&& other) noexcept {
    if (this != &other) {
        reset();
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }
    return *this;
}

template <typename T>
void Unique_ptr<T>::swap(Unique_ptr& other) noexcept {
    std::swap(m_ptr, other.m_ptr);
}

template <typename T>
T* Unique_ptr<T>::get() const noexcept {
    return m_ptr;
}

template <typename T>
T* Unique_ptr<T>::release() noexcept {
    T* temp = m_ptr;
    m_ptr = nullptr;
    return temp;
}

template <typename T>
void Unique_ptr<T>::reset(T* ptr) noexcept {
    T* old_ptr = m_ptr;
    m_ptr = ptr;
    delete old_ptr;
}

template <typename T>
T& Unique_ptr<T>::operator*() const noexcept {
    return *m_ptr;
}

template <typename T>
T* Unique_ptr<T>::operator->() const noexcept {
    return m_ptr;
}


#endif //Unique_ptr_TPP