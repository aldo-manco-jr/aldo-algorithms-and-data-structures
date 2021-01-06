import java.util.NoSuchElementException;

/**
 * Created by unieuro on 10/16/2019.
 */
public class ArrayQueue {
    Employee[] queue;
    int front;
    int back;

    public ArrayQueue(int capacity) {
        this.queue = new Employee[capacity];
    }

    public int size(){
        if (front<=back){
            return back-front;
        }else {
            return (queue.length-front)+back;
        }
    }

    public void enqueue(Employee employee){
        if (size()==queue.length-1){
            int numItems = size();

            Employee[] tmpArray = new Employee[2*queue.length];
            System.arraycopy(queue, front, tmpArray, 0, queue.length-front);
            System.arraycopy(queue, 0, tmpArray, queue.length-front, back); // 3 4 5b 1f 2
            queue = tmpArray;

            front=0;
            back=numItems;
        }
        queue[back] = employee;
        if (back < queue.length-1) {
            back++;
        }else {
            back=0;
        }
    }

    public Employee dequeue(){
        if (size()==0) throw new NoSuchElementException();

        Employee removedItem = queue[front];
        queue[front] = null;
        front++;

        if (size()==0) {
            front=0;
            back=0;
        }else if (front==queue.length){
            front=0;
        }
        return removedItem;
    }

    public Employee peek(){
        if (size()==0) throw new NoSuchElementException();
        return queue[front];
    }

    public void printQueue(){
        if (size()==0) System.out.println("Queue is Empty");

        if (front<=back){
            for (int i = front; i < back; i++) {
                System.out.println(queue[i]);
            }
        }else {
            for (int i = front; i < queue.length; i++) {
                System.out.println(queue[i]);
            }
            for (int i = 0; i < back; i++) {
                System.out.println(queue[i]);
            }
        }
    }
}