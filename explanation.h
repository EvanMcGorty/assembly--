#include<string>

std::string explanation()
{
	std::string ret;
	ret.append("Welcome to my mechanical, turing complete language that only has 4 instructions.\n");
    ret.append("Memory is a infinite list of bits, an index pointing to one of those bits, and a register bit.\n");
    ret.append("All bits and the register default to 0. The index defaults to 0, pointing to the first bit.\n");
    ret.append("The instruction \"+\" moves the index to the right when the register is 1, and left when the register is 0.\n");
    ret.append("(note that trying to decrement past the first does nothing).\n");
    ret.append("The instruction \"=\" swaps the value in the register with the value in the pointed to bit.\n");
    ret.append("The instruction \"!\" flips the register's value from 1 to 0, and from 0 to 1.\n");
    ret.append("The instruction \"/\" will jump to the previous or next instance of a \"/\" d.\n");
	ret.append("When the register is true, it will jump to the next, when it is false, it will jump to the previous.\n");
	ret.append("If it is the first/last isntance of a \"/\" in the program, it will jump to the beggining/end instead.\n");
    ret.append("The program's \"result\" is the bits in memory read as ascii up until a null terminator is found.\n");
    ret.append("have fun!\n");
	return ret;
}