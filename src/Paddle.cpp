#include "Paddle.h"
#include "Game.h"

Paddle::Paddle() : GameObject({350.0f, 950.0f}, {80.0f, 10.0f}, WHITE), speed(200.0f) {}

void Paddle::update(float dt) {

    if(Game::GetState() == RUNNING ) {

        // Ton code existant pour Update, adapté
        int blocLimitGauche = 70;
        int blocLimitDroite = 750;
        if (IsKeyDown(KEY_LEFT) && position.x > blocLimitGauche) {
            position.x -= speed * dt;
        }
        if (IsKeyDown(KEY_RIGHT) && position.x + size.x < blocLimitDroite) {
            position.x += speed * dt;
        }
    }
}

void Paddle::draw() const {
    if (active) {
        DrawRectangleV(position, size, color);
    }
}