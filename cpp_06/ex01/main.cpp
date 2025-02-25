#include "Serializer.hpp"

int main(void) {
    Data data;
    data.str = "hello world!";

    std::cout << &data << std::endl;
    std::cout << data.str << std::endl;

    std::cout << "------------------- serialize! -------------------\n";
    uintptr_t ptr = Serializer::serialize(&data);
    std::cout << ptr << std::endl;

    std::cout << "------------------- deserialize! -------------------\n";
    Data *result = Serializer::deserialize(ptr);
    std::cout << result << std::endl;
    std::cout << result->str << std::endl;

    // int a = 123456;
    // std::cout << reinterpret_cast<int *>(a) << std::endl;
    // 123456 (10진수) => 1e240 윈도우 기준. (16진수 - 0x는 16진수의 표현법)
    return 0;
}