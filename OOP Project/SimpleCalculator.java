import java.util.Scanner;

public class SimpleCalculator
{
	public static void main (String[] args)
	{
    Scanner data=new Scanner(System.in);
	double num1,num2,num;
	int sign;
		System.out.println("Enter 1 for Addition 2 for Subtraction\n 3 for multiplication 4 for division");
		sign=data.nextInt();
			System.out.println("Enter 1st Number:");
			num1=data.nextDouble();
			System.out.println("Enter 2nd Number:");
			num2=data.nextDouble();
			switch(sign){
				case 1:
					num=num1+num2;
					System.out.println("Answer="+num);
					break;
				case 2:
					num=num1-num2;
					System.out.println("Answer="+num);
					break;
				case 3:
					num=num1*num2;
					System.out.println("Answer="+num);
					break;
				case 4:
					num=num1/num2;
					System.out.println("Answer="+num);
					break;
				default:
					System.out.println("ERROR");
					break;	
			}
	}
}