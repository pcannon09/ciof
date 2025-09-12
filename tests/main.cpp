#include "../inc/ciof/ciof.hpp"

int main()
{
	ciof::outputConf.spacing = true;
	ciof::outputConf.ignoreAllFormating = false;

	std::string name;

	ciof::input(">> ", &name);

	ciof::print("1. You typed `%1`, type something else", name);
	ciof::print();
	ciof::echo("2. You typed `%1`, type something else\nThis text is literaly printed inside the `ciof:echo()` function", name);

	return 0;
}

