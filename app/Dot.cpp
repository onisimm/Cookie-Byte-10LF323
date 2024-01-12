#include "Dot.h"
#include <iostream>

namespace twixt {

    // Constructors
    Dot::Dot() : m_status{ DotStatus::Clear }, m_i{ 0 }, m_j{ 0 } {}
    Dot::Dot(int i, int j) : m_status{ DotStatus::Clear }, m_i{ i }, m_j{ j } {}
    Dot::Dot(const Dot& newDot) : m_status{ newDot.m_status }, m_i{ newDot.m_i }, m_j{ newDot.m_j }//, m_existingBridges{newDot.m_existingBridges} 
    {
        //de vazut ce facem cu m_existingBridges
        for (auto bridges : newDot.m_existingBridges)
        {
            m_existingBridges.push_back(new Bridge(bridges->getFirstPillar(), bridges->getSecondPillar()));
        }
    }

    Dot::Dot(Dot&& other) noexcept
        : m_status(other.m_status),
        m_i(other.m_i),
        m_j(other.m_j),
        m_existingBridges(std::move(other.m_existingBridges)) {
        // Reset the moved from object
        other.m_status = DotStatus::Clear;
        other.m_i = 0;
        other.m_j = 0;
        other.m_existingBridges.clear();
    }
    

    Dot& Dot::operator=(Dot&& other) noexcept {
        if (this != &other) {
            // Release resources from the current object
            m_existingBridges.clear();

            // Move resources from the other object
            m_status = other.m_status;
            m_i = other.m_i;
            m_j = other.m_j;
            m_existingBridges = std::move(other.m_existingBridges);

            // Reset the moved from object
            other.m_status = DotStatus::Clear;
            other.m_i = 0;
            other.m_j = 0;
            other.m_existingBridges.clear();
        }
        return *this;
    }

    // Destructor
    Dot::~Dot() {}

    // Getters
    int Dot::getCoordI() const
    {
        return m_i;
    }

    int Dot::getCoordJ() const
    {
        return m_j;
    }

    twixt::Dot::DotStatus Dot::getStatus() const
    {
        return m_status;
    }

    // Setters
    void Dot::setCoordI(int x)
    {
        m_i = x;
    }

    void Dot::setCoordJ(int y)
    {
        m_j = y;
    }

    void Dot::setStatus(const DotStatus& status)
    {
        m_status = status;
    }

    void Dot::setExistingBridges(const std::vector<Bridge*>& existingBridges)
    {
        m_existingBridges = existingBridges;
    }

    // Operatorul egal
    Dot& Dot::operator=(const Dot& newDot)
    {
        this->m_status = newDot.m_status;
        this->m_i = newDot.m_i;
        this->m_j = newDot.m_j;
        for (auto bridges : newDot.m_existingBridges)
        {
            m_existingBridges.push_back(new Bridge(bridges->getFirstPillar(), bridges->getSecondPillar()));
        }
        return *this;
    }

    bool Dot::operator==(const Dot& otherDot) const
    {
        return this->m_i == otherDot.m_i && this->m_j == otherDot.m_j;
    }


    const std::vector<Bridge*>& Dot::getExistingBridges() const
    {
        return m_existingBridges;
    }

   /* const bool& Dot::checkExistingBridge(Dot* dotToCheck) const
    {
        std::cout << "S a apelat check exisgting bridges";
        return std::find(m_existingBridges.begin(), m_existingBridges.end(), dotToCheck) != m_existingBridges.end();
    }*/

    bool Dot::isDotInPath(std::vector<std::pair<Dot*, int>> path) const
    {
        for (auto i : path)
            if (i.first == this)
                return true;
        return false;
    }

    void Dot::deleteAllBridgesForADot()
    {
        for (auto i : m_existingBridges)
        {
            std::cout << "DELETED BRIDGE between " << i->getFirstPillar()->getCoordI() << " "<< i->getFirstPillar()->getCoordJ() << " AND " << i->getSecondPillar()->getCoordI() << " " << i->getSecondPillar()->getCoordJ() << "\n";
             i->deleteBridge();
        }
    }

    void Dot::removeBridgeFromExisting(Bridge* bridge)
    {
        m_existingBridges.erase(find(m_existingBridges.begin(), m_existingBridges.end(), bridge));
    }

    Dot::DotStatus Dot::returnTheOtherPlayer()
    {
        if (m_status == Dot::DotStatus::Player1)
            return Dot::DotStatus::Player2;
        if (m_status == Dot::DotStatus::Player2)
            return Dot::DotStatus::Player1;
        return Dot::DotStatus::Clear;
    }

    Bridge* Dot::getBridgeFromDots(Dot* secondDot)
    {
        for (auto i : m_existingBridges)
        {
            if (i->isPillarInBridge(secondDot))
            {
                return i;
            }
        }
        return nullptr;
    }

    void Dot::addBridge(Dot* connectionDot)
    {
        std::cout << "BUILD BRIDGE BETWEEN " << m_i << " " << m_j << " AND " << connectionDot->getCoordI() << " " << connectionDot->getCoordJ() << "\n";
        Bridge* newBridge = new Bridge(this, connectionDot);
        m_existingBridges.push_back(newBridge);
        connectionDot->m_existingBridges.push_back(newBridge);
    }

    void Dot::clearExistingBridges()
    {
        deleteAllBridgesForADot();
    }

    std::ostream& operator<<(std::ostream& os, const twixt::Dot& dot) {
        // Output the relevant information about the Dot object
        os << "Dot Position: (" << dot.getCoordI() << ", " << dot.getCoordJ() << ") "
            << "Status: ";

        /*switch (dot.getStatus()) {
        case twixt::Dot::DotStatus::Player1:
            os << "Player1";
            break;
        case twixt::Dot::DotStatus::Player2:
            os << "Player2";
            break;
        case twixt::Dot::DotStatus::Clear:
            os << "Clear";
            break;
        }*/

        //os << ", Possible Bridges: " << dot.getPossibleBridges().size()
        //    << ", Existing Bridges: " << dot.getExistingBridges().size();

        os << std::endl;

        return os;
    }

}
