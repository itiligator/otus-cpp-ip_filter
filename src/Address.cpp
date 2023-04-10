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
            s >> first >> ch >> second >> ch >> third >> ch >> fourth;
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
        ss << first << "." << second << "." << third << "." << fourth;
        return ss.str();
    }


} // ipv4
