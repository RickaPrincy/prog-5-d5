#include <exam/coffee.hpp>
#include <exam/exception.hpp>

namespace exam
{
	auto coffee_type_to_string(CoffeeType type) -> std::string
	{
		switch (type)
		{
			case CoffeeType::ESPRESSO: return "Espresso";
			case CoffeeType::LUNGO: return "Lungo";
			case CoffeeType::CAPPUCCINO: return "Cappuccino";
			default: return "Unknown";
		}
	}

	Coffee::Coffee(CoffeeType type, int price, int stock)
		: m_type{ type },
		  m_price{ price },
		  m_stock{ stock }
	{
	}

	auto Coffee::get_type() const -> CoffeeType
	{
		return m_type;
	}

	auto Coffee::get_price() const -> int
	{
		return m_price;
	}

	auto Coffee::get_stock() const -> int
	{
		return m_stock;
	}

	auto Coffee::is_available() const -> bool
	{
		return m_stock > 0;
	}

	auto Coffee::dispense() -> void
	{
		if (m_stock <= 0)
		{
			throw OutOfStockException(coffee_type_to_string(m_type) + " is out of stock.");
		}
		--m_stock;
	}
}  // namespace exam
