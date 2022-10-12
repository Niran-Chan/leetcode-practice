class MyCircularQueue {
    int[] queue;
    int front = 0,back = -1,len = 0;
    
    public MyCircularQueue(int k) {
        queue = new int[k];
    }
    
    public boolean enQueue(int value) {
        if(len != queue.length)
        {
            back = (back + 1) % queue.length;
            queue[back] = value;
            len++;
            return true;
        }
        return false;
    }
    
    public boolean deQueue() {
        if(len != 0)
        {
            front = (front + 1) % queue.length;
            len--;
            return true;
        }
        return false;
    }
    
    public int Front() {
        if(len != 0) return queue[front];
        return -1;
    }
    
    public int Rear() {
        if(len != 0) return queue[back];
        return -1;
    }
    
    public boolean isEmpty() {
        return len == 0;
    }
    
    public boolean isFull() {
        return len == queue.length;
    }

    public static void main(String[] args) {
        int k = 3;
        MyCircularQueue myCircularQueue = new MyCircularQueue(k);
       
        myCircularQueue.enQueue(1); // return True
        myCircularQueue.enQueue(2); // return True
        myCircularQueue.enQueue(3); // return True
        myCircularQueue.enQueue(4); // return False
        System.out.println(myCircularQueue.Rear());     // return 3
        System.out.println(myCircularQueue.isFull());   // return True
        myCircularQueue.deQueue();  // return True
        myCircularQueue.enQueue(4); // return True
        System.out.println(myCircularQueue.Rear());     // return 4
    }



}


