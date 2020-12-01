// task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class ComputerGame
{
private:
    string name;
public:
    ComputerGame(const string _name) :name(_name) {}
    ComputerGame(const ComputerGame& obj) : name(obj.name) {}
    ~ComputerGame() {}

    string get_name() const
    {
        return name;
    }

    explicit virtual operator string()
    {
        return string(typeid(*this).name()) + ": (" + _print() + ")";
    }

protected:

    virtual string _print()
    {
        return "name of the game: " + name;
    }
};

class character : public ComputerGame
{
private:
    int x, y, HealthPoint, ManaPoint, MaxHealthPoint, MaxManaPoint;
public:
    character(const string _name, const int _maxHealth, const int _maxMana) : ComputerGame(_name), x(0), y(0), HealthPoint(_maxHealth), ManaPoint(_maxMana) {}
    character(const string _name, const int _maxHealth, const int _maxMana, const int _x, const int _y) : ComputerGame(_name), x(_x), y(_y), HealthPoint(_maxHealth), MaxHealthPoint(_maxHealth), ManaPoint(_maxMana), MaxManaPoint(_maxMana) {}
    character(const character& obj) : ComputerGame(obj), x(obj.x), y(obj.y), HealthPoint(obj.MaxHealthPoint), ManaPoint(obj.MaxManaPoint), MaxHealthPoint(obj.MaxHealthPoint), MaxManaPoint(obj.MaxManaPoint) {}

    int getx() const
    {
        return x;
    }

    int gety() const
    {
        return y;
    }

    int gethp() const
    {
        return HealthPoint;
    }

    int getmp() const
    {
        return ManaPoint;
    }

    virtual void move(int dx, int dy) = 0;
    virtual void take_damage(int damage) = 0;
    virtual void mana_use(int mana_cost) = 0;

protected:

    void _move(const int dx, const int dy)
    {
        x += dx;
        y += dy;
    }

    void _take_damage(const int Damage)
    {
        HealthPoint = max(0, HealthPoint - Damage);
    }

    void _mana_use(const int ManaCost)
    {
        ManaPoint = max(0, ManaPoint - ManaCost);
    }

    string _print() override
    {
        return ComputerGame::_print() + ", x: " + to_string(x) + ", y: " + to_string(y) +
            ", max hp: " + to_string(MaxHealthPoint) + ", max mp: " + to_string(MaxManaPoint) +
            ", hp: " + to_string(HealthPoint) + ", mp: " + to_string(ManaPoint);
    }

};
class items : public ComputerGame
{
private:
    int Damage;
public:

    items(const string _name, const int _damage) : ComputerGame(_name), Damage(_damage) {}
    items(const items& obj) : ComputerGame(obj), Damage(obj.Damage) {}
    ~items() {}

    int get_damage() const
    {
        return Damage;
    }

protected:
    string _print() override
    {
        return ComputerGame::_print() + ", damage: " + to_string(Damage);
    }
};
class spell_of_darkness : virtual public items
{
private:
    int DarkDamage;
public:
    spell_of_darkness(const string _name, const int _damage, const int _darkdamage) : items(_name, _damage), DarkDamage(_darkdamage) {}
    spell_of_darkness(const spell_of_darkness& obj) : items(obj), DarkDamage(obj.DarkDamage) {}
    ~spell_of_darkness() {}

    int get_darkdamage() const
    {
        return DarkDamage;
    }

protected:
    string _print() override
    {
        return items::_print() + ", dark damage: " + to_string(DarkDamage);
    }
};

class Gnome : virtual public character
{
private:
    string type;
public:
    Gnome(const string _name, const string _type, const int _maxhealth, const int _maxmana) : character(_name, _maxhealth, _maxmana), type(_type) {}
    Gnome(const string _name, const string _type, const int _maxhealth, const int _maxmana, const int _x, const int _y) : character(_name, _maxhealth, _maxmana, _x, _y), type(_type) {}
    Gnome(const Gnome& obj) : character(obj), type(obj.type) {}
    ~Gnome() {}

    void move(const int dx, const int dy) override
    {
        character::_move(dx, dy);
        cout << "Gnome " + get_name() + " goes to (" + to_string(getx()) + ", " + to_string(gety()) + ").\n";
    }

