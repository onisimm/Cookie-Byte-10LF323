#include "Dot.cppm"

namespace twixt {

    // Constructor
    Dot::Dot() : m_status(DotStatus::Clear), m_x(0), m_y(0) {}

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

}
