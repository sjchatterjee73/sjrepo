import java.util.*;
class NumbersInWord{
	static String [] unit = {"","One", "Two", "Three", "Four",
			"Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
			"Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
			"Eighteen", "Nineteen" };

	static String [] ten = {
			"", 		// 0
			"",			// 1
			"Twenty", 	// 2
			"Thirty", 	// 3
			"Forty", 	// 4
			"Fifty", 	// 5
			"Sixty", 	// 6
			"Seventy",	// 7
			"Eighty", 	// 8
			"Ninety" 	// 9
	};	
	static String convert(int num){
		if(num <0)
			return "Minus"+ num;

		if(num<20)
			return unit[num];

		if(num <100)
			return ten[num/10] + (num%10!=0?" ":"")+convert(num%10);
		if(num<1000)
			return unit[num/100] + " Hundred "+(num%100!=0?" ":"")+convert(num%100);
		return unit[num/1000] + " Thousand "+ (num%1000!=0?" ":"")+convert(num%1000);
	}
	public static void main(String args[]){
		int num = new Scanner(System.in).nextInt();
		System.out.println(convert(num));
	}
}