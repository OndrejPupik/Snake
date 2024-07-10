#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include <unistd.h>    
#include "mov.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(840, 840), "SFML works!");
    std::deque<sf::VertexArray> Q;
    sf::VertexArray quad(sf::Quads, 4);
    int prevdir = 3, prevdir2 = 3;
    bool vpoho = true;
    bool snedl = false;
    sf::CircleShape jabko = jablko();
    // define it as a rectangle, located at (10, 10) and with size 100x100
    quad[0].position = sf::Vector2f(400.f, 400.f);
    quad[1].position = sf::Vector2f(440.f, 400.f);
    quad[2].position = sf::Vector2f(440.f, 440.f);
    quad[3].position = sf::Vector2f(400.f, 440.f);
    Q.push_back(quad);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // check the type of the event...
            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                // key pressed
                case sf::Event::KeyPressed:
                    if(event.key.code == 22 && prevdir != 18){
                        prevdir2 = 22;

                        break;
                    }
                    else if(event.key.code == 3 && prevdir != 0){
                        prevdir2 = 3;

                        break;
                    }
                    else if(event.key.code == 18 && prevdir != 22){
                        prevdir2 = 18;

                        break;
                    }
                    else if(event.key.code == 0 && prevdir != 3){
                        prevdir2 = 0;

                        break;
                    }
                    break; // w == 22, d == 3, s == 18, a == 0

                // we don't process other types of events
                default:
                    break;
            }
        }
        move(prevdir2, Q, vpoho, snedl);
        prevdir = prevdir2;
        if(Q.back()[0].position.x == jabko.getPosition().x && Q.back()[0].position.y == jabko.getPosition().y){
            snedl = true;
            jabko = jablko();
        }
        window.clear();
        //window.draw(shape);
        window.draw(jabko);
        for(auto& it : Q){
            window.draw(it);
        }
        window.display();
        if(!vpoho){
            window.close();
        }
        usleep(100000);
    }
	
    return 0; 

}
