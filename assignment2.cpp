#include <iostream>
using namespace std;


class Hero {
protected:
    string name, type;
    int health, experience;
    double power;

public:
    Hero(string n, string t, int h, double p, int exp) {
        name = n;
        type = t;
        health = h;
        power = p;
        experience = exp;
    }

    void showGameMessage() {
        cout << "\n=== Welcome to Fantasy Battle Arena ===\n";
        cout << "Each hero attacks and defends differently.\n";
    }

    virtual double attack() = 0;
    virtual double defend() = 0;


    virtual void display() {
        cout << "\nHero Name: " << name;
        cout << "\nHero Type: " << type;
        cout << "\nHealth: " << health;
        cout << "\nPower: " << power;
        cout << "\nExperience: " << experience << endl;
    }
};


class Warrior : public Hero {
private:
    string weapon;
    int armor;
    double rage;

public:
    Warrior(string n, int h, double p, int exp,
            string w, int a, double r)
        : Hero(n, "Warrior", h, p, exp) {
        weapon = w;
        armor = a;
        rage = r;
    }

    double attack() override {
        return power * rage + experience * 0.5;
    }

    double defend() override {
        return armor * 1.5 + health * 0.2;
    }

    void display() override {
        Hero::display();
        cout << "Weapon: " << weapon;
        cout << "\nArmor: " << armor;
        cout << "\nRage Level: " << rage << endl;
    }
};


class Mage : public Hero {
private:
    string spell;
    int mana;
    double multiplier;

public:
    Mage(string n, int h, double p, int exp,
         string s, int m, double mul)
        : Hero(n, "Mage", h, p, exp) {
        spell = s;
        mana = m;
        multiplier = mul;
    }

    double attack() override {
        return power * multiplier + mana * 0.3;
    }

    double defend() override {
        return mana * 0.5 + health * 0.1;
    }

    void display() override {
        Hero::display();
        cout << "Spell: " << spell;
        cout << "\nMana: " << mana;
        cout << "\nMagic Multiplier: " << multiplier << endl;
    }
};


class Archer : public Hero {
private:
    string bow;
    int arrows;
    double accuracy;

public:
    Archer(string n, int h, double p, int exp,
           string b, int arr, double acc)
        : Hero(n, "Archer", h, p, exp) {
        bow = b;
        arrows = arr;
        accuracy = acc;
    }

    double attack() override {
        return power * accuracy + arrows * 0.2;
    }

    double defend() override {
        return accuracy * 50 + health * 0.1;
    }

    void display() override {
        Hero::display();
        cout << "Bow Type: " << bow;
        cout << "\nArrows: " << arrows;
        cout << "\nAccuracy: " << accuracy << endl;
    }
};


int main() {

    Warrior w("Thor", 150, 80, 40, "Axe", 70, 1.5);
    Mage m("Merlin", 100, 90, 50, "Fireball", 120, 2.0);
    Archer a("Legolas", 110, 75, 45, "Longbow", 60, 1.8);

    w.showGameMessage();

    double atkW, atkM, atkA;

    cout << "\n--- Warrior ---";
    w.display();
    atkW = w.attack();
    cout << "Attack: " << atkW;
    cout << "\nDefense: " << w.defend() << endl;

    cout << "\n--- Mage ---";
    m.display();
    atkM = m.attack();
    cout << "Attack: " << atkM;
    cout << "\nDefense: " << m.defend() << endl;

    cout << "\n--- Archer ---";
    a.display();
    atkA = a.attack();
    cout << "Attack: " << atkA;
    cout << "\nDefense: " << a.defend() << endl;

   
    cout << "\n=== Summary ===\n";

    if (atkW > atkM && atkW > atkA)
        cout << "Warrior has the highest attack.\n";
    else if (atkM > atkW && atkM > atkA)
        cout << "Mage has the highest attack.\n";
    else
        cout << "Archer has the highest attack.\n";

    return 0;
}
