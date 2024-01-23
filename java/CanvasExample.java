// importing awt class  
import java.awt.*;  
import java.lang.Math;

// class to construct a frame and containing main method    
public class CanvasExample    
{    
  // class constructor   
  public CanvasExample(int x, int y)    
  {    
    
    // creating a frame  
    Frame f = new Frame("Canvas Example");   
    // adding canvas to frame   
    f.add(new MyCanvas(x,y));    
  
    // setting layout, size and visibility of frame  
    f.setLayout(null);    
    f.setSize(x, y);    
    f.setVisible(true);    
  }    
  
  // main method  
  public static void main(String args[])    
  {    
    int width = 2560*2;
    int height = 1440;
    new CanvasExample(width, height);   
  }    
}    

// class which inherits the Canvas class  
// to create Canvas  
class MyCanvas extends Canvas    
{    
    public class obj{
        int stepstate = 1;
        int stepstotake = 1;
        int stepstaken = 1;
        int stepsize = 25;
        int turnrate = 1;
    }
    int width;
    int height;
    // class constructor  
    public MyCanvas(int a,int b) {    
        setBackground (Color.BLACK);    
        setSize(a, b);
        width = a;
        height = b;    
     }    
    //checkstate finds the direction the next number should take. either up down left or right
    public obj checkstate(obj stats){
      if( stats.stepstaken>=stats.stepstotake&&stats.turnrate == 2){
          if(stats.stepstate==4){
            stats.stepstate = 1;
            stats.stepstotake++;
              stats.stepstaken = 0;
              stats.turnrate=1;
              
          }
          else{
            stats.stepstate++;
            stats.stepstotake++;
              stats.stepstaken = 0;
              stats.turnrate=1;
          }
      }
      else if(stats.stepstaken>=stats.stepstotake&&stats.turnrate==1){
          if(stats.stepstate==4){
            stats.stepstate = 1;
            stats.stepstaken = 0;
            stats.turnrate=2;
          }
          else{
            stats.stepstate++;
            stats.stepstaken = 0;
            stats.turnrate=2;
          }
      }
      stats.stepstaken++;
      return stats;
    }
    //isprime() method for finding prime numbers returns true false
    public boolean isPrime(double x){
        for(double i = 2, s = Math.sqrt(x); i<=s; i++)
            if(x%i == 0) {return false;}
            String s = String.valueOf(x);
            System.out.println(s);
            return true;
        }
    // paint() method to draw inside the canvas  
    public void paint(Graphics g)    
    {    
    obj turnstats = new obj();
    int x = width/2;
    int y = height/2;
    int stepsize = 10;
    // adding specifications  
    int red = 0;
    int green = 0;
    int blue = 0;
    for (double i = 1 ; i <6500000; i++){
        if (isPrime(i)){
            g.setColor(new Color(0, 0, 255));
            g.fillOval(x, y, 5, 5);
          }

          g.setColor(new Color(red, green, blue));
        switch (turnstats.stepstate){
            case 1:{
                turnstats = checkstate(turnstats);
                g.drawLine(x, y, x+stepsize, y);
                x+=stepsize;
                break;
            }
            case 2:{
                turnstats = checkstate(turnstats);
                g.drawLine(x, y, x, y-stepsize);
                y-=stepsize;
                break;
            }        
            case 3:{
                turnstats = checkstate(turnstats);
                g.drawLine(x, y, x-stepsize, y);
                x-=stepsize;
                break;
            }        
            case 4:{
                turnstats = checkstate(turnstats);
                g.drawLine(x, y, x, y+stepsize);
                y+=stepsize;
                break;
            }}
            
            }}}     