#include<iostream>
#include<string>
using namespace std;

class Character {
protected:
    string characterID;
    string name;
    int level;
    int healthPoints;
public:
    virtual void attack() = 0;
    virtual void defend() = 0;
    virtual void displayStats() = 0;
};

class Warrior : public Character {
    int armorStrength;
    int meleeDamage;
public:
    Warrior(string id, string n, int l, int hp, int armor, int damage) {
        characterID = id; name = n; level = l; healthPoints = hp; armorStrength = armor; meleeDamage = damage;
    }
    void attack() override {
        cout << name << " attacks with melee damage: " << meleeDamage << endl;
    }
    void defend() override {
        cout << name << " defends with armor strength: " << armorStrength << endl;
    }
    void displayStats() override {
        cout << "Warrior: " << name << " | Level: " << level << " | HP: " << healthPoints << endl;
    }
};

class Mage : public Character {
    int manaPoints;
    int spellPower;
public:
    Mage(string id, string n, int l, int hp, int mana, int spell) {
        characterID = id; name = n; level = l; healthPoints = hp; manaPoints = mana; spellPower = spell;
    }
    void attack() override {
        cout << name << " casts a spell with power: " << spellPower << endl;
    }
    void defend() override {
        cout << name << " uses magical barrier!" << endl;
    }
    void displayStats() override {
        cout << "Mage: " << name << " | Level: " << level << " | HP: " << healthPoints << endl;
    }
};

class Archer : public Character {
    int arrowCount;
    int rangedAccuracy;
public:
    Archer(string id, string n, int l, int hp, int arrows, int accuracy) {
        characterID = id; name = n; level = l; healthPoints = hp; arrowCount = arrows; rangedAccuracy = accuracy;
    }
    void attack() override {
        cout << name << " shoots arrows with accuracy: " << rangedAccuracy << endl;
    }
    void defend() override {
        cout << name << " dodges the attack!" << endl;
    }
    void displayStats() override {
        cout << "Archer: " << name << " | Level: " << level << " | HP: " << healthPoints << endl;
    }
};

class Rogue : public Character {
    int stealthLevel;
    int agility;
public:
    Rogue(string id, string n, int l, int hp, int stealth, int agi) {
        characterID = id; name = n; level = l; healthPoints = hp; stealthLevel = stealth; agility = agi;
    }
    void attack() override {
        cout << name << " strikes from the shadows!" << endl;
    }
    void defend() override {
        cout << name << " evades with agility: " << agility << endl;
    }
    void displayStats() override {
        cout << "Rogue: " << name << " | Level: " << level << " | HP: " << healthPoints << endl;
    }
};

int main() {
    Warrior w1("W101", "Thor", 5, 200, 50, 70);
    w1.displayStats();
    w1.attack();
    w1.defend();

    Mage m1("M201", "Loki", 4, 150, 100, 80);
    m1.displayStats();
    m1.attack();
    m1.defend();

    Archer a1("A301", "Artemis", 3, 160, 20, 85);
    a1.displayStats();
    a1.attack();
    a1.defend();

    Rogue r1("R401", "Shadow", 6, 180, 90, 95);
    r1.displayStats();
    r1.attack();
    r1.defend();

    return 0;
}
