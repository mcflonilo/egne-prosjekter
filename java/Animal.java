public class Animal {
    static int n = 0;
    public String iamdog() {
        return "hello this is dog";
    }

    public static String pebis() {
        int a = n;
        n++;
        if (a==0){
            return "cum";

        } else if(a == 5) {
            return "sperm"+a;
        }
        else {
            return "spooge"+a;
        }
    }

    void speak(){
        System.out.println("the animal speaks");
    }
    
}
