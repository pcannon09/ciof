#include "../inc/ciof/ciof.hpp"

int main()
{
	ciof::outputConf.spacing = true;

	const char *msg = "user";
	std::string inputVar;

	ciof::echo("Hello world! %2 How are you? %1\n", msg, "friend");

	ciof::input(&inputVar);

	ciof::print(inputVar);

	return 0;
}

