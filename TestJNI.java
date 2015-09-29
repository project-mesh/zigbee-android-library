public class TestJNI{

	static{
		//System.loadLibrary("TestJNI");
		System.load("/Users/aki/7th Semester/ece4440/zigbee-android-libary/TestJNI.jnilib");
	}	

	private native void helloWorld();

	public static void main(String[] args){
		new TestJNI().helloWorld();
	}

}