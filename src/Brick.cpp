#include "Brick.h"

Brick::Brick(Ball* ball) : GameObject({0, 0}, {0, 0}, BLANK), ballRef(ball), count(0), couleurs{GREEN, RED, PINK, WHITE, PURPLE, GOLD, GRAY, YELLOW, RAYWHITE, BLUE, ORANGE} {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            blocs[i][j] = {(float)75 + i * 75, (float)50 + j * 25, 70, 20};
            visible[i][j] = true;
        }
    }
}

void Brick::update(float dt) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (visible[i][j]) {
                if (CheckCollisionCircleRec(ballRef->getPosition(), ballRef->getRadius(), blocs[i][j])) {
                    visible[i][j] = false;
                    count++;
                    ballRef->setVelocity({ballRef->getVelocity().x, -ballRef->getVelocity().y});
                }
            }
        }
    }
}

void Brick::draw() const {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (visible[i][j]) {
                DrawRectangleRec(blocs[i][j], couleurs[j % 11]);
            }
        }
    }

    DrawText(TextFormat("%s %d", "Point : ", count), 80, 5, 40, RED);
}