#include "../include/Component/Collider.h"

Collider::Collider(int* x, int* y, int w, int h)
: xpos(x), ypos(y), width(w), height(h)
{
    colliderRect = {*xpos, *ypos, width, height};
}

Collider::~Collider() {}


