#include <algorithm>
#include <exam/coffee_machine.hpp>
#include <exam/exception.hpp>

namespace exam
{
	CoffeeMachine::CoffeeMachine(std::string name, std::vector<Coffee> coffees)
		: m_name{ std::move(name) },
		  m_coffees{ std::move(coffees) }
	{
	}

	auto CoffeeMachine::insert_card(std::shared_ptr<Card> card) -> void
	{
		m_inserted_card = std::move(card);
	}

	auto CoffeeMachine::choose_coffee(CoffeeType type) -> Coffee
	{
		if (!m_inserted_card)
		{
			throw NotEnoughMoneyException(0, 1);
		}

		auto it = std::find_if(m_coffees.begin(),
			m_coffees.end(),
			[type](const Coffee& coffee) { return coffee.get_type() == type; });

		if (it == m_coffees.end())
		{
			throw UnknownCoffeeException("Selected coffee type is not recognized.");
		}

		auto& coffee = *it;

		if (!coffee.is_available())
		{
			throw OutOfStockException("Selected coffee is out of stock.");
		}

		m_inserted_card->withdraw(coffee.get_price());
		coffee.dispense();
		return coffee;
	}

}  // namespace exam
