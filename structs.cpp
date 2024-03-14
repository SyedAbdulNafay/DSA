#include <iostream>
using namespace std;

struct Phone
{
    string name;
    int storageSpace;
    string color;
    float price;

};

struct Person
{
    string name;
    int age;
    Phone phone;
};


void phoneInfo(Phone p){
    cout << "Name: " << p.name << ", Color: " << p.color << ", Price: " << p.price << ", Storage Space: " << p.storageSpace << "GB" << endl;
}

void personInfo(Person p){
    cout << "Name: " << p.name << ", Age: " << p.age << endl;
    phoneInfo(p.phone);
}

int main()
{
    Phone p1;
    p1.name = "iPhone 12";
    p1.color = "black";
    p1.price = 999.99;
    p1.storageSpace = 64;

    Phone p2;
    p2.name = "Qmobile A20";
    p2.color = "white";
    p2.price = 1999.99;
    p2.storageSpace = 128;

    phoneInfo(p1);

    Person p;
    p.name = "Nafay";
    p.age = 19;
    p.phone = p1;

    personInfo(p);
    return 0;
}