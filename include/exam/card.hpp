#pragma once

namespace exam
{
	class Card
	{
	protected:
		int m_balance;

	public:
		Card(int initial_balance = 0);

		virtual ~Card() = default;
		virtual auto deposit(int amount) -> void;
		virtual auto withdraw(int amount) -> void;
		[[nodiscard]] virtual auto get_balance() const -> int;
	};
}  // namespace exam
