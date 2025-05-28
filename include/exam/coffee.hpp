#pragma once

#include <cstdint>
namespace exam
{
	enum class CoffeeType : std::uint8_t
	{
		ESPRESSO,
		LUNGO,
		CAPPUCCINO
	};

	class Coffee
	{
	private:
		CoffeeType m_type;
		int m_price;
		int m_stock;

	public:
		Coffee(CoffeeType type, int price, int stock);

		[[nodiscard]] auto get_type() const -> CoffeeType;
		[[nodiscard]] auto get_price() const -> int;
		[[nodiscard]] auto get_stock() const -> int;
		[[nodiscard]] auto is_available() const -> bool;
		auto dispense() -> void;
	};
}  // namespace exam
