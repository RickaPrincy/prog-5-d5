#pragma once
#include <stdexcept>

namespace exam
{
	class NotEnoughMoneyException : public std::runtime_error
	{
	public:
		NotEnoughMoneyException() : std::runtime_error("Not enough money.")
		{
		}
	};

	class OutOfStockException : public std::runtime_error
	{
	public:
		OutOfStockException() : std::runtime_error("Out of stock.")
		{
		}
	};

	class UnknownCoffeeException : public std::runtime_error
	{
	public:
		UnknownCoffeeException() : std::runtime_error("Unknown coffee selected.")
		{
		}
	};
}  // namespace exam
