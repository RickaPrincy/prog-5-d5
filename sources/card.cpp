#include <exam/card.hpp>
#include <exam/exception.hpp>

namespace exam
{
	Card::Card(int initial_balance) : m_balance(initial_balance)
	{
	}

	auto Card::deposit(int amount) -> void
	{
		if (amount < 0)
		{
			throw std::invalid_argument("cannot deposit a negative amount");
		}
		m_balance += amount;
	}

	auto Card::withdraw(int amount) -> void
	{
		if (amount < 0)
		{
			throw std::invalid_argument("cannot withdraw a negative amount");
		}

		if (amount > m_balance)
		{
			throw NotEnoughMoneyException(m_balance, amount);
		}
		m_balance -= amount;
	}

	auto Card::get_balance() const -> int
	{
		return m_balance;
	}
}  // namespace exam
