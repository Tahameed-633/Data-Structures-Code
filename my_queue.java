package pac3;

public class my_queue {
	private int[] queue;
	private int rear=-1,front=0,total_item=0;
	private int capacity=5;
	public my_queue()
	{
		queue=new int[capacity];
	}
	public boolean isEmpty()
	{
		if(total_item==0)
		{
			return true;
		}
		return false;
	}
	public void resize()
	{
		int[] new_queue=new int[2*capacity];
		for(int i=0;i<total_item;i++)
		{
			new_queue[i]=queue[(front+i)%capacity];
		}
		queue=new_queue;
		front=0;
		rear=total_item-1;
		capacity=2*capacity;
		System.out.println("Capacity is now increased into: "+capacity);
	
	}
	public void enqueue(int item)
	{
		if(total_item==capacity)
		{
			resize();
		}
		rear=(rear+1)%capacity;
		queue[rear]=item;
		total_item++;
		System.out.println("Item pushed successfully."+item);
	}
	public void print_queue()
	{
		System.out.println("Queue: ");
		for(int i=0;i<capacity;i++)
		{
			System.out.print(" "+queue[i]);
		}
		System.out.println();
	}
	public int dequeue()
	{
		if(isEmpty())
		{
			System.out.println("Noitem to delete. The queue is empty");
			return -1;
		}
		int front_item=queue[front];
		queue[front]=-1;
		front=(front+1)%capacity;
		total_item--;
		return front_item;
	}
	
	

}

