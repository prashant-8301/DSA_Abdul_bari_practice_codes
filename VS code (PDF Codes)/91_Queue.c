struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct queue
{
    int rear;
    int front;
    int size;
    struct node **Q; /* here we are using double star because
    in Q we are storing pointer not the data or actual binary tree.
     here Q will store the pointer pointing the binary tree in heap,
      and **Q is nothing but the pointer pointing to the pointer of
      the actual binary tree. Add something if you further understand...
      hum ** q ke saamne tab hi put karte hai jab hume pata hai ki q kisi
      data ya value ko store nhi kar rha instead yeh kisi pointer ki address
      ko store karne wala isiliye hume ** pointer lagana pada...for ex->
      let say
      ----------
      int b;
      int *a;
      a = &b;
      int **c;
      c = &a;
      -------------
      here in this example you can clearly see that a ke saamne humne sirf
      ek star lagaya hai but c ke aage humne double star lagaya hai.
      iska reason simple hai...a is nothing but the address of int value b
      or we can also say that a is storing the address of int value b;
      but on the other hand we are putting double star in front of c
      because c is nothing but the address of the pointer pointing to
      the pointer of int value b..or we can say c is storing the address
      of pointer a not any int value...therefore when we store the
      address of any pointer then we put more than one star in front of
      that variable ...the number of star in front of variable depends
      on the number of  level or phase there in reaching the actual data
      value i.e int here in this case

    */
};
void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct node **)malloc(q->size*sizeof(struct node *));
}
void enqueue(struct queue *q, struct node *x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is full\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}
struct node * dequeue(struct queue *q)
{
    struct node *x = NULL;
    if (q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}
int isEmpty(struct queue q)
{
    return q.front == q.rear;
}