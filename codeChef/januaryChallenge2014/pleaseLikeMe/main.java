import java.util.*;
import java.math.BigInteger;

class main {
    public static void main(String[] args) {
	Scanner lee = new Scanner(System.in);
	int t = lee.nextInt();

	while(t-- != 0) {
	    long l = lee.nextLong();
	    long d = lee.nextLong();
	    long s = lee.nextLong();
	    long c = lee.nextLong();

	    s *= Math.pow(c+1, d-1);

	    if(s >= l)
		System.out.println("ALIVE AND KICKING");
	    else
	     	System.out.println("DEAD AND ROTTING");
	}
    }
}