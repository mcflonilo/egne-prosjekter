public abstract class Vehicle {
    double speed;

    abstract void go();
        
    void stop(){
        System.out.println("this vehicle is stopped");
    }
}
