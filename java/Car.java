public class Car extends Vehicle{
    String make;
    int year;
    String model;
    String color;
    double price;

    Car(String make,int year, String model, String color, double price){
        this.make = make;
        this.year = year;
        this.model = model;
        this.color = color;
        this.price = price;
    }
    Car(String make,int year, String model){
        this.make = make;
        this.year = year;
        this.model = model;
    }
    Car(String make){
        this.make = make;
    }

    //override av tostring metoden. denne metoden gir egentlig addressen til objektet i minnet men etter override gir den 
    //akkurat den stringen jeg vil
    public String toString() {
        return make + model + color+ price;
    }

    
    

    void drive(){
        System.out.println("you drive the car"+ this.make);
    }
    void brake(){
        System.out.println("you step on the brakes"+ this.color);
    }
    @Override
    void go(){
        System.out.println("the driver is driving the car");
    }
}

