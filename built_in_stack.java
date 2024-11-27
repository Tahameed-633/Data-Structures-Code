package pac2;
import java.util.Stack;

public class built_in_stack {

	public static void main(String[] args) {
		Stack<String> my_stack=new Stack();
		my_stack.push("Bangladesh");
		my_stack.push("Dhaka");
		System.out.println("POP: "+my_stack.pop());
		System.out.println("Peek: "+my_stack.peek());
		System.out.println(my_stack.size());

	}

}
