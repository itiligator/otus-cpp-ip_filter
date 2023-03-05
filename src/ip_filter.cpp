#include <iostream>
#include "../include/Address.h"


int main() {
    try {
        // Read from stdin
        std::vector<ipv4::Address> ip_pool;
        for (std::string line; std::getline(std::cin, line);) {
            try {
                auto addr = ipv4::Address(line.substr(0, line.find('\t')));
                ip_pool.push_back(addr);
            }
            catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
        }

        // Sort
        std::sort(ip_pool.begin(), ip_pool.end(), std::greater<>());

        // Print all
        std::copy(ip_pool.begin(), ip_pool.end(), std::ostream_iterator<ipv4::Address>(std::cout, "\n"));

        // Print 1.*.*.*
        std::copy_if(ip_pool.begin(), ip_pool.end(), std::ostream_iterator<ipv4::Address>(std::cout, "\n"),
                     [](const auto &ip) { return std::get<0>(ip) == 1; });

        // Print 46.70.*.*
        std::copy_if(ip_pool.begin(), ip_pool.end(), std::ostream_iterator<ipv4::Address>(std::cout, "\n"),
                     [](const auto &ip) { return std::get<0>(ip) == 46 && std::get<1>(ip) == 70; });

        // Print 46.*.*.* || *.46.*.* || *.*.46.* || *.*.*.46
        std::copy_if(ip_pool.begin(), ip_pool.end(), std::ostream_iterator<ipv4::Address>(std::cout, "\n"),
                     [](const auto &ip) {
                         return std::get<0>(ip) == 46 || std::get<1>(ip) == 46 || std::get<2>(ip) == 46 ||
                                std::get<3>(ip) == 46;
                     });

    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
