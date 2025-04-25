#include "entrypoint.h"
#include "Game.h"
#include "Breakout.h"

//Creer votre class Engin ici et appeler une fonction start que vous définisser à la classe dans la fonction raylib_start plus bas.
void raylib_start(void){
    Game* game = new Breakout(800, 1000);
    game->init();
    while (game->not_finished()) {
        float dt = GetFrameTime();
        game->update(dt);
        game->draw();
    }
    game->deinit();
    delete game;
}