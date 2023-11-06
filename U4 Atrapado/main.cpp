#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

int main() {

    sf::RenderWindow App(sf::VideoMode(800, 600), "Ejercicio 4 Atrapado");

    sf::Texture textura_cuadrado;
    textura_cuadrado.loadFromFile("cuad_yellow.png");

    sf::Texture textura_circulo;
    textura_circulo.loadFromFile("rcircleg.png");

    float tamaño_figura = 100.0f; 
    sf::Sprite figura_cuadrado(textura_cuadrado);
    figura_cuadrado.setScale(tamaño_figura / textura_cuadrado.getSize().x, tamaño_figura / textura_cuadrado.getSize().y);
    figura_cuadrado.setPosition(sf::Vector2f(400, 300));

    sf::Sprite figura_circulo(textura_circulo);
    figura_circulo.setScale(tamaño_figura / textura_circulo.getSize().x, tamaño_figura / textura_circulo.getSize().y);
    figura_circulo.setPosition(sf::Vector2f(400, 300));

    sf::Sprite& figura = figura_cuadrado;

    while (App.isOpen()) {
        sf::Event evt;
        while (App.pollEvent(evt)) {
            switch (evt.type) {
            case sf::Event::Closed:
                App.close();
                break;
            case sf::Event::KeyPressed:
                if (evt.key.code == sf::Keyboard::Space) {

                    if (&figura == &figura_cuadrado) {
                        figura = figura_circulo;
                    }
                    else {
                        figura = figura_cuadrado;
                    }
                }
                break;
            }
        }

        float speed = 0.2f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            figura.move(-speed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            figura.move(speed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            figura.move(0, -speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            figura.move(0, speed);
        }

        if (figura.getPosition().x < 0) {
            figura.setPosition(0, figura.getPosition().y);
        }
        if (figura.getPosition().x > App.getSize().x - figura.getGlobalBounds().width) {
            figura.setPosition(App.getSize().x - figura.getGlobalBounds().width, figura.getPosition().y);
        }
        if (figura.getPosition().y < 0) {
            figura.setPosition(figura.getPosition().x, 0);
        }
        if (figura.getPosition().y > App.getSize().y - figura.getGlobalBounds().height) {
            figura.setPosition(figura.getPosition().x, App.getSize().y - figura.getGlobalBounds().height);
        }

        App.clear();
        App.draw(figura);
        App.display();
    }

    return 0;
}
