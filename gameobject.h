#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QString>
#include <QPixmap>

// Forward declaration of GameMap.
class GameMap;

// Parent class for all GameObjects, stored in GameMap.
// This class is virtual and should not be intantiated.
class GameObject
{
public:
    GameObject();
    virtual ~GameObject();

    // Main GameObject methods.
    bool move(const int xoff, const int yoff);

    // Virtual GameObject methods.
    // Any new method for a child object MUST be declared as
    // a virtual method here, and defined as empty in gameobject.cpp.
    virtual void destroy();
    virtual void update();
    virtual void collide(GameObject* other);
    virtual void takeDamage(double amount);

    // Getters/Setters.
    QString name() const;
    QString type() const;
    char symbol() const;
    QPixmap graphic() const;
    unsigned int x() const;
    unsigned int y() const;
    GameMap* map() const;

    // Virtual Getters/Setters.
    virtual double health() const;
    virtual double armor() const;
    virtual void healthBuff(int x);

protected:
    // Basic Variable Members.
    QString _name;
    QString _type;
    char _symbol;
    QPixmap _graphic;
    unsigned int _x;
    unsigned int _y;
    GameMap* _map;
    QPixmap * _pixmap;

    bool _persistent;

    // Is friend of GameMap.
    friend class GameMap;
};

// Class declaration for spike trap.
class Spike : public GameObject
{
public:
    Spike();
    virtual void collide(GameObject* other);

protected:
    double _damage;
};

// Class declaration for wall
class Wall : public GameObject
{
public:
    Wall();
    virtual void collide(GameObject *other);
};

// Class declaration for tombstone
class Tombstone : public GameObject
{
public:
    Tombstone();
    virtual void collide(GameObject *other);
};

// Class declaration for health potion
class HealthPotion : public GameObject
{
public:
    HealthPotion();
    virtual void collide(GameObject *other);
};

// Parent class for all Entities. This class should not be intantiated.
// This includes any GameObject which has health and should take damage.
class Entity : public GameObject
{
public:
    Entity();
    double health() const;
    double armor() const;
    void healthBuff(int x);

    virtual void takeDamage(double amount);

protected:
    double _health;
    double _armor;
};

// Parent class for all Enemies. The class should not be instantiated.
// This includes Entities which engage in combat with the player.
class Enemy : public Entity
{
public:
    Enemy();

    // Main event methods.
    virtual void collide(GameObject* other);
    virtual void destroy();

protected:
    double _damage;
};

// Goblin class declaration.
class Goblin : public Enemy //Number One
{
public:
    Goblin();
};

// Class declaration for Goblin Boss
class GoblinBoss : public Enemy
{
public:
    GoblinBoss();
};

// Class declaration for Player.
class Player : public Entity
{
public:
    Player();

    // Main event methods.
    void collide(GameObject* other);

protected:
    double _damage;
};

#endif // GAMEOBJECT_H
