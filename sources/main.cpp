#include <exam/exam.hpp>
#include <exam/examConfig.hpp>
#include <iostream>

auto exam::sum(int a, int b) -> int
{
	return a + b;
}

auto main(int argc, char *argv[]) -> int
{
	std::cout << "sum " << exam::sum(1, 4) << "\n";
	return 0;
}
