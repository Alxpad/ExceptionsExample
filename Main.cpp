#include <iostream>
#include <string>

struct Exception {
    Exception(const char* message) {
        msg = message;
    }
    ~Exception() = default;

    const char* msg;
};

int main() {
    int num{0};
    std::cout << "Init for :" << std::endl;
    for (int num = 0; num <= 5; ++num) {
        
        std::cout << "Numero " << num << std::endl;
        try {
            if (num == 2) {
                throw "char* exception";
            }

            if (num == 3) {
                throw 23;
            }

            if (num == 4) {
                Exception exc("Exception object thrown");
                throw exc;
            }
            else
            {
                throw std::runtime_error("Unknown runtime error");
            }
        } catch (const int& n) {
            if (n == 4) {
                // No hacer nada específico para la excepción 4
            } else {
                std::cout << "Int exception (" << n << ")" << std::endl;
            }
        } catch (const char* msg) {
            std::cout << msg << std::endl;
        } catch (const Exception& excObj) {
            std::cout << excObj.msg << std::endl;
        } catch (...) {
            std::cout << "Unknown exception" << std::endl;
        }
    }
    std::cout << "For ended" << std::endl;
    return 0;
}
