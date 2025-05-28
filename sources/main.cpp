#include <exam/card.hpp>
#include <exam/coffee.hpp>
#include <exam/coffee_machine.hpp>
#include <exam/exception.hpp>
#include <exam/logger.hpp>
#include <memory>
#include <vector>

using namespace exam;

auto main() -> int
{
	std::vector<Coffee> coffees{ Coffee(CoffeeType::ESPRESSO, 3, 10),
		Coffee(CoffeeType::LUNGO, 4, 5),
		Coffee(CoffeeType::CAPPUCCINO, 5, 0) };

	CoffeeMachine machine("SuperCoffee 3000", coffees);

	auto card = std::make_shared<Card>(10);
	try
	{
		machine.insert_card(card);

		Coffee c1 = machine.choose_coffee(CoffeeType::ESPRESSO);
		Coffee c2 = machine.choose_coffee(CoffeeType::CAPPUCCINO);
		std::shared_ptr<Card> my_card = machine.take_out_card();
	}
	catch (const std::exception& e)
	{
		Logger::log_error(e);
	}

	return 0;
}
