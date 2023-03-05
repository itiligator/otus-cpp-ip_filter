//
// Created by andrei on 02.03.23.
//

#ifndef IP_FILTER_ADDRESS_H
#define IP_FILTER_ADDRESS_H

#include "tuple"
#include "string"
#include "memory"
#include "regex"
#include "ostream"


namespace ipv4 {
class Address : public std::tuple<uint16_t,uint16_t,uint16_t,uint16_t >{
    public:
        typedef std::unique_ptr<Address> Ptr;

        explicit Address(const std::string &);

        inline static bool isValidIPAddressString(const std::string &IP) {
            std::regex ipv4regex(
                    "(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
            return std::regex_match(IP, ipv4regex);
        }

        friend std::ostream &operator<<(std::ostream &os, const Address &addr);

    };

    std::ostream &operator<<(std::ostream &os, const ipv4::Address &addr);


} // ipv4



#endif //IP_FILTER_ADDRESS_H
