#pragma once
//#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cstring>
// #ifdef TESTDLL_EXPORTS
//     #define TESTDLL_EXPORTS  __decls
// #endif
class CheckInt {
    private:
        std::string line;
    public:
        CheckInt() = default;
        std::string getLine_();
        void setLine_(std::string line_);
        bool isNumeric();
        int toInteger();
};
