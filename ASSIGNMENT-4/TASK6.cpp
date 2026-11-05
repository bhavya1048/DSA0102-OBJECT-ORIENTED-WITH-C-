#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string regNo;
    double dailyRate;
    bool rented;

public:
    Vehicle(string r, double d)
        : regNo(r), dailyRate(d), rented(false) {}

    virtual double rentalCharge(int days) const = 0;

    void rent() {
        if (!rented) {
            rented = true;
            cout << regNo << " rented successfully" << endl;
        }
        else {
            cout << regNo << " is already rented" << endl;
        }
    }

    void returnVehicle(int days, int lateDays) {
        if (rented) {
            double amount = rentalCharge(days) + lateDays * 100;

            cout << regNo << " return amount: "
                 << amount << endl;

            rented = false;
        }
        else {
            cout << regNo << " was not rented" << endl;
        }
    }

    virtual void display() const {
        cout << "Registration: " << regNo
             << ", Daily Rate: " << dailyRate << endl;
    }

    virtual ~Vehicle() {}
};

class Bicycle : public Vehicle {
public:
    Bicycle(string r, double d) : Vehicle(r, d) {}

    double rentalCharge(int days) const override {
        return dailyRate * days + 100;
    }
};

class TwoWheeler : public Vehicle {
    double fuelLevel;
    string serviceDate;

public:
    TwoWheeler(string r, double d, double f, string s)
        : Vehicle(r, d), fuelLevel(f), serviceDate(s) {}

    double rentalCharge(int days) const override {
        return dailyRate * days + fuelLevel * 50 + 100;
    }
};

class Car : public Vehicle {
    int seats;

public:
    Car(string r, double d, int s)
        : Vehicle(r, d), seats(s) {}

    double rentalCharge(int days) const override {
        return dailyRate * days + seats * 100 + 100;
    }
};

class ElectricCar : public Vehicle {
    double batteryKWh;

public:
    ElectricCar(string r, double d, double b)
        : Vehicle(r, d), batteryKWh(b) {}

    double rentalCharge(int days) const override {
        return dailyRate * days + batteryKWh * 8 + 100;
    }
};

class ElectricBus : public Vehicle {
    double batteryKWh;

public:
    ElectricBus(string r, double d, double b)
        : Vehicle(r, d), batteryKWh(b) {}

    double rentalCharge(int days) const override {
        return dailyRate * days + batteryKWh * 8 + 100;
    }
};

int main() {
    Bicycle b("BIKE101", 100);
    TwoWheeler t("BIKE102", 300, 1, "2026-12-01");
    Car c("CAR101", 1500, 2);
    ElectricCar e("EV101", 2000, 50);
    ElectricBus bus("BUS101", 2500, 100);

    Vehicle* fleet[] = {&b, &t, &c, &e, &bus};

    cout << "VEHICLE RENTAL SYSTEM" << endl;

    for (Vehicle* v : fleet) {
        v->display();
        v->rent();
    }

    cout << "\nVEHICLE RETURN DETAILS\n";

    for (Vehicle* v : fleet) {
        v->returnVehicle(2, 1);
    }

    return 0;
}