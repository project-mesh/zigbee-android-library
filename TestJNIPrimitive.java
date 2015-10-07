public class TestJNIPrimitive {
	static {
		System.load("/home/hhe/Projects/Capstone/zigbee-android-library/libTestJNIPrimitive.so");
	}

	// Declare a native method average() that receives two ints and returns a double containing the average
	private native double average(int n1, int n2);

	// Test Driver

	public static void main(String args[]){
		System.out.println("In Java, the average is " + new TestJNIPrimitive().average(4, 2));
	}

}