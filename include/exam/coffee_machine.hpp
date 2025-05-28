#pragma once

#include <exam/card.hpp>
#include <exam/coffee.hpp>
#include <memory>
#include <string>
#include <vector>

namespace exam
{
	class CoffeeMachine
	{
	private:
		std::string m_name{};
		std::vector<Coffee> m_coffees{};
		std::shared_ptr<Card> m_inserted_card = nullptr;

	public:
		CoffeeMachine(std::string name, std::vector<Coffee> coffees);

		auto insert_card(std::shared_ptr<Card> card) -> void;
		auto choose_coffee(CoffeeType type) -> Coffee;
		auto take_out_card() -> std::shared_ptr<Card>;
	};
}  // namespace exam
