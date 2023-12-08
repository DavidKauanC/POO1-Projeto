// main.cpp
#include <SDL2/SDL.h>
#include <iostream>
#include "circle.h"
#include "mesa.h"

class Circulo; 


// Função para desenhar um círculo preenchido usando pontos
void desenharCirculoPreenchido(SDL_Renderer* renderer, int centroX, int centroY, int raio) {
    for (int x = -raio; x <= raio; ++x) {
        for (int y = -raio; y <= raio; ++y) {
            if (x * x + y * y <= raio * raio) {
                SDL_RenderDrawPoint(renderer, centroX + x, centroY + y);
            }
        }
    }
}
void renderizar(SDL_Renderer* renderer, const Circulo& bola1, const Circulo& bola2, const Mesa& mesa) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderClear(renderer);

    // Desenhar a mesa
    SDL_Rect retanguloMesa = {static_cast<int>(mesa.getX()), static_cast<int>(mesa.getY()), static_cast<int>(mesa.getLargura()), static_cast<int>(mesa.getAltura())};
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &retanguloMesa);

    // Desenhar os círculos usando pontos para simular um círculo preenchido
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    desenharCirculoPreenchido(renderer, static_cast<int>(bola1.getX()), static_cast<int>(bola1.getY()), static_cast<int>(bola1.getRaio()));

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    desenharCirculoPreenchido(renderer, static_cast<int>(bola2.getX()), static_cast<int>(bola2.getY()), static_cast<int>(bola2.getRaio()));

    SDL_RenderPresent(renderer);
}

int main(int argc, char* args[]) {
    SDL_Window* janela = nullptr;
    SDL_Renderer* renderizador = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL não pôde ser inicializado! Erro SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    janela = SDL_CreateWindow("Simulador POO1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (janela == nullptr) {
        std::cerr << "A janela não pôde ser criada! Erro SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderizador == nullptr) {
        std::cerr << "O renderizador não pôde ser criado! Erro SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    Circulo bola1(100, 300, 40, 9, -3);
    Circulo bola2(400, 300, 40, 5, 2);
    Mesa mesa(100, 100, 600, 400);

    bool sair = false;
    SDL_Event evento;

    while (!sair) {
        while (SDL_PollEvent(&evento) != 0) {
            if (evento.type == SDL_QUIT) {
                sair = true;
            }
        }

        bola1.atualizar();
        bola2.atualizar();

        bola1.verificarColisaoBorda(mesa);
        bola2.verificarColisaoBorda(mesa);

        bola1.verificarColisaoCirculo(bola2);

        renderizar(renderizador, bola1, bola2, mesa);

        SDL_Delay(1000 / 60);
    }

    SDL_DestroyRenderer(renderizador);
    SDL_DestroyWindow(janela);
    SDL_Quit();

    return 0;
}
