#pragma once

namespace exam
{
	class Card
	{
	private:
		int m_balance;

	public:
		Card(int initial_balance = 0);

		auto posit(int amount) -> void;
		auto withdraw(int amount) -> void;
		[[nodiscard]] auto getBalance() const -> int;
	};
}  // namespace exam
