#include <string>
#include <vector>
#include <sstream>
#include <bitset>

std::string binary_to_code(std::string binary)
{
	std::string ret = "!";
	for (auto v : binary)
	{
		if (v != '1' && v != '0')
		{
			return std::string("1s and 0s only");
		}
		if (v == '1')
		{
			ret.append("=!");
		}
		ret.push_back('+');
	}
	ret.push_back('!');
	for (int i = 0; i != binary.size(); ++i)
	{
		ret.push_back('+');
	}
	return ret;
}

std::string string_to_binary(std::string text)
{
	std::stringstream ret;
	for (auto c : text)
	{
		ret << std::bitset<8>(c);
	}
	return ret.str();
}

#include "../expression-evaluator/include/expression-evaluator/evaluator.h"

int main()
{
	expr::interpreter env;
	env.functions
		<< "cp" << expr::sfn(&binary_to_code)
		<< "bn" << expr::sfn(&string_to_binary);
	env.go();
}