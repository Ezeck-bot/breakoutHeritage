#pragma once
#include <vector>
#include "GameObject.h"
enum GameState {
    RUNNING,
    GAMEOVER,
    END
};


class Game {
protected:
    int screenWidth;
    int screenHeight;
    std::vector<GameObject*> objects;
    
    static void SetState(GameState next);
public:
    static GameState GetState();
    Game(int width, int height);
    virtual ~Game();

    virtual void init();

    virtual void update(float dt) = 0;
    virtual void draw() = 0;

    virtual bool not_finished() const;

    virtual void deinit();
};