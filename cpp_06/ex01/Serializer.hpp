#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

#define uintptr_t unsigned int

typedef struct sData {
    std::string str;
} Data;

class Serializer {
   private:
    Serializer();
    virtual ~Serializer();
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);

   public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

#endif