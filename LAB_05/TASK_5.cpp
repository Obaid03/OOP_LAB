/*Keeping in mind our previous car example, write a class that represents a car, and useaggregation and
composition to combine different components like engine, wheels, headlights and steering to create the
car object.

Hint: create the individual classes firstbeforeperforming the composition. Remember
thatfor aggregation, you will need pointers! You’ll be needing constructors and setters to
set these values in case of aggregation. Same hint applies to other questions.*/

#include <iostream>
using namespace std;
class Engine
{
public:
    Engine()
    {
        cout << "Engine is created" << endl;
    }
    ~Engine()
    {
        cout << "Engine is detroyed" << endl;
    }
};
class Wheels
{
public:
    Wheels()
    {
        cout << "Wheels is created" << endl;
    }
    ~Wheels()
    {
        cout << "Wheels is detroyed" << endl;
    }
};
class Headlights
{
public:
    Headlights()
    {
        cout << "Headlights is created" << endl;
    }
    ~Headlights()
    {
        cout << "Headlights is detroyed" << endl;
    }
};
class Steering
{
public:
    Steering()
    {
        cout << "Steering is created" << endl;
    }
    ~Steering()
    {
        cout << "Steering is detroyed" << endl;
    }
};
class Car
{
    Engine *engine;
    Wheels wheels;
    Steering steering;
    Headlights *headlights;

public:
    Car() : engine(nullptr), headlights(nullptr) {}
    Car(Engine *e, Headlights *h, Steering st, Wheels w) : engine(e), headlights(h), steering(st), wheels(w)
    {
        cout << "Car created" << endl;
    }
    void installEngine(Engine *e)
    {
        engine = e;
        cout << "Engine is installed" << endl;
    }
    void installHeadlights(Headlights *h)
    {
        headlights = h;
        cout << "Headlights has been installed" << endl;
    }
    ~Car()
    {
        cout << "Car has been destroyed." << endl;
    }
};
int main()
{
    Engine e;
    Headlights h;
    Wheels w;
    Steering s;
    Car myCar(&e, &h, s, w);
    myCar.installEngine(&e);
    myCar.installHeadlights(&h);
    return 0;
}
