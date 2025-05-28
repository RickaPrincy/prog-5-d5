#pragma once

#include <stdexcept>
#include <string>

namespace exam
{
	class NotEnoughMoneyException : public std::runtime_error
	{
	public:
		NotEnoughMoneyException(int balance, int required)
			: std::runtime_error("Not enough money. Balance: " + std::to_string(balance) +
								 ", Required: " + std::to_string(required))
		{
		}
	};

	class OutOfStockException : public std::runtime_error
	{
	public:
		explicit OutOfStockException(const std::string& detail = "")
			: std::runtime_error("Out of stock. " + detail)
		{
		}
	};

	class UnknownCoffeeException : public std::runtime_error
	{
	public:
		explicit UnknownCoffeeException(const std::string& detail = "")
			: std::runtime_error("Unknown coffee selected. " + detail)
		{
		}
	};
}  // namespace exam
