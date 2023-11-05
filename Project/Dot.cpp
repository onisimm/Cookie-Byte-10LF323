#include "Dot.h"
#include <iostream>

namespace twixt {

    // Constructors
    Dot::Dot() : m_status(DotStatus::Clear), m_x(0), m_y(0) {}
    Dot::Dot(const Dot& newDot) : m_status(newDot.m_status), m_x(newDot.m_x), m_y(newDot.m_y) {}

    // Destructor
    Dot::~Dot() {}

    // Getters
    int Dot::getCoordX() const
    {
        return m_x;
    }

    int Dot::getCoordY() const
    {
        return m_y;
    }

    twixt::Dot::DotStatus Dot::getStatus() const 
    {
        return m_status;
    }

    // Setters
    void Dot::setCoordX(int x) 
    {
        m_x = x;
    }

    void Dot::setCoordY(int y) 
    {
        m_y = y;
    }

    void Dot::setStatus(DotStatus status) 
    {
        m_status = status;
    }

    // Operatorul egal
    Dot& Dot::operator=(const Dot& newDot)
    {
        this->m_status = newDot.m_status;
        this->m_x = newDot.m_x;
        this->m_y = newDot.m_y;
        return *this;
    }

    void Dot::addPossibleBridge(Dot* possibleBridgeDot)
    {
        if (std::find(m_possibleBridges.begin(), m_possibleBridges.end(), possibleBridgeDot) == m_possibleBridges.end())
        {
            m_possibleBridges.push_back(possibleBridgeDot);
        }
    }

    const std::vector<Dot*>& Dot::getPossibleBridges() const 
    {
        return m_possibleBridges;
    }

    void Dot::clearPossibleBridges()
    {
        m_possibleBridges.clear();
    }

    void Dot::buildBridge(Dot* connectionDot)
    {
        m_existingBridges.push_back(connectionDot);

        std::cout << "BUILT BRIDGE between " << this->getCoordX() << " " << this->getCoordY() << 
            " AND " << connectionDot->getCoordX() << " " << connectionDot->getCoordY() << std::endl;
    }

    const std::vector<Dot*>& Dot::getExistingBridges() const
    {
        return m_existingBridges;
    }

    const bool& Dot::checkExistingBridge(Dot* dotToCheck) const
    {
        return std::find(m_existingBridges.begin(), m_existingBridges.end(), dotToCheck) != m_existingBridges.end();
    }

    void Dot::possibleToExistingBridges()
    {
        for (auto dotForBridge : getPossibleBridges())
        {
            buildBridge(dotForBridge);
        }

        clearPossibleBridges();
    }

    void Dot::clearExistingBridges()
    {
        m_existingBridges.clear();
    }

    
}
