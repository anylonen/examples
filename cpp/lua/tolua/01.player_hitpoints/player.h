#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int _health;

public:
    Player();
    ~Player();
    void setHealth(int health);
    int getHealth();
};

#endif // PLAYER_H
