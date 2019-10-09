
public class Scope {
 public static void main(String[] args) {
	int age = 44;
	int adult = 18;
	
	String teacherName = "Rafael";
	
	if(age>= adult) {
		System.out.println("Is Adult");
		boolean isCefetTeacher = true;
		System.out.println("Name: " + teacherName + ", age: " + age + "\nCEFET Teacher: " + isCefetTeacher);
	}
	
	//System.out.println("Name: " + teacherName + ", age: " + age + "\n CEFET Teacher: " + isCefetTeacher);
	// Out of scope
}
}
