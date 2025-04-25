#pragma once
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include "Ecran.h"
#include "Game.h"

// Classe Breakout qui hérite de Game (point 4)
class Breakout : public Game {
private:
    Paddle* paddle;
    Ball* ball;
    Brick* bricks;
    Ecran* ecran;
    bool gameOver;

public:
    Breakout(int width, int height);

    void init() override;

    void update(float dt) override;

    void draw() override;
};