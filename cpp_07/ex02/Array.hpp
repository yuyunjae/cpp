#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
   private:
    T *_arrptr;
    size_t _arrSize;

   public:
    Array();
    Array(unsigned int n);
    virtual ~Array();
    Array(const Array &other);
    Array &operator=(const Array &other);
    T &operator[](size_t idx);

    size_t size() const;

    class OutOfBound : public std::exception {
       public:
        const char *what() const throw();
    };
};

#include "Array.tpp"

#endif
