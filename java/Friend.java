public class Friend {
    static int numberoffriends = 0;
    String name;
    
    Friend(String name){
        this.name = name;
        numberoffriends++;
    }
    static void displayfriends(){
        System.out.println("you have "+ numberoffriends+ " friends");
    }
}
