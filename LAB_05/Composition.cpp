/*COMPOSITION SAMPLE*/
#include <iostream>
using namespace std;
class Engine {
public:
Engine() { cout << "Engine Created\n"; }
void start() { cout << "Engine Started\n"; }
~Engine() { cout << "Engine Destroyed\n"; }
};
class Car {
public:
Engine engine; // Composition: Car owns Engine
Car() { cout << "Car Created\n"; }
void start() { engine.start(); }
~Car() { cout << "Car Destroyed\n"; }
};
int main() {
{
Car myCar;
myCar.start();
} // myCar goes out of scope, so Car and Engine are destroyed.
cout << "Car object no longer exists!\n";
return 0;
}
