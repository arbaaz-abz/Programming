//Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
import java.io.*;
import java.util.*;
class RemoveKDig
{

public static String removeKdigits(String num, int k) {
    if(num.length()==k)
        return "0";

    StringBuilder sb = new StringBuilder(num);
    for(int j=0; j<k; j++){
        int i=0;
        while(i<sb.length()-1 && sb.charAt(i) <= sb.charAt(i+1) ){
            i++;
        }
        sb.delete(i, i+1);
    }

    if(sb.length()==0){
        return "0";
    }

    System.out.println(sb.toString());
	 return sb.toString();
}

public static void main(String[] args)
{
        String num = "";
        int k=0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of num");
        num = sc.next();
        System.out.println("Enter the value of k");
        k = sc.nextInt();
        removeKdigits(num,k);

}


}