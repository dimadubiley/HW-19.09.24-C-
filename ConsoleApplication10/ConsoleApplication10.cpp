#include <iostream>
#include <cstring>

using namespace std;

class Car 
{
    char* mod;
    char* count;
    int year;
    double price;

public:
    Car();

    Car(const char* mod, const char* count, int year, double price);

    ~Car();

    void Input();

    void Print() const;

    const char* getMod() const;
    void setMod(const char* mod);

    const char* getCount() const;
    void setCount(const char* count);

    int getYear() const;
    void setYear(int year);

    double getPrice() const;
    void setPrice(double price);
};

Car::Car()
{
    mod = nullptr;
    count = nullptr;
    year = 0;
    price = 0.0;
}

Car::Car(const char* modName, const char* countName, int yearValue, double priceValue)
{
    mod = new char[strlen(modName) + 1];
    strcpy_s(mod, strlen(modName) + 1, modName);

    count = new char[strlen(countName) + 1];
    strcpy_s(count, strlen(countName) + 1, countName);

    year = yearValue;
    price = priceValue;
}

Car::~Car()
{
    delete[] mod;
    delete[] count;
    cout << "Destruct\n";
}

void Car::Input()
{
    char buffer[100];

    cout << "Enter model: ";
    cin >> buffer;
    if (mod != nullptr)
    {
        delete[] mod;
    }
    mod = new char[strlen(buffer) + 1];
    strcpy_s(mod, strlen(buffer) + 1, buffer);

    cout << "Enter country: ";
    cin >> buffer;
    if (count != nullptr)
    {
        delete[] count;
    }
    count = new char[strlen(buffer) + 1];
    strcpy_s(count, strlen(buffer) + 1, buffer);

    cout << "Enter year: ";
    cin >> year;

    cout << "Enter price: ";
    cin >> price;
}

void Car::Print() const {
    cout << "Model: " << mod << endl;
    cout << "Country: " << count << endl;
    cout << "Year: " << year << endl;
    cout << "Price: $" << price << endl;
}

const char* Car::getMod() const
{
    return mod;
}

void Car::setMod(const char* modelName)
{
    if (mod != nullptr)
    {
        delete[] mod;
    }
    mod = new char[strlen(modelName) + 1];
    strcpy_s(mod, strlen(modelName) + 1, modelName);
}

const char* Car::getCount() const
{
    return count;
}

void Car::setCount(const char* countName)
{
    if (count != nullptr)
    {
        delete[] count;
    }
    count = new char[strlen(countName) + 1];
    strcpy_s(count, strlen(countName) + 1, countName);
}

void Car::setYear(int yearVal)
{
    year = yearVal;
}

int Car::getYear() const
{
    return year;
}

void Car::setPrice(double priceVal)
{
    price = priceVal;
}

double Car::getPrice() const
{
    return price;
}
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
int main()
{
    Car car1("BMW", "UA", 2018, 30000);
    car1.Print();

    cout << "\nEnter new car details:" << endl;
    car1.Input();
    car1.Print();

}
