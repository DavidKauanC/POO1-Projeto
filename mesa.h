#ifndef MESA_H
#define MESA_H

class Mesa {
public:
    Mesa(float x, float y, float largura, float altura);

    float getX() const;
    float getY() const;
    float getLargura() const;
    float getAltura() const;

private:
    float x, y;
    float largura, altura;
};

#endif 