    void take_damage(const int damage) override
    {
        character::_take_damage(damage);
        cout << "Gnome " + get_name() + " hit by " + to_string(damage) + " damage.\n";
    }

    void mana_use(const int mana_cost) override
    {
        character::_mana_use(mana_cost);
        cout << "Gnome " + get_name() + " used " + to_string(mana_cost) + " manapoints.\n";
    }

protected:
    string _print() override
    {
        return character::_print() + ", speciality: " + type;
    }
};

class Warlock : virtual public character
{
private:
    string Warlockofwhat;
public:
    Warlock(const string _name, const int _maxhealth, const int _maxmana, const string _godofwhat) : character(_name, _maxhealth, _maxmana), Warlockofwhat(_godofwhat) {}
    Warlock(const string _name, const int _maxhealth, const int _maxmana, const int _x, const int _y) : character(_name, _maxhealth, _maxmana, _x, _y) {}
    Warlock(const string _name, const int _maxhealth, const int _maxmana, const int _x, const int _y, const string _godofwhat) : character(_name, _maxhealth, _maxmana, _x, _y), Warlockofwhat(_godofwhat) {}
    Warlock(const Warlock& obj) : character(obj), Warlockofwhat(obj.Warlockofwhat) {}
    ~Warlock() {}

    void move(const int dx, const int dy) override
    {
        character::_move(dx, dy);
        cout << "Warlock " + get_name() + " goes to (" + to_string(getx()) + ", " + to_string(gety()) + ").\n";
    }

    void take_damage(const int damage) override
    {
        character::_take_damage(damage);
        cout << "Warlock " + get_name() + " hit by " + to_string(damage) + " damage.\n";
    }

    void mana_use(const int mana_cost) override
    {
        character::_mana_use(mana_cost);
        cout << "Warlock " + get_name() + " used " + to_string(mana_cost) + " manapoints.\n";
    }

    void voice(const string str)
    {
        cout << get_name() + " shout \"" + str + "\"\n";
    }

protected:
    string _print() override
    {
        return character::_print() + ", kind of magic: " + Warlockofwhat;
    }
};

class Jedi : virtual public character
{
public:
    Jedi(const string _name, const int _maxhealth, const int _maxmana) : character(_name, _maxhealth, _maxmana) {}
    Jedi(const string _name, const int _maxhealth, const int _maxmana, const int _x, const int _y) : character(_name, _maxhealth, _maxmana, _x, _y) {}
    Jedi(const Jedi& obj) : character(obj) {}
    ~Jedi() {}

    void move(const int dx, const int dy) override
    {
        character::_move(dx, dy);
        cout << "Jedi " + get_name() + " moved to (" + to_string(getx()) + ", " + to_string(gety()) + ").\n";
    }

    void take_damage(const int damage) override
    {
        character::_take_damage(damage);
        cout << "Jedi " + get_name() + " hit by " + to_string(damage) + " damage.\n";
    }

    void mana_use(const int mana_cost) override
    {
        character::_mana_use(mana_cost);
        cout << "Jedi " + get_name() + " used " + to_string(mana_cost) + " manapoints.\n";
    }
};

int main()
{
    Jedi new_jedi("Cal", 5000, 420, -13, 15);
    cout << string(new_jedi) << endl; cout << endl;

    Warlock new_warlock("Damnok", 10000, 10000, -1, -1, "Dark");
    cout << string(new_warlock) << endl; cout << endl;

    Gnome new_gnome("Gimli", "Warrior", 1000, 250, 5, 3);
    cout << string(new_gnome) << endl;  cout << endl;

    new_jedi.move(12, -14);  cout << endl;
    new_warlock.take_damage(2500); cout << endl;
    cout << string(new_warlock) << endl;

    spell_of_darkness new_sod("Dark", 500, 500); cout << endl;
    cout << string(new_sod) << endl; cout << endl;
    
    new_warlock.voice("For the darkness"); cout << endl;
    new_warlock.mana_use(1500); cout << endl;
    new_jedi.take_damage(1000); cout << endl;

    cout << string(new_jedi) << endl;
}