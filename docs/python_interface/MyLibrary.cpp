#include <iostream>

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif

//extern "C" __declspec(dllexport) void PrintMessage() {
//extern "C" void __attribute__((visibility("default"))) PrintMessage(){
extern "C" EXPORT void PrintMessage(const char* message){
    std::cout << "Message : " << message << std::endl;
}

