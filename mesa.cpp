#include "mesa.h"

Mesa::Mesa(float x, float y, float largura, float altura)
    : x(x), y(y), largura(largura), altura(altura) {}

float Mesa::getX() const {
    return x;
}

float Mesa::getY() const {
    return y;
}

float Mesa::getLargura() const {
    return largura;
}

float Mesa::getAltura() const {
    return altura;
}
