#include "Serializer.hpp"

Serializer::Serializer() {
    std::cout << "Serializer default constructor called\n";
}

Serializer::~Serializer() {
    std::cout << "Serializer destructor called\n";
}

Serializer::Serializer(const Serializer &other) {
    std::cout << "Serializer copy constructor called\n";
    (void)other;
}

Serializer &Serializer::operator=(const Serializer &other) {
    std::cout << "Serializer copy assignment operator called\n";
    (void)other;
    return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data *>(raw));
}