#pragma once
#include "GameObject.h"

class Paddle : public GameObject {
private:
    float speed;

public:
    Paddle();

    void update(float dt) override;

    void draw() const override;
};