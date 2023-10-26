#include "Dot.cppm"

namespace twixt {

    // Constructor
    Dot::Dot() : m_state(DotState::Clear), m_x(0), m_y(0) {}

    // Getters
    int Dot::getCoordX() {
        return m_x;
    }

    int Dot::getCoordY() {
        return m_y;
    }

    // Setters
    void Dot::setCoordX(int x) {
        m_x = x;
    }

    void Dot::setCoordY(int y) {
        m_y = y;
    }

}
