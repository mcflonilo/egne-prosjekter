import java.util.Scanner;
import javax.swing.JOptionPane;
import java.util.ArrayList;
import java.util.Random;
import java.lang.reflect.Method;
import java.util.*;

public class tutorial {
    public static void main(String[] args){
        encapsulation();
        twoDArrayList();
      }

    public static void twoDArrayList(){

        ArrayList<ArrayList<String>> shoppinglist = new ArrayList<>();

        ArrayList<String> bakerylist = new ArrayList<>();
        bakerylist.add("pasta");
        bakerylist.add("garlic bread");
        bakerylist.add("donuts");

        ArrayList<String> producelist = new ArrayList<>();
        producelist.add("tomatoes");
        producelist.add("zuchini");
        producelist.add("peppers");

        ArrayList<String> drinkslist = new ArrayList<>();
        drinkslist.add("soda");
        drinkslist.add("coffee");

        shoppinglist.add(bakerylist);
        shoppinglist.add(producelist);
        shoppinglist.add(drinkslist);


        System.out.println(shoppinglist.get(0).get(0));
        



        
    }
    public static void executableJar(){
        
    }
    public static void compileRunPrompt(){
        
    }
    public static void packages(){
        
    }
    public static void multiThreading(){
        
    }
    public static void threads(){
        
    }
    public static void timerTask(){
        
    }
    public static void serialization(){
        
    }
    public static void generics(){
        
    }
    public static void twoDAnimation(){
        
    }
    public static void twoDGraphics(){
        
    }
    public static void keybindings(){
        
    }
    public static void dragNDrop(){
        
    }
    public static void mouselistener(){
        
    }
    public static void keylistener(){
        
    }
    public static void colorChooser(){
        
    }
    public static void selectFile(){
        
    }
    public static void menuBar(){
        
    }
    public static void progressBar(){
        
    }
    public static void slider(){
        
    }
    public static void combobox(){
        
    }
    public static void radioButtons(){
        
    }
    public static void checkBox(){
        
    }
    public static void textField(){
        
    }
    public static void JOptionPane(){
        
    }
    public static void openNewGUIWindow(){
        
    }
    public static void layeredpane(){
        
    }
    public static void gridlayout(){
        
    }
    public static void flowlayout(){
        
    }
    public static void borderlayout(){
        
    }
    public static void buttons(){
        
    }
    public static void panels(){
        
    }
    public static void labels(){
        
    }
    public static void GUI(){
        
    }
    public static void audio(){
        
    }
    public static void fileReader(){
        
    }
    public static void fileWriter(){
        
    }
    public static void fileClass(){
        
    }
    public static void exceptionhandling(){
        
    }
    public static void dynamicPolymorphism(){
        
    }
    public static void polymorphism(){
        
    }
    public static void interfaces(){
        
    }
    public static void copyobjects(){
        
    }
    public static void encapsulation(){
        
    }
    public static void accessmodifiers(){
        // access modifiers er public, protected og private
        //public sørger for at objekter og klasser utenfor en package kan se variabler/metoder/klasser fra andre pakker
        //protected gjør at kun subclasser av klasser kan få tilgang til variabler/metoder som er beskyttet
        //private gjør at kun selve klassen som har variablen/metoden har tilgang til den
    }
    public static void abstraction(){
        // abstraction er et keyword som brukes på klasser / metoder som man ikke vil at skal kunne brukes i programmet.
        // vehicle klassen gir mening å ha i programmet men gir ikke mening å instansiere som et objekt

        Car car = new Car("bmw");
        car.go();


    }
    public static void superkeyword(){
        //super er som this. men refererer til parent classen iastedenfor sin egen klasse
        Hero hero1 = new Hero("batman", 42, "money");
        Hero hero2 = new Hero("superman", 43, "everything");

        System.out.println(hero1.toString());
        System.out.println(hero2.toString());

        
    }
    public static void methodoverriding(){
        //method overriding gjør at en funksjon kan ha samme navn, men gjøre forskjellige ting for forskjellige klasser som slekter på hverandre
        Dog dog = new Dog();
        dog.speak();
        Animal animal = new Animal();
        animal.speak();
    }
    public static void inheritance(){
        //brukes hvis du har flere klasser som har fellestrekk men er fortsatt forskjellige nok så de ikke kan være samme klasse
        Car car = new Car("toyota");
        Bicycle bicycle = new Bicycle();
        bicycle.stop();
        car.drive();

    }
    public static void statickeyword(){
        //static er en variabel som deles mellom alle instanser av en klasse 
        //i dette tilfellet er numoffriends static så hcer gang vi legger til en venn incrementer numoffriends for alle Friend objekter
        // static variabler kan og burde bli accessa gjennom selve klassen og ikke gjennom instansierte objekter av klassen

        Friend friend1 = new Friend("sponegbob");
        Friend friend2 = new Friend("patrick");
        Friend friend3 = new Friend("squidward");
        Friend friend4 = new Friend("sandy");

        Friend.displayfriends();
        System.out.println(friend1);
        System.out.println(friend2);
        System.out.println(friend3);
        System.out.println(friend4);



    }
    public static void objectpassing(){
        
        Garage garage = new Garage();
        Car car = new Car("BMW");
        Car car2 = new Car("chevvy");

        garage.park(car);
        garage.park(car2);

    }
    public static void arrayofobjects(){
        
        Food[] refrigerator = new Food[3];

        Food food1 = new Food("pizza");
        Food food2 = new Food("hamburger");
        Food food3 = new Food("hotdog");

        Food[] refrigerator2 = {food1,food2,food3};

        refrigerator[0] = food1;
        refrigerator[1] = food2;
        refrigerator[2] = food3;

        System.out.println(refrigerator[2]);
        System.out.println(refrigerator2[0]);




    }
    public static void tostringmethod(){
        
        Car mycar = new Car("ford",2008,"fiesta","red",2000);
        
        

        System.out.println(mycar.toString());
        System.out.println(mycar);

    }
    public static void overloadconstructors(){
        
        pizza Pizza = new pizza("thicc crust", "tomato", "mozza", "pepperoni");
        System.out.println("here are the ingreadients of you pizza:");
        System.out.println(Pizza.bread);
        System.out.println(Pizza.sauce);
        System.out.println(Pizza.cheese);
        System.out.println(Pizza.topping);

        //to forskjellige constructors for hvis man vil lage en pizza uten topping

        pizza Pizza2 = new pizza("thicc crust", "tomato", "mozza");
        System.out.println(Pizza2);
        System.out.println(Pizza2.bread);
        System.out.println(Pizza2.sauce);
        System.out.println(Pizza2.cheese);



    }
    public static void varscope(){
        DiceRoller diceroller = new DiceRoller();
    }
    public static void constructors(){
        
        Car myCar = new Car("corvette", 33, "chevvy", "blue", 660.00);
        Car myCar2 = new Car("CUMMER", 66, "GAYMOBILE", "CUMCOLORED", 69);

        System.out.println(myCar.make);
        System.out.println(myCar2.make);
        myCar.drive();
        myCar2.drive();



    }
    public static void objectsOOP(){
        // se Car.java for å se hvordan man lager nye klasser
        Car myCar = new Car("corvette", 33, "chevvy", "blue", 660.00);
        System.out.println(myCar.model +" "+ myCar.make);
        myCar.drive();
        myCar.brake();
        Car myCar2 = new Car("corvette", 33, "chevvy", "blue", 660.00);
        System.out.println(myCar2.model +" "+ myCar2.make);



    }
    public static void finalkeyword(){
        //final brukes for å hindre at variabler kan endres.
        final double PI = 3.14159;
        System.err.println(PI);
    }
    public static void printf(){
        
        //%d betyr decimal/int
        //%b betyr boolean
        //%s betyr string
        //%f betyr double /float
        //%c betyr char
        char mychar = '@';
        int myint = 33;
        boolean myboolean = true;
        String mystring = "larsi";
        double mydouble = 1000;
        System.out.printf("%b", myboolean);
        //legg til tall før s for å bestemme karakterer som vises
        System.out.printf("Hello %10s", mystring);
        //legg til .2 for bestemme hvor mange decimaler som skal vises
        System.out.printf("you have this much money %.2f", mydouble);
        // legg til + for å vise om et tall er negativt eller positivt.
        // legg til , for å separere stor tall med komma.
        System.out.printf("Hello %+f", mydouble);




    }
    public static int overloadmethod(int a, int b){
        //man kan også overloade metoder ved å bare endre datatype, men virker også å endre parameterne
        return a+b;

    }
    public static int overloadmethod(int a, int b, int c,int d){
        
        return a+b+c+d;

    }
    public static int methods(int x, int y){
        
        System.out.println();

        return x+y;

    }
    public static void foreach(){

        String[] animals = {"cat","dog", "rat", "bird"};

        ArrayList<String> animals2 = new ArrayList<String>();

        animals2.add("cat");
        animals2.add("dog");
        animals2.add("rat");
        animals2.add("bird");

        for (String i : animals) {
            System.out.println(i);
        }
    }
    public static void arraylist(){
        //kan ikke bruke primitive typer. hvis du skal lagre primive, bruk wrapper classen
        ArrayList<String> food = new ArrayList<String>();
        food.add("pizza");
        food.add("hamburger");
        food.add("hotdog");

        food.set(0, "sushi");
        food.remove(2);
        food.clear();

        for(int i = 0 ; i<food.size() ; i++){
            System.out.println(food.get(i));
        }
    }
    public static void wrapperclasses(){
        //brukes for å endre primitive typer til referanse typer.
        //fordeler er at man får tilgang til mange nyttige teknikker som man ikke har til primitive typer.
        //ulempe er at primitive typer er raskere enn referanser så hvis man trenger at det skal gå fort burde man ikke bruke referanse

        Boolean a = true;
        Character b = '@';//husk å bruke enkeltfnutt og ikke dobbelfnutt når man bare skal ha en char
        Integer c = 123;
        Double d = 3.14;
        
        if( a == true && 
            b == '@' && 
            c == 123 && 
            d == 3.14)
            {System.out.println("this is true");}

    }
    public static void stringbasics(){

        String name = "larsi";
        String name2 = "         larsi";
        boolean equals = name.equals("Larsi");
        boolean equalsignorecase = name.equalsIgnoreCase("LaRsi");
        int length = name.length();
        char charat = name.charAt(0);
        int indexof = name.indexOf("i");
        boolean isempty = name.isEmpty();
        String touppercase = name.toUpperCase();
        String trim = name2.trim();
        String replace = name.replace("l", "b");
        System.out.println(
            equals+" "+
            equalsignorecase+" "+
            length+" "+ 
            charat+" "+ 
            indexof+" "+ 
            isempty+" "+
            touppercase+" "+
            trim+" "+ 
            replace);
    }
    public static void twoDarray(){
        String[][] cars2 = 
        {
            {"camaro", "corvette", "silverado"},
            {"mustang", "ranger", "f150"},
            {"ferrari", "lambo", "tesla"}
        };

        String[][] cars = new String[3][3];
        cars[0][0] = "camaro";
        cars[0][1] = "corvette";
        cars[0][2] = "silverado";
        
        cars[1][0] = "mustang";
        cars[1][1] = "ranger";
        cars[1][2] = "f-150";

        cars[2][0] = "ferrari";
        cars[2][1] = "lambo";
        cars[2][2] = "tesla";

        for (int i = 0; i < cars.length; i++) {
            System.out.println();
            for (int j = 0; j < cars[i].length; j++) {
                System.out.println(cars[i][j]);
            } 
        }
        for (int i = 0; i < cars2.length; i++) {
            System.out.println();
            for (int j = 0; j < cars2[i].length; j++) {
                System.out.println(cars2[i][j]);
            } 
        }
    }
    public static void arraybasics(){
        //kan ikke legge til eller fjerne antall elementer etter kompilering. hvis man skal gjøre dette bruk ArrayList
        String[] cars = {"ferrari", "bmw", "skoda"};
        String[] cars2 = new String[3];
        cars2[0] = "camaro";
        cars2[1] = "corvette";
        cars2[2] = "tesla";
        for (int i = 0; i < cars2.length; i++) {System.out.println(cars2[i]);}
        for (int i = 0; i < cars.length; i++) {System.out.println(cars[i]);}

    }
    public static void nestedloop(){
        Scanner scanner = new Scanner(System.in);
        int rows;
        int columns;
        String symbol = "";

        System.out.println("enter num of rows");
        rows = scanner.nextInt();
        System.out.println("enter num of columns");
        columns = scanner.nextInt();
        System.out.println("enter symbol to use");
        symbol = scanner.next();

        for(int i = 0; i <= rows; i++)
            {System.out.println();
            for (int j = 1; j < columns; j++) 
                {System.out.print(symbol);}}
            scanner.close();
    }
    public static void whileloop(){

        //kan bruke DO loop hvis man vil sjekke condition etter at den har kjørt koden en gang
        Scanner scanner = new Scanner(System.in);
        String name = "";

        while(name.isEmpty()){
            System.out.println("enter your name");
            name = scanner.nextLine();
        }

        System.out.println("hello "+name);
        scanner.close();

    }
    public static void random(){
        Random random = new Random();

        //tilfeldig tall mellom 1 og 6
        int x = random.nextInt(6)+1;
        System.out.println(x);

        double y = random.nextDouble();
        System.out.println(y);

        boolean z = random.nextBoolean();
        System.out.println(z);
    }
    public static void hypotenuse(){
        double x;
        double y;
        double z;

        Scanner scanner = new Scanner(System.in);

        System.out.println("enter side x");
        x = scanner.nextDouble();
        System.out.println("enter side y");
        y = scanner.nextDouble();

        z = Math.sqrt((x*x)+(y*y)); 
        System.out.println("the hypotenuse is :"+z);

        scanner.close();
    }
    public static void mathbasics(){
        double x = 3.5;
        double y = -10;
        double z = 15;

        double max = Math.max(x, y);
        double min = Math.min(x, y);
        double abs = Math.abs(y);
        double sqrt = Math.sqrt(z);
        double round = Math.round(x);
        double floor = Math.floor(x);

        System.out.println(max+" and "+min+ " and "+abs+" and "+sqrt+" and "+round+" and "+floor+" and ");
    }
    public static void guibasics(){
        String name = JOptionPane.showInputDialog("enter your name");
        JOptionPane.showMessageDialog(null, "hello "+name);

        int age = Integer.parseInt(JOptionPane.showInputDialog("enter your age"));
        JOptionPane.showMessageDialog(null, "You are "+age+ " years old");

        double height = Double.parseDouble(JOptionPane.showInputDialog("enter your height"));
        JOptionPane.showMessageDialog(null, "You are "+height+ " tall");
    }
    public static void scannerpractice(){
        Scanner scanner = new Scanner(System.in);
        System.out.println("what is your name");
        String name = scanner.nextLine();
        System.out.println("how old are you");
        int age = scanner.nextInt();
        System.out.println("what is your fav food");
        scanner.nextLine();
        String food = scanner.nextLine();
        System.out.println("hello "+name);
        System.out.println("you are "+ age+"old");
        System.out.println("your fav food is "+food);
        scanner.close();
    }
}