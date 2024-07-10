#include "mov.h"
void move(int dir, std::deque<sf::VertexArray>& Q, bool& vpoho, bool& snedl){
    sf::VertexArray now = Q.back();
    if(dir == 22){
        for(int i = 0; i < 4; i++){
            now[i].position.y -= 40;
        }
    }
    else if(dir == 3){
        for(int i = 0; i < 4; i++){
            now[i].position.x += 40;
        }
    }
    else if(dir == 18){
        for(int i = 0; i < 4; i++){
            now[i].position.y += 40;
        }
    }
    else if(dir == 0){
        for(int i = 0; i < 4; i++){
            now[i].position.x -= 40;
        }
    }
    else{
        return;
    }
    for(auto& it : Q){
        if(it[0].position.x == now[0].position.x && it[0].position.y == now[0].position.y){
            vpoho = false;
            return;
        }
    }
    for(int i = 0; i < 4; i++){
        now[i].color = sf::Color::Green;
    }
    if(now[2].position.x > 840 || now[0].position.x < 0 || now[0].position.y < 0 || now[2].position.y > 840){
        vpoho = false;
        return;
    }
    Q.push_back(now);
    if(!snedl){
        Q.pop_front();
    }
    snedl = false;
}
sf::CircleShape jablko(){
    time_t current_time = time(NULL);
    srand(current_time);
    int x = rand() % 21;
    current_time = time(NULL);
    srand(current_time);
    int y = rand() % 21;
    sf::CircleShape jabko(20);
    jabko.setPosition(40.f * x, 40.f * y);
    jabko.setFillColor(sf::Color::Red);
    return jabko;
}