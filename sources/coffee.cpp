#include <exam/coffee.hpp>
#include <exam/exception.hpp>

namespace exam
{
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
			throw OutOfStockException("Cannot dispense: out of stock.");
		}
		--m_stock;
	}
}  // namespace exam
