#include <viewstr/string_view_stream.hpp>

#include <iostream>

#include <cstdlib>

int main(int, char**)
{
	viewstr::string_view_stream sv_str{ "1.0 11 25 3" };
	viewstr::wstring_view_stream wsv_str{ L"1.0 11 25 3" };
	double val = 0.0;
	while (sv_str >> val) {
		std::cout << 'c' << val << std::endl;
	}
	while (wsv_str >> val) {
		std::cout << 'w' << val << std::endl;
	}
	return 0;
}


