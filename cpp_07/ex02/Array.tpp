
template <typename T>
Array<T>::Array() : _arrptr(NULL), _arrSize(0) {
    std::cout << "Array default constructor called\n";
}

template <typename T>
Array<T>::Array(unsigned int n) : _arrptr(NULL), _arrSize(n) {
    std::cout << "Array constructor called\n";
    if (this->_arrSize > 0) this->_arrptr = new T[n];
}

template <typename T>
Array<T>::~Array() {
    std::cout << "Array destructor called\n";
    delete[] this->_arrptr;
}

template <typename T>
Array<T>::Array(const Array<T> &other) {
    std::cout << "Array copy constructor called\n";
    this->_arrSize = other._arrSize;
    this->_arrptr = NULL;
    if (this->_arrSize > 0) this->_arrptr = new T[other._arrSize];
    for (size_t i = 0; i < this->_arrSize; i++)
        this->_arrptr[i] = other._arrptr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
    std::cout << "Array copy assignment operator called\n";
    if (*this != other) {
        if (this->_arrptr) {
            delete[] this->_arrptr;
            this->_arrptr = NULL;
        }
        this->_arrSize = other._arrSize;
        if (this->_arrSize > 0) this->_arrptr = new T[other._arrSize];
        for (size_t i = 0; i < this->_arrSize; i++)
            this->_arrptr[i] = other._arrptr[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](size_t idx) {
    if (idx >= this->_arrSize)
        throw Array<T>::OutOfBound();  // 어처피 음수는 size_t에 의해 양수로
                                       // 전환됨.
    return this->_arrptr[idx];
}

template <typename T>
size_t Array<T>::size() const {
    return this->_arrSize;
}

template <typename T>
const char *Array<T>::OutOfBound::what() const throw() {
    return "Out of Bound error!";
}

// [] 이거 제대로 작동하는지 체크해봐야할듯... 뭔가 이상하다야.
