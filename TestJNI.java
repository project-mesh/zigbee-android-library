public class TestJNI{

	static{
		System.loadLibrary("TestJNI");
	}	

	private native void helloWorld();

	public static void main(String[] args){
		new TestJNI().helloWorld();
	}

}