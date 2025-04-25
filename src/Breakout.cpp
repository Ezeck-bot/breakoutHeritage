#include "Breakout.h"

Breakout::Breakout(int width, int height) : Game(width, height), paddle(nullptr), ball(nullptr), bricks(nullptr), ecran(nullptr), gameOver(false) {}

void Breakout::init() {
    Game::init();

    ball = new Ball();
    paddle = new Paddle();
    bricks = new Brick(ball);
    ecran = new Ecran();
    objects.push_back(ecran);
    objects.push_back(paddle);
    objects.push_back(ball);
    objects.push_back(bricks);
}

void Breakout::update(float dt) {
    for (auto obj : objects) {
        if (obj->isActive()) obj->update(dt);
    }
    // Collision balle-raquette
    if (CheckCollisionCircleRec(ball->getPosition(), ball->getRadius(),
                                {paddle->getPosition().x, paddle->getPosition().y, paddle->getSize().x, paddle->getSize().y})) {
        ball->setVelocity({ball->getVelocity().x, -ball->getVelocity().y});
    }
    
    //Collision balle - blocs gauche
    if (CheckCollisionCircleRec(ball->getPosition(), ball->getRadius(), ecran->getBloc(GAUCHE))) {
        Vector2 newPos = ball->getPosition();
        newPos.x = ecran->getBloc(GAUCHE).x + ecran->getBloc(GAUCHE).width + ball->getRadius();
        ball->setPosition(newPos);
        ball->setVelocity({-ball->getVelocity().x, ball->getVelocity().y});
    }

    //Collision balle - blocs droite
    if (CheckCollisionCircleRec(ball->getPosition(), ball->getRadius(), ecran->getBloc(DROITE))) {
        Vector2 newPos = ball->getPosition();
        newPos.x = ecran->getBloc(DROITE).x - ball->getRadius();
        ball->setPosition(newPos);
        ball->setVelocity({-ball->getVelocity().x, ball->getVelocity().y});
    }

    //Collision balle - blocs bas
    if (CheckCollisionCircleRec(ball->getPosition(), ball->getRadius(), ecran->getBloc(BAS))) {
        gameOver = true;
        Game::SetState(END);
    }
    
    // Collision balle-haut (plafond)
    if (ball->getPosition().y - ball->getRadius() < 0) {
        ball->setVelocity({ball->getVelocity().x, -ball->getVelocity().y});
    }
}

void Breakout::draw() {
    BeginDrawing();
    ClearBackground(BLACK);
    if (gameOver)
    {
        DrawText("GAME OVER", 150, screenHeight/2, 80, RED);
    }
    for (auto obj : objects) {
        if (obj->isActive()) obj->draw();
    }
    EndDrawing();
}