import java.util.*;

class Main {
    public static void main(String[] args) {
	Scanner lee = new Scanner(System.in);
	String s;

	while(lee.hasNext()) {
	    s = lee.next();

	    if(s.matches("da+dd?(i|y)")) {
		System.out.println("She called me!!!");
	    } else {
		System.out.println("Cooing");
	    }
	}
    }
}