#include <iostream>

extern "C" __declspec(dllexport) void PrintMessage() {
    std::cout << "Hello from C++!" << std::endl;
}

