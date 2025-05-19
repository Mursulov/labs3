#include <print.hpp>

void print(const std::string& text, std::ostrem& out)
{
	out << text;
}
void print(const std::string& text, std::ofstream& out)
{
	out << text;
}
