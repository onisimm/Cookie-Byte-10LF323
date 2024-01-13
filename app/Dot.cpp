#include "Dot.h"
#include <iostream>

namespace twixt {

    // Constructors
    Dot::Dot() : m_status{ DotStatus::Clear }, m_i{ 0 }, m_j{ 0 } {}
    Dot::Dot(size_t i, size_t j) : m_status{ DotStatus::Clear }, m_i{ i }, m_j{ j } {}
    Dot::Dot(const Dot& newDot) : m_status{ newDot.m_status }, m_i{ newDot.m_i }, m_j{ newDot.m_j }
    {}

    Dot::Dot(Dot&& other) noexcept
        : m_status(other.m_status),
        m_i(other.m_i),
        m_j(other.m_j){
        // Reset the moved from object
        other.m_status = DotStatus::Clear;
        other.m_i = 0;
        other.m_j = 0;
    }


    Dot& Dot::operator=(Dot&& other) noexcept {
        if (this != &other) {
            // Release resources from the current object

            // Move resources from the other object
            m_status = other.m_status;
            m_i = other.m_i;
            m_j = other.m_j;
           
            // Reset the moved from object
            other.m_status = DotStatus::Clear;
            other.m_i = 0;
            other.m_j = 0;
        }
        return *this;
    }

    // Destructor
    Dot::~Dot() {}

    // Getters
    size_t Dot::getCoordI() const
    {
        return m_i;
    }

    size_t Dot::getCoordJ() const
    {
        return m_j;
    }

    twixt::Dot::DotStatus Dot::getStatus() const
    {
        return m_status;
    }

    // Setters
    void Dot::setCoordI(size_t x)
    {
        m_i = x;
    }

    void Dot::setCoordJ(size_t y)
    {
        m_j = y;
    }

    void Dot::setStatus(const DotStatus& status)
    {
        m_status = status;
    }

    // Operatorul egal
    Dot& Dot::operator=(const Dot& newDot)
    {
        this->m_status = newDot.m_status;
        this->m_i = newDot.m_i;
        this->m_j = newDot.m_j;
        return *this;
    }

    bool Dot::operator==(const Dot& otherDot) const
    {
        return this->m_i == otherDot.m_i && this->m_j == otherDot.m_j;
    }

    //std::ostream& operator<<(std::ostream& os, const twixt::Dot& dot) {
    //    // Output the relevant information about the Dot object
    //    os << "Dot Position: (" << dot.getCoordI() << ", " << dot.getCoordJ() << ") "
    //        << "Status: ";

    //    /*switch (dot.getStatus()) {
    //    case twixt::Dot::DotStatus::Player1:
    //        os << "Player1";
    //        break;
    //    case twixt::Dot::DotStatus::Player2:
    //        os << "Player2";
    //        break;
    //    case twixt::Dot::DotStatus::Clear:
    //        os << "Clear";
    //        break;
    //    }*/

    //    //os << ", Possible Bridges: " << dot.getPossibleBridges().size()
    //    //    << ", Existing Bridges: " << dot.getExistingBridges().size();

    //    os << std::endl;

    //    return os;
    //}

}
