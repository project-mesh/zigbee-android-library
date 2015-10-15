public class TestJNIObject {
	static{
		System.load("/home/hhe/Projects/Capstone/zigbee-android-library/Tests/JNIObject/libTestJNIObject.so");
	}
	//Instance variables
	private int number = 88;
	private String message = "Hello from Java";

	//Declare a native method that modfies instance variables
	private native void modifyInstanceVariable();


	//Test Driver
	public static void main(String args[]) {
		TestJNIObject test = new TestJNIObject();
		test.modifyInstanceVariable();
		System.out.println("In Java, int is " + test.number);
		System.out.println("In Java, String is " + test.message);

	}
}