#pragma once
#include "raylib.h"

class GameObject {
protected:
    Vector2 position;
    Vector2 size;
    Color color;
    bool active;

public:
    GameObject(Vector2 pos, Vector2 sz, Color col);

    virtual ~GameObject() {}

    virtual void update(float dt) = 0;
    virtual void draw() const = 0;

    Vector2 getPosition() const;
    Vector2 getSize() const;
    bool isActive() const;
    void setActive(bool state);
    void setPosition(Vector2 pos);
};