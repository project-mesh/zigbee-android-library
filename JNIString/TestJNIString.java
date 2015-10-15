public class TestJNIString {
	static {
		System.load("/home/hhe/Projects/Capstone/zigbee-android-library/Tests/JNIString/libTestJNIString.so");
	}

	private native String sayHello(String msg);

	public static void main(String args[]){
		String result = new TestJNIString().sayHello("Hello from Java");
		System.out.println("In Java, the returned string is: " + result);
	}

}