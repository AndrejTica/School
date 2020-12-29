public class Test_FIFO {

	public static void main(String[] args) {

		if (!testEmpty()) {
			System.out.println("ERROR: testEmpty");
			return;
		}

		if (!testFull()) {
			System.out.println("ERROR: testFull");
			return;
		}

		if (!testEnqueueAndEmpty()) {
			System.out.println("ERROR: testEnqueueAndEmpty");
			return;
		}

		if (!testEnqueueDequeueAndEmpty()) {
			System.out.println("ERROR: testEnqueueDequeueAndEmpty");
			return;
		}

		if (!testFullException()) {
			System.out.println("ERROR: testFullException");
			return;
		}

		if (!testEmptyException()) {
			System.out.println("ERROR: testEmptyException");
			return;
		}

		System.out.println("======== ALL TESTS PASSED =======");
	}

	public static boolean testEmpty() {
		FIFO fifo = new FIFO(5); // 5 Elemente haben Platz
		if (fifo.isEmpty())
			return true;
		else
			return false;
	}

	public static boolean testFull() {
		try {
			FIFO fifo = new FIFO(5); // 5 Elemente haben Platz
			fifo.enqueue(1);
			fifo.enqueue(2);
			fifo.enqueue(3);
			fifo.enqueue(4);
			fifo.enqueue(5);

			if (fifo.isFull())
				return true;
			else
				return false;
				
		} catch (FullException e) {
			return false;
		}
	}

	public static boolean testEnqueueAndEmpty() {
		try {
			FIFO fifo = new FIFO(5); // 5 Elemente haben Platz
			fifo.enqueue(1);

			if (fifo.isEmpty())
				return false;
			else
				return true;

		} catch (FullException f) {
			return false;
		}
	}

	public static boolean testEnqueueDequeueAndEmpty() {
		try {
			FIFO fifo = new FIFO(5); // 5 Elemente haben Platz
			fifo.enqueue(1);
			int val = fifo.dequeue();
			if (val != 1)
				return false;

			if (fifo.isEmpty())
				return true;
			else
				return false;

		} catch (FullException f) {
			return false;
		} catch (EmptyException f) {
			return false;
		}
	}

	public static boolean testFullException() {
		try {
			FIFO fifo = new FIFO(5); // 5 Elemente haben Platz
			fifo.enqueue(1);
			fifo.enqueue(2);
			fifo.enqueue(3);
			fifo.enqueue(4);
			fifo.enqueue(5);
			fifo.enqueue(6);

			return false;
		} catch (FullException f) {
			return true;
		}
	}

	public static boolean testEmptyException() {

		try {
			FIFO fifo = new FIFO(5); // 5 Elemente haben Platz
			int ret = fifo.dequeue();

			return false;

		} catch (EmptyException f) {
			return true;
		}
	}
}
