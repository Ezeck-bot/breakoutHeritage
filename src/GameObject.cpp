#include "GameObject.h"

GameObject::GameObject(Vector2 pos, Vector2 sz, Color col)
    : position(pos), size(sz), color(col), active(true) {}

Vector2 GameObject::getPosition() const { return position; }
Vector2 GameObject::getSize() const { return size; }
bool GameObject::isActive() const { return active; }
void GameObject::setActive(bool state) { active = state; }
void GameObject::setPosition(Vector2 pos) { position = pos; }