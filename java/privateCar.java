public class privateCar {
    
    private String make;
    private String model;
    private int year;

    privateCar(String make, String model, int year){
        this.make = make;
        this.model = model;
        this.year = year;
    }
    void hoink(){
        System.out.println(make+model+year);
    }


}
