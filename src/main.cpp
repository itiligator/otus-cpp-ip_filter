#include "../include/metainfo.h"

#include <iostream>

int main(int, char **) {
	std::cout << "Version: " << patch_number() << std::endl;
	std::cout << "Hello, world!" << std::endl;
	return 0;
}
