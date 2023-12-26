#include <iostream>
using namespace std;
#include <vector>

class Vehicle
{
private:
    string make;
    string model;
    int year;
    float price;

public:
//default constructor
    Vehicle(){}

    //setters
    void setMake(const string brand)
    {
        make = brand;
    }

    void setModel(const string modelNo)
    {
        model = modelNo;
    }

    void setYear(const int yr)
    {
        model = yr;
    }

    void setPrice(const float value)
    {
        price = value;
    }

    //getters
    string getMake() const
    {
        return make;
    }

    string getModel() const
    {
        return model;
    }

    int getYear() const
    {
        return year;
    }

    float getprice() const
    {
        return price;
    }

    void displayDetails() const
    {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Price: $" << price << endl;
    }

    //vrtuaal function
    virtual float calculateTax() const
    {
        return 0.1*price;
    }

    // destructor
    virtual ~Vehicle(){}
};

class Car : public Vehicle
{
private:
    int numDoors;

public:
    void setNumDoors(int doors){
        numDoors = doors;
    }

    int getNumDoors(){
        return numDoors;
    }

    float calculateTax() const override{
        return 0.1*getprice()+0.02*numDoors;
    }
};

class Truck : public Vehicle
{
    private:
        float payload;
        float towingCapacity;

    public:
        void setPayLoad(float load){
            payload = load;
        }

        void setTowingCapacity(float capacity){
            towingCapacity = capacity;
        }

        float getPayLoad() {
            return payload;
        }

        float getTowingCapacity() {
            return towingCapacity;
        }

        float calculateTax() const override{
            return 0.1*getprice()+0.05*payload+0.01*towingCapacity;
        }
};

class FleetManager{
    private:
        vector<Vehicle* > fleet;
        const size_t capacity;

    public:
        FleetManager():capacity(100){
        fleet.reserve(capacity);
        }

        void addVehicle(Vehicle* vehicle){
            if(fleet.size()<capacity){
                fleet.push_back(vehicle);
                cout<<"Vehicle added to the fleet."<<endl;
            }else{
                cout<<"Fleet has reached max limit."<<endl;
            }
        }

        void removeVehicle(int index){
            if(index>=0 && index<fleet.size()){
                delete fleet[index];
                fleet.erase(fleet.begin()+index);
                cout<<"Vehicle removed from the fleet."<<endl;
            }else{
                cout<<"Invalid index. no vehicle removed."<<endl;
            }
        }

        void searchVehicle(int index) const{

            if(index>=0 && index<fleet.size()){
            fleet[index]->displayDetails();
            cout<<"Tax payable: $"<<fleet[index]->calculateTax();
            }
            else{
                cout<<"Invalid index. No vehicle found."<<endl;
            }
        }

        void viewList() const{
            cout<<"Vehicle list: \n";
            for(int i=0; i<fleet.size(); i++){
                cout<<"Index: "<<i<<"\n";
                fleet[i]->displayDetails();
            }
        }

        ~FleetManager(){
            for(auto vehicle:fleet){
                delete vehicle;
            }
        }
};

int main(){
    FleetManager fleetManager;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Vehicle\n";
        std::cout << "2. Remove Vehicle\n";
        std::cout << "3. Search for Vehicle\n";
        std::cout << "4. View List\n";
        std::cout<< "5. Exit"<<endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice){
            case 1:{
                 //Add Vehicle
                int vehicleType;
                std::cout << "Select vehicle type (1 for Car, 2 for Truck): ";
                std::cin >> vehicleType;
                Vehicle* newVehicle = nullptr; //ptr object initialised to nullptr
                //This ptr will be dynamically allocated an object Vehicle as required
                if(vehicleType ==1){
                    newVehicle = new Car;
                }
                else if (vehicleType == 2){
                    newVehicle = new Truck;
                }else{
                    cout<<"Invalid choice. Return to the main menu."<<endl;
                    continue;
                }

                //vehicle details
                string make, model;
                int year;
                float price;

                cout<<"Enter make: ";
                cin>>make;
                newVehicle->setMake(make);

                cout << "Enter model: ";
                cin >> model;
                newVehicle->setModel(model);

                cout << "Enter year: ";
                cin >> year;
                newVehicle->setYear(year);

                cout << "Enter price: $";
                cin >> price;
                newVehicle->setPrice(price);

                //additional attributes
                if(vehicleType == 1){
                    int numDoors;
                    cout<<"Enter number of doors: ";
                    cin>>numDoors;
                    //dynamic casting of vehicle ptr to car ptr
                    dynamic_cast<Car*>(newVehicle)->setNumDoors(numDoors);
                }else if(vehicleType == 2){
                    float payLoad, towingCapacity;
                    cout<<"Enter payLoad: lb";
                    cin>>payLoad;
                    //dynamic casting newVehicle ptr to Truck ptr
                    dynamic_cast<Truck*>(newVehicle)->setPayLoad(payLoad);

                    cout<<"Enter towingCapacity: lb";
                    cin >>towingCapacity;
                    dynamic_cast<Truck*>(newVehicle)->setTowingCapacity(towingCapacity);
                }

                fleetManager.addVehicle(newVehicle);
                break;
            }

            case 2:{
                //Remove vehicle
                int index;
                cout<<"Enter the index of the vehicle to remove: ";
                cin>>index;
                fleetManager.removeVehicle(index);
                break;
            }
            case 3:{
                //display details
                int index;
                cout<<"Enter index of the vehicle: ";
                cin>>index;
                fleetManager.searchVehicle(index);
                break;
            }
           case 4: {
                fleetManager.viewList();
                break;
           }
           case 5:{
            //exit
           }
        }
    }
    return 0;
}