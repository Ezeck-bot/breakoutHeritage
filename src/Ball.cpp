#include "Ball.h"

Ball::Ball() : GameObject({400.0f, 500.0f}, {0.0f, 0.0f}, BLUE),
radius(15), velocity({1.0f, -1.0f}), speed(200.0f) {}

void Ball::update(float dt) {
    this->position.x += velocity.x * speed * dt;
    this->position.y += velocity.y * speed * dt;
}

void Ball::draw() const {
    if (active) {
        DrawCircleV(position, radius, color);
    }
}

Vector2 Ball::getVelocity() const {
    return this->velocity;
}

int Ball::getRadius() const {
    return this->radius;
}

float Ball::getSpeed() const {
    return this->speed;
}

void Ball::setVelocity(Vector2 vel) {
    this->velocity = vel;
}

void Ball::setRadius(int rad) {
    this->radius = rad;
}

void Ball::setSpeed(int speedBall) {
    this->speed += speedBall;
}