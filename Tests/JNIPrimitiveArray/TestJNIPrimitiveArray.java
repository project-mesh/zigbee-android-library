public class TestJNIPrimitiveArray {
	
	static {
		System.load("/home/hhe/Projects/Capstone/zigbee-android-library/Tests/JNIPrimitiveArray/libTestJNIPrimitiveArray.so");
	}

	//Returns a double[2] array with [0] as sum and [1] as average
	private native double[] sumAndAverage(int[] numbers);

	public static void main(String args[]) {

		int[] numbers = {22, 33, 44, 123};
		double[] results = new TestJNIPrimitiveArray().sumAndAverage(numbers);
		System.out.println("In Java, the sum is " + results[0]);
		System.out.println("In Java, the average is " + results[1]);

	}

}