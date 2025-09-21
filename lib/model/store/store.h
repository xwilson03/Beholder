#ifndef STORE_H
#define STORE_H

#include <QObject>
#include <mutex>


struct State {

    std::string name;
    uint8_t     level;
    std::string characterClass;
    std::string race;


    struct AbilityScores {
        uint8_t strength;
        uint8_t dexterity;
        uint8_t constitution;
        uint8_t intelligence;
        uint8_t wisdom;
        uint8_t charisma;
    };

    AbilityScores abilityScores;

    struct CombatStats {
        uint16_t HP;
        uint16_t maxHP;
        uint16_t tempHP;
        uint8_t  AC;
        uint8_t  initiative;
        uint16_t speed;
    };

    CombatStats combatStats;

    struct Feature {
        std::string name;
        std::string category;
        bool passive;
        uint8_t charges;
        uint8_t maxCharges;
    };

    std::vector<Feature> features;

    struct Item {
        std::string name;
        std::string category;
        bool equipped;
    };

    std::vector<Item> items;
};

class Store : QObject {
    Q_OBJECT

public:

    class Accessor {
        friend class Store;

    public:
        const State* operator->() const;

    private:
        Accessor(std::mutex &aLock, const State &aState);

        const State& mState;
        const std::lock_guard<std::mutex> mLock;

    };

    Store(QObject* parent = nullptr);
    Accessor getState();

private:
    State mState;
    std::mutex mLock;

};


#endif // STORE_H
