#pragma once

#include <cstdint>
#include <string>

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
	protected:
		CoffeeType m_type;
		int m_price;
		int m_stock;

	public:
		Coffee(CoffeeType type, int price, int stock);

		virtual ~Coffee() = default;

		[[nodiscard]] virtual auto get_type() const -> CoffeeType;
		[[nodiscard]] virtual auto get_price() const -> int;
		[[nodiscard]] virtual auto get_stock() const -> int;
		[[nodiscard]] virtual auto is_available() const -> bool;
		virtual auto dispense() -> void;
	};

	auto coffee_type_to_string(CoffeeType type) -> std::string;
}  // namespace exam
