#include "unitTest.h"
#include "rand_functions.h"

#include "gamemap.h"
#include "qdebug.h"

unitTest::unitTest()
{
    // Sets a random seed for randomization to have different outputs.
    randomize();

    // Declaring mainMap and mainPlayer.
    GameMap mainMap = GameMap(5, 5);
    GameObject* mainPlayer = mainMap.create<Player>(0, 0, true);
    // Declaring goblin and goblin boss so we can make random movements
    GameObject* goblin1 = mainMap.create<Goblin>(1, 1);
    GameObject* goblin2 = mainMap.create<GoblinBoss>(1,2);
    // Declaring a goblin boss for testing AI
    GameObject* goblin3 = mainMap.create<Goblin>(1,3);
    // Declaring a spike, tombstone, healthPotion and wall for unit testing
    mainMap.create<Spike>(1, 0);
    mainMap.create<Tombstone>(3,0);
    mainMap.create<HealthPotion>(2,2);
    mainMap.create<Wall>(4, 0);

    // Initial game state for unit testing
    qDebug().noquote() << mainMap.print();
    qDebug() << "HEALTH = " << mainPlayer->health();
    qDebug() << "ARMOR = " << mainPlayer->armor();
    qDebug() << "--------------------------------------------------";

    // Unit test for player landing on spike
    mainPlayer->move(1, 0);
    qDebug().noquote() << mainMap.print();
    qDebug() << "HEALTH = " << mainPlayer->health();
    qDebug() << "ARMOR = " << mainPlayer->armor();
    qDebug() << "--------------------------------------------------";


    // Unit test for player landing on tombstone
    mainPlayer->move(2, 0);
    qDebug().noquote() << mainMap.print();
    qDebug() << "HEALTH = " << mainPlayer->health();
    qDebug() << "ARMOR = " << mainPlayer->armor();
    qDebug() << "--------------------------------------------------";

    // Unit test for player running into a wall
    mainPlayer->move(1, 0);
    qDebug().noquote() << mainMap.print();
    qDebug() << "HEALTH = " << mainPlayer->health();
    qDebug() << "ARMOR = " << mainPlayer->armor();
    qDebug() << "--------------------------------------------------";


    // Unit test for player fighting a goblin
    mainPlayer->move(-1, 1);
    qDebug().noquote() << mainMap.print();
    qDebug() << "HEALTH = " << mainPlayer->health();
    qDebug() << "ARMOR = " << mainPlayer->armor();
    qDebug() << "--------------------------------------------------";

    mainPlayer->move(-1,0);
    qDebug().noquote() << mainMap.print();
    qDebug() << "HEALTH = " << mainPlayer->health();
    qDebug() << "ARMOR = " << mainPlayer->armor();
    qDebug() << "--------------------------------------------------";

    mainPlayer->move(-1,0);
    qDebug().noquote() << mainMap.print();
    qDebug() << "HEALTH = " << mainPlayer->health();
    qDebug() << "ARMOR = " << mainPlayer->armor();
    qDebug() << "--------------------------------------------------";


    // Unit test for player fighting a goblin boss
    mainPlayer->move(0, 1);
    qDebug().noquote() << mainMap.print();
    qDebug() << "HEALTH = " << mainPlayer->health();
    qDebug() << "ARMOR = " << mainPlayer->armor();
    qDebug() << "--------------------------------------------------";

    mainPlayer->move(0, 1);
    qDebug().noquote() << mainMap.print();
    qDebug() << "HEALTH = " << mainPlayer->health();
    qDebug() << "ARMOR = " << mainPlayer->armor();
    qDebug() << "--------------------------------------------------";

    mainPlayer->move(0, 1);

    qDebug().noquote() << mainMap.print();
    qDebug() << "HEALTH = " << mainPlayer->health();
    qDebug() << "ARMOR = " << mainPlayer->armor();
    qDebug() << "--------------------------------------------------";

    // Unit test for health potion
    mainPlayer->move(1,0);
    qDebug().noquote() << mainMap.print();
    qDebug() << "HEALTH = " << mainPlayer->health();
    qDebug() << "ARMOR = " << mainPlayer->armor();
    qDebug() << "--------------------------------------------------";


    // Unit test: Loop game until player is dead moving the game objects with randomized input
    // ****TODO IF WE SETUP GAME SIMILAR TO THIS****:
        //Make turns that dont result in a change skipped and re roll movement of objects other than mainPlayer
    while(goblin3->health() != 0.0)
    {
        if(mainPlayer->health() == 0.0){
            qDebug() << "DEAD BRO";
            break;
        }

        goblin3->move(irandom(5), irandom(5));
        qDebug().noquote() << mainMap.print();
        qDebug() << "HEALTH = " << mainPlayer->health();
        qDebug() << "ARMOR = " << mainPlayer->armor();
        qDebug() << "--------------------------------------------------";
        qDebug() << endl;

        mainPlayer->move(irandom(5), irandom(5));
        qDebug().noquote() << mainMap.print();
        qDebug() << "HEALTH = " << mainPlayer->health();
        qDebug() << "ARMOR = " << mainPlayer->armor();
        qDebug() << "--------------------------------------------------";
        qDebug() << endl;
    }
}
