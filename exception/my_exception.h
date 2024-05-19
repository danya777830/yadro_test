#pragma once

#include <exception>

class EndFile : public std::exception {
    
};

class WrongFormatException : public std::exception {
    
};

class ClientUnknown : public std::exception {
    
};