#include <iostream> // for input and output
#include <string> //  for strings



int main() {
    std::string name; // user name
    std::cout << "Enter your name: "; // prompt
    std::cin >> name; // read name
    std::cout << "Hello world from " << name << "!" << std::endl; // greeting
    return 0; // success
}
