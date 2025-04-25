#pragma once
#include "GameObject.h"

class Ball : public GameObject {
private:
    int radius;
    Vector2 velocity;
    float speed;

public:
    Ball();

    void update(float dt) override;

    void draw() const override;

    Vector2 getVelocity() const;
    int getRadius() const;
    float getSpeed() const;

    void setVelocity(Vector2 vel);
    void setRadius(int rad);
    void setSpeed(int speedBall);
};