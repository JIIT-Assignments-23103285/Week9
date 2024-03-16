#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class House;

class Room {
private:
    House* myHse_p;
    char* name_p;

public:
    Room(const char* name, House* house) : myHse_p(house) {
        name_p = new char[strlen(name) + 1];
        strcpy(name_p, name);
    }

    ~Room() {
        delete[] name_p;
    }

    void disp() const {
        cout << "Room: " << name_p << endl;
    }
};

class House {
private:
    vector<Room*> roomList_p;
    char* name_p;

public:
    House(const char* name) {
        name_p = new char[strlen(name) + 1];
        strcpy(name_p, name);
    }

    ~House() {
        for (Room* room : roomList_p) {
            delete room;
        }
        roomList_p.clear();
        delete[] name_p;
    }

    void addRoom(const char* roomName) {
        Room* newRoom = new Room(roomName, this);
        roomList_p.push_back(newRoom);
    }

    void disp() const {
        cout << "House: " << name_p << endl;
        for (Room* room : roomList_p) {
            room->disp();
        }
    }
};

int main() {
    House* myHouse = new House("My House");

    myHouse->addRoom("Living Room");
    myHouse->addRoom("Bedroom");
    myHouse->addRoom("Kitchen");

    myHouse->disp();

    delete myHouse;

    return 0;
}
