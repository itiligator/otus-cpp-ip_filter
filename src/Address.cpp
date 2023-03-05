//
// Created by andrei on 02.03.23.
//

#include "../include/Address.h"
#include "string"
#include "regex"
#include "iostream"


namespace ipv4 {

    Address::Address(const std::string &str) {
        if (isValidIPAddressString(str)) {
            uint16_t first = 0;
            uint16_t second = 0;
            uint16_t third = 0;
            uint16_t fourth = 0;
            std::stringstream s(str);
            char ch;
            s >> first >> ch >> second >> ch >> third >> ch >> fourth;
            auto tmp = std::make_tuple(first, second, third, fourth);
            this->swap(tmp);
        } else {
            throw std::invalid_argument("IPv4 address string is malformed");
        }

    }

    std::ostream &operator<<(std::ostream &os, const ipv4::Address &addr) {
        os << std::get<0>(addr) << '.' << std::get<1>(addr) << '.' << std::get<2>(addr) << '.' << std::get<3>(addr);
        return os;
    }


} // ipv4
