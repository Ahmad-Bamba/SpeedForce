#pragma once

#include <string>
#include <iostream>

namespace SpeedForce {
    class Greeter {
    private:
        std::string msg;
    public:
        Greeter() {
            msg = "Hello World";
        }
        Greeter(std::string s) {
            msg = s;
        }

        void greet() {
            std::cout << msg << "!\n";
        }
    };
}
