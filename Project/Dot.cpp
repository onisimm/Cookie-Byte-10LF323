#include "Dot.h"

namespace twixt {

    // Constructors
    Dot::Dot() : m_status(DotStatus::Clear), m_x(0), m_y(0) {}

    Dot::Dot(const Dot& newDot) : m_status(newDot.m_status), m_x(newDot.m_x), m_y(newDot.m_y) {}

    // Destructor
    Dot::~Dot() {}

    // Getters
    int Dot::getCoordX() {
        return m_x;
    }

    int Dot::getCoordY() {
        return m_y;
    }

    twixt::Dot::DotStatus Dot::getStatus() const {
        return m_status;
    }

    // Setters
    void Dot::setCoordX(int x) {
        m_x = x;
    }

    void Dot::setCoordY(int y) {
        m_y = y;
    }

    void Dot::setStatus(DotStatus status) {
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

}
