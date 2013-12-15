/*
 * Write a thread-safe queue.
 * http://stackoverflow.com/questions/1212623/multiple-writer-thread-safe-queue-in-c	

If you dont need a lock free queue, then you could just wrap up 
an existing queue with a lock.

Mutex myQueueLock;
Queue myQueue; 
void mtQueuePush(int value)
{
    lock(myQueueLock);
    queuePush(myQueue, value);
    unlock(myQueueLock);
}
int mtQueueNext()
{
    lock(myQueueLock);
    int value = queueFront(myQueue);
    queuePop(myQueue);
    unlock(myQueueLock);
    return value;
}

The only thing after that is to add some sort of handeling for 
mtQueueNext when the queue is empty.

EDIT: If you have a single reader, single writer lockless queue, 
you only need to have a lock around mtQueuePush, to prevent multiple 
simultaneous writers.

Theres a nubmer of single reader/writer lockless queues around, 
howver most of them are implemented as c++ template classes. 
However do a google search and if need be work out how to rewrite 
them in plain C.
 */
