//
// Created by andrei on 02.03.23.
//

#include "../include/Address.h"
#include "string"

#include "iostream"


namespace ipv4 {

    Address::Address(const std::string &str) {
        if (isValidIPAddressString(str)) {
            std::stringstream s(str);
            char ch;
            s >> this->at(0) >> ch >> this->at(1) >> ch >> this->at(2) >> ch >> this->at(3);
        } else {
            throw std::invalid_argument("IPv4 address string is malformed");
        }

    }

    std::ostream &operator<<(std::ostream &os, const ipv4::Address &addr) {
        os << std::string(addr);
        return os;
    }

    Address::operator std::string() const {
        std::stringstream ss;
        ss  << this->at(0) << "." << this->at(1) << "."<< this->at(2) << "."<< this->at(3);
        return ss.str();
    }


} // ipv4
