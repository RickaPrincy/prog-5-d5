#pragma once

#include <exam/exception.hpp>
#include <iostream>
#include <string>

namespace exam
{
	class Logger
	{
	public:
		static void log_error(const std::exception& e)
		{
			const std::string error_type = determine_error_type(e);
			std::cerr << "[" << error_type << "] " << e.what() << "\n";
		}

	private:
		static auto determine_error_type(const std::exception& e) -> std::string
		{
			if (dynamic_cast<const NotEnoughMoneyException*>(&e))
				return "PAYMENT_ERROR";
			if (dynamic_cast<const OutOfStockException*>(&e))
				return "STOCK_ERROR";
			if (dynamic_cast<const UnknownCoffeeException*>(&e))
				return "UNKNOWN_COFFEE_EXCEPTION";

			return "UNEXPECTED_ERROR";
		}
	};
}  // namespace exam
