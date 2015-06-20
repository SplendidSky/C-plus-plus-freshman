#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct City {
    double x, y;          // position of the city
    std::string name;  // name of city
};

class Vehicle {
public:
    explicit Vehicle(double _speed) : speed(_speed) {}
    virtual void doTravel(const City& src, const City& dest) = 0;
    double getSpeed() const {
        return speed;
    }
    virtual ~Vehicle() {}
private:
    double speed;
};

class BicycleStrategy : public Vehicle {
public:
    explicit BicycleStrategy(double _speed) : Vehicle(_speed) {}
    void doTravel(const City& src, const City& dest) {
        double dis = fabs(src.x - dest.x) + fabs(src.y - dest.y);
        double time = dis / getSpeed();
        cout << "It takes " << time << " hours to Travel from "
            << src.name << " to " << dest.name << " by Bicycle." << endl;
    }
};

class TrainStrategy : public Vehicle {
public:
    explicit TrainStrategy(double _speed) : Vehicle(_speed) {}
    void doTravel(const City& src, const City& dest) {
        double dis = sqrt((src.x - dest.x) * (src.x - dest.x)
            + (src.y - dest.y) * (src.y - dest.y));
        double time = dis / getSpeed();
        cout << "It takes " << time << " hours to Travel from " <<
            src.name << " to " << dest.name << " by Train." << endl;
    }
};

class AirplaneStrategy : public Vehicle {
public:
    explicit AirplaneStrategy(double _speed) : Vehicle(_speed) {}
    void doTravel(const City& src, const City& dest) {
        double dis = fabs(src.x - dest.x) > fabs(src.y - dest.y) ?
            abs(src.x - dest.x) : abs(src.y - dest.y);
        double time = dis / getSpeed();
        cout << "It takes " << time << " hours to Travel from " <<
            src.name << " to " << dest.name << " by Airplane." << endl;
    }
};
