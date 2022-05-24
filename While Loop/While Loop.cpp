#include "header.h"
#include <string>
#include <forward_list>

// The <signature> definition(s)
std::string buildTheString(std::forward_list<char> const& char_list);

int main() {
	return 0;
}

std::string buildTheString(std::forward_list<char> const& char_list) {
	auto itr = char_list.cbegin();
	auto eitr = char_list.cend();
	std::string thebuild;

	while (itr != eitr) {
		char c = *itr;
		thebuild += c;

		itr++;
	}
	return thebuild;
}