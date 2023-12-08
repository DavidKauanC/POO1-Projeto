// Circulo.cpp
#include "circle.h"
#include <cmath>

Circulo::Circulo(float x, float y, float raio, float dx, float dy)
    : x(x), y(y), raio(raio), dx(dx), dy(dy) {}

void Circulo::atualizar() {
    x += dx;
    y += dy;
}

void Circulo::verificarColisaoBorda(const Mesa& mesa) {
    if (x - raio < mesa.getX()) {
        x = mesa.getX() + raio;  // Corrigir posição se ultrapassar à esquerda da mesa
        dx = -dx;                // Inverter direção
    } else if (x + raio > mesa.getX() + mesa.getLargura()) {
        x = mesa.getX() + mesa.getLargura() - raio;  // Corrigir posição se ultrapassar à direita da mesa
        dx = -dx;                                   // Inverter direção
    }

    if (y - raio < mesa.getY()) {
        y = mesa.getY() + raio;  // Corrigir posição se ultrapassar acima da mesa
        dy = -dy;                // Inverter direção
    } else if (y + raio > mesa.getY() + mesa.getAltura()) {
        y = mesa.getY() + mesa.getAltura() - raio;  // Corrigir posição se ultrapassar abaixo da mesa
        dy = -dy;                                   // Inverter direção
    }
}

void Circulo::verificarColisaoCirculo(Circulo& outro) {
    float distancia = std::sqrt(std::pow(outro.x - x, 2) + std::pow(outro.y - y, 2));
    if (distancia < 2 * raio) {
        // Trocar velocidades
        float tempDx = dx;
        float tempDy = dy;
        dx = outro.dx;
        dy = outro.dy;
        outro.dx = tempDx;
        outro.dy = tempDy;
    }
}

float Circulo::getX() const {
    return x;
}

float Circulo::getY() const {
    return y;
}

float Circulo::getRaio() const {
    return raio;
}
