//
// Created by andrei on 10.03.23.
//

#include <gtest/gtest.h>
#include "Address.h"

// Test constructor with invalid argument
TEST(Address, ConstructorInvalid) {
EXPECT_ANY_THROW(ipv4::Address(""));
EXPECT_ANY_THROW(ipv4::Address("sdgfsdf"));
EXPECT_ANY_THROW(ipv4::Address("1...0"));
EXPECT_ANY_THROW(ipv4::Address("260.0.1.0"));
EXPECT_ANY_THROW(ipv4::Address("1.1.1.01"));
EXPECT_ANY_THROW(ipv4::Address("127.1"));
EXPECT_ANY_THROW(ipv4::Address("192.168.1.256"));
EXPECT_ANY_THROW(ipv4::Address("192.256.1.1"));
EXPECT_ANY_THROW(ipv4::Address("192.1.256.1"));
EXPECT_ANY_THROW(ipv4::Address("256.1.1.1"));
EXPECT_ANY_THROW(ipv4::Address("-1.2.3.4"));
EXPECT_ANY_THROW(ipv4::Address("1.1.1.1."));
EXPECT_ANY_THROW(ipv4::Address("3...3"));
EXPECT_ANY_THROW(ipv4::Address("1.1.1."));
EXPECT_ANY_THROW(ipv4::Address(".1.1.1"));
EXPECT_ANY_THROW(ipv4::Address(".1.1"));
EXPECT_ANY_THROW(ipv4::Address("1.1.1.01"));
}

// Test constructor with valid argument
TEST(Address, ConstructorValid) {
    EXPECT_NO_THROW(ipv4::Address("127.0.0.1"));
    EXPECT_NO_THROW(ipv4::Address("192.168.1.1"));
    EXPECT_NO_THROW(ipv4::Address("192.168.1.255"));
    EXPECT_NO_THROW(ipv4::Address("255.255.255.255"));
    EXPECT_NO_THROW(ipv4::Address("0.0.0.0"));
}

TEST(Address, ConstructorComparation) {
    auto addr1 = ipv4::Address("127.0.0.1");
    auto addr2 = ipv4::Address("192.168.1.1");
    auto addr3 = ipv4::Address("192.169.1.1");
    auto addr4 = ipv4::Address("192.169.1.1");
    EXPECT_TRUE(addr2 > addr1);
    EXPECT_TRUE(addr3 > addr2);
    EXPECT_TRUE(addr3 == addr4);
    EXPECT_TRUE(addr3 >= addr4);
    EXPECT_TRUE(addr3 <= addr4);
    EXPECT_TRUE(addr1 < addr4);
}

TEST(Address, ToString){
    auto addr1 = ipv4::Address("127.0.0.1");
    EXPECT_EQ(std::string(addr1), "127.0.0.1");
}
