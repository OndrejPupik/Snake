#pragma once
#include <SFML/Graphics.hpp>
#include <queue>
#include <iostream>
void move(int prevdir, std::deque<sf::VertexArray>& Q, bool& vpoho, bool& snedl);
sf::CircleShape jablko();
