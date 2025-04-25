#pragma once
#include "GameObject.h"
#include "Ball.h"

class Brick : public GameObject {
private:
    bool visible[9][9];
    Rectangle blocs[9][9];
    Color couleurs[11];
    Ball* ballRef;
    int count;

public:
    Brick(Ball* ball);

    void update(float dt) override;

    void draw() const override;
};