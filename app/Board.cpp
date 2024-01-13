#include "Board.h"

namespace twixt
{

	//this function shows the board
	void Board::showBoard() const
	{
		for (size_t i = 0; i < m_matrixDot.size(); i++)
		{
			for (size_t j = 0; j < m_matrixDot[i].size(); j++)
			{
				if (m_matrixDot[i][j].get()->getStatus() == Dot::Status::Empty)
					std::cout << "_";

				if (m_matrixDot[i][j].get()->getStatus() == Dot::Status::Player1)
					std::cout << "R";

				if (m_matrixDot[i][j].get()->getStatus() == Dot::Status::Player2)
					std::cout << "B";


				if (m_matrixDot[i][j].get()->getStatus() == Dot::Status::Bulldozer)
					std::cout << "@";

				if (m_matrixDot[i][j].get()->getStatus() == Dot::Status::Mine)
					std::cout << "M";
				if (m_matrixDot[i][j].get()->getStatus() == Dot::Status::Exploded)
					std::cout << " ";


				std::cout << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\nThe existing bridges are:\n";
		if (m_bridges.size() == 0)
		{
			std::cout << "There aren't any existing bridges!\n\n";
		}
		for (auto& it : m_bridges)
		{
			std::cout << it.get()->getFirstPillar().GetPointer()->getCoordI() << " " << it.get()->getFirstPillar().GetPointer()->getCoordJ() << "  AND  " << it.get()->getSecondPillar().GetPointer()->getCoordI() << " " << it.get()->getSecondPillar().GetPointer()->getCoordJ()<<"\n";
		}
	}

	void Board::placePiece(size_t i, size_t j, Dot::Status status, bool& didMineExplode)
	{
		if (m_matrixDot[i][j]->getStatus() == Dot::Status::Empty)
		{
			placePeg(i, j, status);
		}
		else if (m_matrixDot[i][j]->getStatus() == Dot::Status::Mine) // in case there is a mine it will explode
		{
			didMineExplode = true;
			Observer_ptr<Mine> MinePointer(dynamic_cast<Mine*>(m_matrixDot[i][j].get()));
			explodeMine(MinePointer);
			std::cout << "You lost your turn!\n";
			std::cout << "Choose another mine!\n";
			showBoard();
			size_t mineI, mineJ;
			std::cin >> mineI >> mineJ;
			placeMine(mineI, mineJ);
			MinePointer.GetPointer()->setNewPlacedMine(Observer_ptr<Mine>(dynamic_cast<Mine*>(m_matrixDot[mineI][mineJ].get())));
		}
		else
		{
			std::cout << "Node already occupied!\nChoose another dot!\nEnter position: ";
			std::cin >> i >> j;
			placePiece(i, j, status, didMineExplode);
		}
	}

	void Board::placePiece(size_t i, size_t j, Dot::Status status)
	{
		bool didMineExplode = false;
		placePiece(i, j, status, didMineExplode);
	}

	Board::Board() {}

	Board::Board(uint32_t size)
	{
		m_matrixDot.resize(size);
		for (size_t i = 0; i < size; ++i)
		{
			m_matrixDot[i].resize(size);
		}

		for (size_t i = 0; i < size; ++i)
		{
			for (size_t j = 0; j < size; ++j)
			{
				m_matrixDot[i][j] = std::make_unique<Dot>(); // new Dot;
				m_matrixDot[i][j]->setCoordI(i);
				m_matrixDot[i][j]->setCoordJ(j);
			}
		}
		m_bulldozer = Observer_ptr<Bulldozer>(new Bulldozer());

		m_bridges.reserve(100);
	}

	Board::Board(const Board& newBoard)
	{
		m_matrixDot.resize(newBoard.getSize());
		for (size_t i = 0; i < newBoard.getSize(); ++i)
		{
			m_matrixDot[i].resize(newBoard.getSize());
		}

		for (size_t i = 0; i < newBoard.getSize(); ++i)
		{
			for (size_t j = 0; j < newBoard.getSize(); ++j)
			{
				m_matrixDot[i][j] = std::make_unique<Dot>(); //new Dot;
				m_matrixDot[i][j]->setCoordI(i);
				m_matrixDot[i][j]->setCoordJ(j);
				*m_matrixDot[i][j] = *newBoard.m_matrixDot[i][j];
			}
		}
		m_bulldozer = Observer_ptr<Bulldozer>(new Bulldozer());
		m_bridges.reserve(100);

	}

	// Move constructor
	Board::Board(Board&& other) noexcept
		: m_matrixDot(std::move(other.m_matrixDot)) {}

Board::~Board() {}


	std::unique_ptr<Dot>& Board::getDot(size_t i, size_t j)
	{
		if (i >= 0 && i < m_matrixDot.size() && j >= 0 && j < m_matrixDot[i].size())
		{
			return m_matrixDot[i][j];
		}

		throw std::out_of_range("Index out of bounds while trying to get Dot.");
	}

	uint32_t Board::getSize() const
	{
		//Getter for matrixSize;
		return m_matrixDot.size();
	}

	std::vector<std::vector<std::unique_ptr<Dot>>>& Board::getMatrix()
	{
		//Getter for matrix
		return m_matrixDot;
	}

	std::unique_ptr<Dot>& Board::getMatrixDot(size_t i, size_t j)
	{
		//Getter for a dot in position (i,j)
		return m_matrixDot[i][j];
	}

	std::vector<std::unique_ptr<Bridge>>& Board::getBridges()
	{
		return m_bridges;
	}

	// Move assignment operator
	Board& Board::operator=(Board&& other) noexcept {
		if (this != &other) {
			// Move matrixDot
			m_matrixDot = std::move(other.m_matrixDot);
		}
		return *this;
	}


	Board& Board::operator=(const Board& newBoard)
	{
		m_matrixDot.resize(newBoard.getSize());
		for (size_t i = 0; i < newBoard.getSize(); ++i)
		{
			m_matrixDot[i].resize(newBoard.getSize());
		}

		for (size_t i = 0; i < newBoard.getSize(); ++i)
		{
			for (size_t j = 0; j < newBoard.getSize(); ++j)
			{
				m_matrixDot[i][j] = std::make_unique<Dot>(); //new Dot;
				m_matrixDot[i][j]->setCoordI(i);
				m_matrixDot[i][j]->setCoordJ(j);
				*m_matrixDot[i][j] = *newBoard.m_matrixDot[i][j];
			}
		}
		m_bulldozer = newBoard.m_bulldozer;
		return *this;
	}


	int orientation(const Dot& p, const Dot& q, const Dot& r) {
		int val = (q.getCoordJ() - p.getCoordJ()) * (r.getCoordI() - q.getCoordI()) -
			(q.getCoordI() - p.getCoordI()) * (r.getCoordJ() - q.getCoordJ());

		if (val == 0) return 0;
		return (val > 0) ? 1 : 2;
	}

	bool onSegment(const Dot& p, const Dot& q, const Dot& r) {
		if (q.getCoordI() <= std::max(p.getCoordI(), r.getCoordI()) && q.getCoordI() >= std::min(p.getCoordI(), r.getCoordI()) &&
			q.getCoordJ() <= std::max(p.getCoordJ(), r.getCoordJ()) && q.getCoordJ() >= std::min(p.getCoordJ(), r.getCoordJ()))
			return true;
		return false;
	}

	bool twixt::doIntersect(const Dot& p1, const Dot& p2, const Dot& q1, const Dot& q2) {
		int o1 = orientation(p1, p2, q1);
		int o2 = orientation(p1, p2, q2);
		int o3 = orientation(q1, q2, p1);
		int o4 = orientation(q1, q2, p2);

		if (o1 != o2 && o3 != o4) return true;

		if (o1 == 0 && onSegment(p1, q1, p2)) return true;
		if (o2 == 0 && onSegment(p1, q2, p2)) return true;
		if (o3 == 0 && onSegment(q1, p1, q2)) return true;
		if (o4 == 0 && onSegment(q1, p2, q2)) return true;

		return false;
	}

	bool Board::checkObstructingBridges(const Peg& dot1, const Peg& dot2) const
	{
		size_t x1 = dot1.getCoordJ();
		size_t y1 = dot1.getCoordI();
		size_t x2 = dot2.getCoordJ();
		size_t y2 = dot2.getCoordI();

		// Check if any existing bridge obstructs the way from dot1 to dot2
		for (size_t i = std::min(y1, y2); i <= std::max(y1, y2); ++i)
		{
			for (size_t j = std::min(x1, x2); j <= std::max(x1, x2); ++j)
			{
				if (*m_matrixDot[i][j] == dot1 || *m_matrixDot[i][j] == dot2)
				{
					continue;
				}

				if(dynamic_cast<Peg*>(m_matrixDot[i][j].get()) != nullptr)
				{
					for (auto& bridge : dynamic_cast<Peg*>(m_matrixDot[i][j].get())->getExistingBridges())
					{
						auto [firstDot, secondDot] = bridge.GetPointer()->getPillars();
						if (doIntersect(dot1, dot2, *firstDot.GetPointer(), *secondDot.GetPointer()))
						{
							return false;
						}
					}
				}
			}
		}
		return true;
	}

	// Verify whether the path leads to win or not
	bool Board::checkPath(twixt::Dot::Status status)
	{
		std::vector<Observer_ptr<Peg>> margins = FindDotInMargins(status);
		if (margins.empty()) return false;
		size_t index = 0;
		Observer_ptr<Peg> firstDot = margins[index];
		Observer_ptr<Peg> newDot;

		//Creating path vector: pair of dot in path and position of existing bridges for the dot.
		std::vector<std::pair<Observer_ptr<Peg>, size_t>> path;

		bool isFinalDot = false;
		path.push_back({firstDot, 0 });
		while (!isFinalDot && !path.empty())
		{
			auto [checkDot, position] = path[path.size() - 1];
			if (position < checkDot.GetPointer()->getExistingBridges().size())
			{
				newDot = checkDot.GetPointer()->getExistingBridges()[position].GetPointer()->returnTheOtherPillar(checkDot);
				if (!newDot.GetPointer()->isPegInPath(path))
				{
					path.push_back({ newDot, -1 });
					checkDot = path[path.size() - 1].first;
					if (checkFinalMargin(checkDot, status))
					{
						isFinalDot = true;
					}
				}
			}
			else
			{
				path.pop_back();
			}
			if (!path.empty())
				path[path.size() - 1].second++;
			else
			{
				index++;
				if (index < margins.size())
				{
					path.push_back({ margins[index], 0 });
				}
			}

		}
		return isFinalDot;
	}

	std::vector<Observer_ptr<Peg>> Board::FindDotInMargins(Dot::Status status)
	{
		std::vector<Observer_ptr<Peg>> margin;
		if (status == Dot::Status::Player1)
		{
			for (size_t i = 0; i < m_matrixDot.size(); i++)
			{
				if (m_matrixDot[0][i]->getStatus() == Dot::Status::Player1)
				{
					margin.push_back(Observer_ptr<Peg>(dynamic_cast<Peg*>(m_matrixDot[0][i].get())));
				}
				if (m_matrixDot[1][i]->getStatus() == Dot::Status::Player1)
				{
					margin.push_back(Observer_ptr<Peg>(dynamic_cast<Peg*>(m_matrixDot[1][i].get())));
				}
			}
		}
		else
		{
			for (size_t i = 0; i < m_matrixDot.size(); i++)
			{
				if (m_matrixDot[i][0]->getStatus() == Dot::Status::Player2)
				{
					margin.push_back(Observer_ptr<Peg>(dynamic_cast<Peg*>(m_matrixDot[i][0].get())));
				}
				if (m_matrixDot[i][1]->getStatus() == Dot::Status::Player2)
				{
					margin.push_back(Observer_ptr<Peg>(dynamic_cast<Peg*>(m_matrixDot[i][1].get())));
				}
			}
		}
		return margin;
	}

	bool Board::checkFinalMargin(Observer_ptr<Peg> dotToCheck, Dot::Status status)
	{
		if (status == Dot::Status::Player1)
		{
			for (size_t i = 0; i < m_matrixDot.size(); i++)
			{
				if (dotToCheck.GetPointer() == m_matrixDot[m_matrixDot.size() - 1][i].get() || dotToCheck.GetPointer() == m_matrixDot[m_matrixDot.size() - 2][i].get())
				{
					return true;
				}
			}
		}
		else
		{
			for (size_t i = 0; i < m_matrixDot.size(); i++)
			{
				if (dotToCheck.GetPointer() == m_matrixDot[i][m_matrixDot.size() - 1].get() || dotToCheck.GetPointer() == m_matrixDot[i][m_matrixDot.size() - 2].get())
				{
					return true;
				}
			}
		}
		return false;
	}

	void Board::deleteBridgeInBoard(Observer_ptr<Peg> firstDot, Observer_ptr<Peg> secondDot)
	{
		for (auto it = m_bridges.begin(); it!= m_bridges.end(); it++)
			{
				if (it->get()->isPillarInBridge(firstDot) && it->get()->isPillarInBridge(secondDot))
				{
					firstDot.GetPointer()->removeBridgeFromExisting(Observer_ptr<Bridge>(it->get()));
					secondDot.GetPointer()->removeBridgeFromExisting(Observer_ptr<Bridge>(it->get()));
					m_bridges.erase(it);
					break;
				}
			}
	}

	void Board::deleteAllBridgesForAPegInBoard(Observer_ptr<Peg> peg)
	{
		auto existingBridges = peg.GetPointer()->getExistingBridges();  // Store the result in a local variable
		for (auto it = existingBridges.begin(); it != existingBridges.end(); it++)
		{
			deleteBridgeInBoard(peg, it->GetPointer()->returnTheOtherPillar(peg));
		}
	}

	void Board::placePeg(size_t i,size_t j, Dot::Status status)
	{
		m_matrixDot[i][j].reset(new Peg());
		m_matrixDot[i][j]->setStatus(status);
		m_matrixDot[i][j]->setCoordI(i);
		m_matrixDot[i][j]->setCoordJ(j);
	}
	void Board::addBridgeInBoard(Observer_ptr<Peg> firstPeg, Observer_ptr<Peg> secondPeg)
	{
		m_bridges.resize(m_bridges.size() + 1);
		m_bridges[m_bridges.size()-1].reset(new Bridge(firstPeg, secondPeg));
		firstPeg.GetPointer()->addBridge(Observer_ptr<Bridge>(m_bridges[m_bridges.size()-1].get()));
		secondPeg.GetPointer()->addBridge(Observer_ptr<Bridge>(m_bridges[m_bridges.size()-1].get()));
	}


	void Board::placeMine(size_t i, size_t j)
	{
		std::cout << "MINE PLACED on " << i << " " << j << "\n";
		m_matrixDot[i][j].reset(new Mine());
		m_matrixDot[i][j]->setStatus(Dot::Status::Mine);
		m_matrixDot[i][j]->setCoordI(i);
		m_matrixDot[i][j]->setCoordJ(j);
	}
	void Board::placeRandomMine()
	{
		srand(time(NULL));
		size_t i = rand() % (m_matrixDot.size()-2) + 1;
		size_t j = rand() % (m_matrixDot.size()-2) + 1;
		while (m_matrixDot[i][j]->getStatus() != Dot::Status::Empty)
		{
			i = rand() % (m_matrixDot.size()-2) + 1;
			j = rand() % (m_matrixDot.size()-2) + 1;
		}
		placeMine(i, j);
	}

	void Board::explodeMine(Observer_ptr<Mine> mine)
	{
		std::array<std::pair<int, int>, 8> positions{ { {-1, -1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1} } };
		size_t i = mine.GetPointer()->getCoordI();
		size_t j = mine.GetPointer()->getCoordJ();

		mine.GetPointer()->setTrigger(true);
		for (auto pair : positions)
		{
			auto [newI, newJ] = pair;
			newI += i;
			newJ += j;
			if (newI >= 0 && newI < m_matrixDot.size() && newJ >= 0 && newJ < m_matrixDot[newI].size()) // check boundaries
			{

				if (m_matrixDot[newI][newJ].get()->getStatus() == Dot::Status::Player1 || m_matrixDot[newI][newJ].get()->getStatus() == Dot::Status::Player2)
				{
					mine.GetPointer()->setExplodedDots(m_matrixDot[newI][newJ]);
					deleteAllBridgesForAPegInBoard(Observer_ptr<Peg>(dynamic_cast<Peg*>(m_matrixDot[newI][newJ].get())));
					m_matrixDot[newI][newJ].reset(new Dot(newI, newJ));
				}
				if (m_matrixDot[newI][newJ].get()->getStatus() == Dot::Status::Mine && (dynamic_cast<Mine*>(m_matrixDot[newI][newJ].get()))->getTrigger() == false)
				{
					explodeMine(Observer_ptr<Mine>(dynamic_cast<Mine*>(m_matrixDot[newI][newJ].get())));
					mine.GetPointer()->setExplodedDots(m_matrixDot[newI][newJ]);
				}
				m_matrixDot[newI][newJ].get()->setStatus(Dot::Status::Exploded);
			}
		}
		m_matrixDot[i][j].get()->setStatus(Dot::Status::Exploded);
	}
}