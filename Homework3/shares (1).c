#include "stock.h"
#include "structure.h"

char SYM[MAX_SIZE][MAX_SIZE];

//function to initialize stack array and queue array
void init(){
    st = (stack*)malloc(MAX_SIZE*sizeof(stack)); //memory allocation

    q = (queue*)malloc(MAX_SIZE*sizeof(queue)); //memory allocation
    int i;
    //initialize all members of stack and queue
    for(i=0;i<MAX_SIZE;i++){
        strcpy(SYM[i],"");
        st[i].top=-1;
        st[i].head=NULL;
        

        q[i].front=NULL;
        q[i].rear=NULL;
    }
}

//Searches for the particular symbol in the SYM array and returns the respective index
int symbolsearch(char *symbol){
    int i;
    for(i=0;i<MAX_SIZE;i++){
        if(!strcmp(SYM[i],symbol)){ //compares both the strings and if they are not equal returns the index
            return i;
        }
    }

    for(i=0;i<MAX_SIZE;i++){
        if(!strcmp(SYM[i],"")){ //compares entries of SYM array with null string and returns index
            strcpy(SYM[i],symbol); //copies symbol to the required index in the SYM array
            return i;
        }
    }
    return -1; //returns -1 if all the above conditions are not satisfied
}

int main(){
	int i;
    init();
    int status; //used for scanning choice of the user
    stock *s; //declaration for stock structure
    while(1){
        printf("Press 1 to enter new stock\n");
		printf("Press 2 to find LIFO and FIFO dollar cost average for the number of shares sold\n");
		printf("Press 3 to print list\n");
		printf("Press 4 to exit\n");
        scanf("%d",&status); //takes input of user
        if(status ==1){ //if status is 1 then stock need to be added in stack and queue
            s= (stock*)malloc(sizeof(stock)); //memory allocation
            s->next = NULL;
            printf("Enter the Ticker\n");
            scanf("%s",s->symbol); //symbol of stock

            printf("Enter the Name\n");
            fflush(stdin);
            gets(s->name); //name of stock

            printf("Enter the Number of shares and price\n");
            scanf("%d%lf",&s->purchase,&s->price); //purchase and price of stock
            //finds index of particular symbol
            int index = symbolsearch(s->symbol);

            push(s,index); //pushes stock s in st[index]
            stock* snew = copy(s);
            enQueue(snew,index); //enqueues stock s in q[index]
        }
        else if (status ==2){ //if status is 2 then computation of FIFO and LIFO is done
            printf("Enter the SYMBOL of share\n");
            char sind[MAX_SIZE];
            scanf("%s",sind); //search symbol
            //finds index of particular symbol
            int index = symbolsearch(sind);
            printf("Printing LIFO dollar cost average for the number of shares sold: ");
            //LIFO calculation
            double amt=0; //takes total amount of last 250 shares
            int pur=0; //counts 250 shares
            while(st[index].head){ //looping condition for st[index]
                stock *curr = st[index].head;
                if((pur+curr->purchase)<=250){ //if count of shares is less than 250 add
                    amt+=(double)curr->purchase*curr->price; //add in amount the product of purchase and price
                    pur+=curr->purchase; //add the count of shares
                }
                else{ //if count of shares is greater than 250
                    amt+=(double)(250-pur)*curr->price; //add remaining shares amount
                    break;
                }
                st[index].head=curr->next; //next value for looping
            }
            printf("%lf\n",amt/250); //printing the value of LIFO average
            printf("Printing FIFO dollar cost average for the number of shares sold: ");
            //FIFO calculation
            amt=0; //takes total amount of last 250 shares
            pur=0; //counts 250 shares
            stock *curr = q[index].front;
            while(curr!=q[index].rear){ //looping condition
                if((pur+curr->purchase)<=250){ //if count of shares is less than 250 add
                    amt+=(double)curr->purchase*curr->price; //add in amount the product of purchase and price
                    pur+=curr->purchase; //add the count of shares
                }
                else{ //if count of shares is greater than 250
                    amt+=(double)(250-pur)*curr->price; //add remaining shares amount
                    break;
                }
                curr=curr->next; //next value for looping
            }
            printf("%lf\n",amt/250); //printing the value of FIFO average
        }
        else if (status == 3) { //print list
        	for(i = 0; i <= st->top; i++)
            	printStack(st[i].head);
        } else {
        	return 1;
		}
    }
    return 1;
}


#include "structure.h"
//structure to define stack

//Adds stock structure s at top of st[index]
void push(stock *s,int index) {
    s->next = st[index].head;
    st[index].head = s;
    st[index].top++;
}
// make a copy content of stock
stock* copy(stock *s)
{
	stock* snew = (stock*)malloc(sizeof(stock));
	snew->price = s->price;
	snew->purchase = s->purchase;
	strcpy(snew->name, s->name);
	strcpy(snew->symbol, s->symbol);
	return snew;
}
//Removes stock structure from st[index]
stock* pop(int index){
    stock *s = st[index].head;
    st[index].head=s->next;
    return s;
}
// print all stocks
void printStack(stock *s)
{
	if (s != NULL) {
		printf("Symbol: %s\n", s->symbol);
		printf("Name: %s\n", s->name);
		printf("Purchage: %d\n", s->purchase);
		printf("Price: %.2f\n", s->price);
		printf("-----\n");	
		printStack(s->next);	
	}
}

//function to add stock structure s to q[index]
void enQueue(stock *s,int index)
{
    // If queue is empty, then new node is front and rear both
    if (q[index].rear == NULL)
    {
       q[index].front = q[index].rear = s;
       return;
    }

    // Add the new node at the end of queue and change rear
    q[index].rear->next = s;
    q[index].rear = s;
}

// Function to remove a stock structure from q[index]
stock *deQueue(int index)
{
    // If queue is empty, return NULL.
    if (q[index].front == NULL)
       return NULL;

    // Store previous front and move front one node ahead
    stock *temp = q[index].front;
    q[index].front = q[index].front->next;

    // If front becomes NULL, then change rear also as NULL
    if (q[index].front == NULL)
       q[index].rear = NULL;
    return temp;
}

