//
// Created by Root on 30.03.2018.
//


#include "Entity/Player.h"

Player::Player(int x, int y, std::shared_ptr<sf::Event> & cEvent, Layers cLayer)
        : Entity(x, y, true, cLayer), event(cEvent)
{
    rect.setPosition(getPosition());
    rect.setSize(sf::Vector2f(32, 32));
    playerControler = std::unique_ptr<PlayerController>(new PlayerController(std::shared_ptr<Player>(this), 0.0002));

}

void Player::draw(std::shared_ptr<sf::RenderWindow> window)
{
    rect.setPosition(getPosition());
    window->draw(rect);
}

void Player::update(const float dt)
{
    playerControler->control(dt);
}

void Player::input()
{

}

Player::~Player()
{

}
