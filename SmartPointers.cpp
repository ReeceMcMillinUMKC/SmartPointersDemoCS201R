#include <iostream>
#include <memory> // For smart pointers

using namespace std;

class Rectangle
{
private:
    
public:
    Rectangle(int __length, int __height, string __name);
    ~Rectangle();

    int length;
    int height;
    string name;
};

Rectangle::Rectangle(int __length, int __height, string __name)
{
    length = __length;
    height = __height;
    name = __name;
    cout << name << " Constructed!" << endl;
}

Rectangle::~Rectangle()
{
    cout << name << " Destructed!" << endl;
}

void CreateRectangles() {
    //smartointer is a smart pointer - it will call SmartRectangle's destructor as soon as it goes out of scope (end of this function)
    unique_ptr<Rectangle> smartpointer(new Rectangle(15, 20, "SmartRectangle"));
    //rawptr is a dumb idiot raw pointer - it doesn't know anything and we have to do everything manually or we lose control of our memory
    Rectangle *rawptr = new Rectangle(20, 25, "DumbIdiot");

    //They operate the exact same way!
    cout << smartpointer->height << endl;
    cout << rawptr->height << endl;

    //Here, we HAVE to manually delete rawptr's associated rectangle object.
    //Try commenting this out and see what it outputs!
    delete rawptr;

    //Unfortunately, the pointer still points to an location in memory, so we have to manually set the pointer to nullptr.
    //If we don't, we might start using another application's memory as our own, leading to undefined behavior.
            //This is a dangling pointer.
    rawptr = nullptr;
}


int main() {
    CreateRectangles();
}
