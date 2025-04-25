#include "Ecran.h"

Ecran::Ecran() : GameObject({0, 0}, {0, 0}, BLANK), 
    bloc_gauche({50, 0, 20, 1000}), 
    bloc_droite({750, 0, 20, 1000}), 
    bloc_bas({0, 990, 800, 100}) {}

void Ecran::draw() const {
    DrawRectangleRec(bloc_gauche, RAYWHITE);
    DrawRectangleRec(bloc_droite, RAYWHITE);
    DrawRectangleRec(bloc_bas, BLACK);
}

void Ecran::update(float dt) {

}

Rectangle Ecran::getBloc(BlocType type) const {
    if (type == GAUCHE){
        return bloc_gauche;
    } else if (type == DROITE) {
        return bloc_droite;
    } else if (type == BAS) {
        return bloc_bas;
    }
}