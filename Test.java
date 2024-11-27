package pac3;

public class Test {

	public static void main(String[] args) {
		System.out.println("Implementing dynamic queue in java");
		my_queue queue=new my_queue();
		queue.dequeue();
		queue.enqueue(10);
		queue.enqueue(20);
		queue.enqueue(30);
		queue.enqueue(40);
		queue.enqueue(50);
		queue.print_queue();
		queue.enqueue(60);
		queue.enqueue(70);
		queue.print_queue();
		System.out.println("deleted item: "+queue.dequeue());
		queue.print_queue();

	}

}
