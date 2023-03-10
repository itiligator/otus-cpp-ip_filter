#include <iostream>
#include "Address.h"

template<typename C, typename P>
void print(C container, P predicate) {
    typedef typename C::value_type element_type;
    std::copy_if(container.begin(), container.end(), std::ostream_iterator<element_type>(std::cout, "\n"),
                 predicate);
}


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
        auto no_filtering = [](ipv4::Address _) { return true; };
        print(ip_pool, no_filtering);

        // Print 1.*.*.*
        auto starts_from_1 = [](ipv4::Address ip) { return std::get<0>(ip) == 1; };
        print(ip_pool, starts_from_1);

        // Print 46.70.*.*
        auto starts_from_4670 = [](ipv4::Address ip) { return std::get<0>(ip) == 46 && std::get<1>(ip) == 70; };
        print(ip_pool, starts_from_4670);

        // Print 46.*.*.* || *.46.*.* || *.*.46.* || *.*.*.46
        auto has_any_46 = [](ipv4::Address ip) {
            return std::get<0>(ip) == 46 || std::get<1>(ip) == 46 || std::get<2>(ip) == 46 ||
                   std::get<3>(ip) == 46;
        };
        print(ip_pool, has_any_46);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
