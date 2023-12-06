#pragma once
#include "Painter.hpp"
#include "Point.hpp"
#include "Velocity.hpp"

class Ball {
public:
    Ball(Point center, Velocity velocity, Color color, double radius)
        : m_center(center)
        , m_velocity(velocity)
        , m_color(color)
        , m_radius(radius) {}
    void setVelocity(const Velocity& velocity);
    Velocity getVelocity() const;
    void draw(Painter& painter) const;
    void setCenter(const Point& center);
    Point getCenter() const;
    double getRadius() const;
    double getMass() const;
    void setColor(const Color& color);
private:
    Point m_center;
    Velocity m_velocity;
    Color m_color;
    double m_radius;
};
