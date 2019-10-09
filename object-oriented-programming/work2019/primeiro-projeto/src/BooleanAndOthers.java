public class BooleanAndOthers {
	public static void main(String[] args) {
		
		System.out.println("Testing boolean");
		
		int age = 18;
		boolean studentIsAdult = (age >= 18);
		boolean TeacherLikesHim = true;
		
		if (studentIsAdult || TeacherLikesHim)
			System.out.println("Go to barbecue");
		else
			System.out.println("Sorry");
		
		System.out.println("-----------------------------");
		System.out.println("Conversions");
		
		double pi = 3.14;
		int number = 5;
		double numberTwo = number; // promotion casting
		
		double numberThree = 5;
		int numberFour = (int) numberThree;
		
		System.out.println("Number 2:" + numberTwo);
		System.out.println("Number 3:" + numberThree);
		
	}
}
