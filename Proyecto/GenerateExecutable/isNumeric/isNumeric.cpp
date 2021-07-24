#include "isNumeric.h"

bool CheckInt::isNumeric(){
    char* chain = new char;
    std::strcpy(chain, line.c_str());
    bool check = true;
    int size = line.size();

    if(size == 0){
        check = false;
    }else if( size == 1 && !std::isdigit(*(chain+0))) {
        check =  false;
    }else{
        int i = 0;
        if (*(chain+0) == '+' ||*(chain+0) == '-' ){
            i = 1;
        }else{
            i = 0;
            while (i < size){
                if (!std::isdigit(*(chain + i))){
                    check = false;
                    break;
                }
                i ++;
            }
            
        }
    }
    return check;
}

int CheckInt::toInteger(){
    if(!isNumeric()){
        return 0;
    }else{
        return std::stoi(line.c_str());
    }
}

std::string CheckInt::getLine_(){
    return line;
}

void CheckInt::setLine_(std::string line_){
    line = line_;
}