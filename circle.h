// Circulo.hpp
#ifndef CIRCULO_H
#define CIRCULO_H

#include "mesa.h"

class Circulo {
public:
    Circulo(float x, float y, float raio, float dx, float dy);

    void atualizar();
    void verificarColisaoBorda(const Mesa& mesa);
    void verificarColisaoCirculo(Circulo& outro);

    float getX() const;
    float getY() const;
    float getRaio() const;

private:
    float x, y;
    float raio;
    float dx, dy;
};

#endif // CIRCULO_HPP
