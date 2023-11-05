#include <vector>
#include <iostream>
#include "Dot.h"

namespace twixt {
	class Board {
	public:
		// Constructors
		Board();
		Board(uint32_t size);
		Board(const Board& newBoard);

		// Destructor
		~Board();

		enum class TypeOfBridge : uint8_t
		{
			HorizontallUphill, // _-
			HorizontallDownhill, // -_
			VerticalUphill, // /
			VerticalDownhill // \ 
		};

		// Getters
		Dot getDot(int i, int j) const;

		// Setters
		void setDot(int i, int j, const Dot& dot);

		// Operators Overload
		Board& operator=(const Board& newBoard);

		void showBoard() const;
		bool isAvailableDot(const Dot& dot) const;
		void makeStatus(int i, int j, Dot::DotStatus status);

		bool checkObstructingBridges(const Dot& dot1, const Dot& dot2, const Board::TypeOfBridge& bridgeType) const;
		TypeOfBridge getTypeOfBridge(const Dot& dot1, const Dot& dot2) const;
		void buildPossibleBridges(Dot & dot);

	private:
		std::vector<std::vector<Dot>> m_matrixDot;
	};
}