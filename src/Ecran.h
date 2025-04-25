#pragma once
#include "GameObject.h"

typedef enum {
    GAUCHE,
    DROITE,
    BAS
} BlocType;

class Ecran : public GameObject {
private:
    Rectangle bloc_gauche;
    Rectangle bloc_droite;
    Rectangle bloc_bas;
    
public:
    Ecran();
    
    void update(float dt) override;

    void draw() const override;

    Rectangle getBloc(BlocType type) const;
};