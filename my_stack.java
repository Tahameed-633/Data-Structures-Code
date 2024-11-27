package pac1;
public class my_stack
{
	static int capacity=4;
	static int top=-1;
	static int[] stack=new int[capacity];
	public static void resize()
	{
		int[] new_stack=new int[2*capacity];
		for(int i=0;i<=top;i++)
		{
			new_stack[i]=stack[i];
		}
		stack=new_stack;
		capacity=capacity*2;
		System.out.println("Size of the stack increased into: "+capacity);
	}
	public static void push(int x)
	{
		if(top==capacity-1)
		{
			resize();
			
		}
		top=top+1;
		stack[top]=x;
		System.out.println("Item added to the stack successfully: "+x);
	}
	public static int peek()
	{
		if(top>=0)
		{
			return stack[top];
		}
		System.out.println("Exception in peek! Stack is empty");
		return -1;
	}
	public static int pop()
	{
		if(top>=0)
		{
			int value=stack[top];
			top=top-1;
			return value;
		}
		System.out.println("Exception in pop! Stack is empty");
		return -1;
	}
	public static void main(String[] args)
	{
		System.out.println("Implementig stack in java");
		peek();
		pop();
		push(10);
		push(20);
		push(30);
		push(40);
		push(50);
		push(60);
		push(70);
		push(80);
		System.out.println("Item peeked successfully: "+peek());
		push(90);
		System.out.println("Item pooped successfully: "+pop());
	}
}

