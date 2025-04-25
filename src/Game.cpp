#include "Game.h"

static GameState currentState;
GameState Game::GetState(){
        
    return currentState;
}
void Game::SetState(GameState next){
        
    currentState = next;
}
Game::Game(int width, int height) : screenWidth(width), screenHeight(height) {
    currentState = RUNNING;
}


Game::~Game(){
    for (auto obj : objects) delete obj;
}

void Game::init(){
    InitWindow(screenWidth, screenHeight, "Breakout");
    SetTargetFPS(60);
}

bool Game::not_finished() const {
    return !WindowShouldClose();
}

void Game::deinit(){
    CloseWindow();
}