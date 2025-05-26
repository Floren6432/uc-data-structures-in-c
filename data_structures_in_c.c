#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int myMenu ();
//array
void arrayIntro();
void myArray (int arr[]);
void displayArray (int arr[]);
void arrayMenu ();
void traverseArray (int arr[]);
void insertionArray (int arr[]);
void deletionArray (int arr[]);
void searchArray (int arr[]);
void updateArray (int arr[]);

//Stack

#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;
void stackIntro();
void push(int item);
int pop();
int peek();
void display();

//Queues

#define MAX_QUEUE_SIZE 10
int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;
void queueIntro();
int isFull();
int isEmpty();
void enqueue(int value);
void dequeue();
void queueDisplay();

//singly linkedList
struct node {
    int value;
    struct node *next;
    //Trees
    int data;
    struct node *left;
    struct node *right;
    //graph
    int vertex;
};

void printLinkedlist (struct node *p);
void traverseLinkedList (struct node *p);
int deleteNode (struct node **head, int value);
struct node *searchNode (struct node *head, int value);
void insertNode (struct node **head, int value, int position);
struct node *head = NULL;
//Sorting algo
#define SIZE 5
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);

//searching algo
int linearSearch(int arr[], int n, int x);
int binarySearch(int arr[], int left, int right, int x);
int interpolationSearch(int arr[], int n, int x);

//Trees
void treeIntro();
void treeHeader();

struct node *newNode(int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        return newNode(data);
    } else {
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}
void inorder(struct node *root);

//graph
void graphIntro();
#define MAX_VERTICES 100
struct Graph {
    struct node* adjList[MAX_VERTICES];
    int numVertices;
};

struct Graph* createGraph(int numVertices);
void addEdge(struct Graph* graph, int src, int dest);
void printGraph(struct Graph* graph);

int main (){
  int menuDecision;
  int choice = 0;
  int i;
  
  
  menuDecision = myMenu (menuDecision);
  system("clear");
  if (menuDecision == 1){////////////////array
      arrayIntro();
      printf("\nPress 'Enter' to continue...");
      getchar();
      system("clear");
      int getArray[5] = { };
      myArray (getArray);
      system ("clear");
      displayArray (getArray);
      while(1){
      printf("\n");
      arrayMenu ();
      scanf ("%d", &choice);
      
      if(choice==0){
        system("clear");
        printf("\033[36mExiting program...\033[0m");
        break;
    }
    
      switch (choice){
          case 1:
          traverseArray (getArray);
          break;
          case 2:
          insertionArray (getArray);
          break;
          case 3:
          deletionArray (getArray);
          break;
          case 4:
          searchArray (getArray);
          break;
          case 5:
          updateArray (getArray);
          break;
          default:
          printf("\033[31mInvalid input!\033[0m");
          break;
      }
    }
    
 }
  if(menuDecision==2){//-------------------------------------------------------------stack
    int choice, item;
    printf ("\t\tData Structures: C Edition\n");
    for (int i = 0; i < 30; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
    i = 0;
    printf("\n");
    printf("\n\t     A stack is a data structure that follows\n\tthe Last-In-First-Out (LIFO) principle,");
    printf("\n\twhere the last item added is the first one\n\tto be removed.");
    printf("\n\tIt supports two main operations: push \n\t(to add an element to the top)");
    printf("\n\tand pop (to remove the top element).\n\tStacks are commonly used in");
    printf("\n\tapplications such as function\n\tcall management, expression evaluation,\n\tand backtracking algorithms."); 
    printf("\n");
    printf("\n");
     for (i = 0; i < 30; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
    printf("\n");
    printf("\nPress 'Enter' to continue...");
      getchar();
    stackIntro();
    while(1){
    
    printf("\n\t\t     Stack Operations:\n");
    
    printf("\n\t\t[1] Push\t[3] Peek\n");
    printf("\t\t[2] Pop\t\t[4] Display\n");
    printf("\t\t[5] Exit\n");
    printf("\nPlease enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice){
      case 1:
        printf("Enter the item to be pushed: ");
        scanf("%d", &item);
        push(item);
        stackIntro();
        break;
      case 2:
        item = pop();
        if (item != -1) {
          printf("Popped item: %d\n", item);
        }
        stackIntro();
        break;
      case 3:
        item = peek();
        if (item != -1) {
          printf("Top item: %d\n", item);
        }
        stackIntro();
        break;
      case 4:
        display();
        printf("Press 'Enter' to continue...");
        getchar();
        stackIntro();
        break;
      case 5:
        return 0;
      default:
        printf("\033[31mInvalid choice!\033[0m\n\n");
        getchar();
        stackIntro();
        }
    }
}
  if(menuDecision==3){
       int choice, value;
       queueIntro();
      getchar();
      system("clear");
    while (1) {
    printf ("\t\tData Structures: C Edition\n");
    for (int i = 0; i < 30; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
    printf("\n");
    printf("\t\t     Queue Operations:\n");
    printf("\t\t[1] Enqueue\t[3] Display\n");
    printf("\t\t[2] Dequeue\t[4] Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the value to be added to the queue: ");
        scanf("%d", &value);
        enqueue(value);
        getchar();
        getchar();
        system("clear");
        break;

      case 2:
        dequeue();
        getchar();
        getchar();
        system("clear");
        break;

      case 3:
        queueDisplay();
        getchar();
        getchar();
        system("clear");
        break;

      case 4:
        printf("Exiting program...\n");
        return 0;

      default:
        printf("\033[31mInvalid input!\033[0m\n");
        getchar();
        getchar();
        system("clear");
        break;
    }
  }
  }
  if(menuDecision==4){
      char ch; 
      int option;
      int n1, n2, n3, n4;
      struct node *head = NULL;
      struct node *one = NULL;
      struct node *two = NULL;
      struct node *three = NULL;
      struct node *four = NULL;
      
      one = malloc(sizeof(struct node));
      two = malloc(sizeof(struct node));
      three = malloc(sizeof(struct node));
      four = malloc(sizeof(struct node));
      
      one->value = 1;
      two->value = 2;
      three->value = 3;
      four->value = 4;
      
      one->next = two;
      two->next = three;
      three->next = four;
      four->next = NULL;
      head = one;
      
    printf ("\t\tData Structures: C Edition\n");
    for (int i = 0; i < 30; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
    i = 0;
    printf("\n");
    printf("\n\t     A singly-linked list is a data structure where\n\teach node contains a value and a reference to ");
    printf("\n\tthe next node in the list. It forms a sequence\n\tof elements, starting from the head node and ");
    printf("\n\tending with a tail node pointing to NULL. \n\tSingly-linked lists are efficient for insertion and ");
    printf("\n\tdeletion at the head, but sequential traversal\n\tis necessary to access or modify other nodes.");
    printf("\n");
    printf("\n");
    for (i = 0; i < 30; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
    printf("\n");
    printf("\nPress 'Enter' to continue...");
    getchar();
    getchar();
    system("clear");
      do {
          printf ("\t\tData Structures: C Edition\n");
        for (int i = 0; i < 30; i++)
        {
          printf ("\x1b[34m-\x1b[0m");
          printf ("\x1b[33m+\x1b[0m");
        }
        printf("\n");
        printf("\t       Singly-Linked-List Operations\n");
        for (int i = 0; i < 30; i++){
                printf ("\x1b[34m-\x1b[0m");
                printf ("\x1b[33m+\x1b[0m");
            }
          printf("\n\t\t[1] Traverse\t[4] Search\n\t\t[2] Insertion\t[5] Exit\n\t\t[3] Deletion\n\nSingly-Linked List: ");
          printLinkedlist(head);
          
          printf("\nEnter your option: ");
          scanf("%d", &option);
          system("clear");
          switch(option) {
              case 1:
              four->next = one;
              one->next = two;
              two->next = three;
              three->next = NULL;
              head = four;
              printf("\033[32mTraverse Linked List:\033[0m\n");
              traverseLinkedList(head);
              break;
              
              case 2:
              int valueToInsert, position;
              printf("Linked List: ");
              printLinkedlist(head);
              printf("\nEnter the value to be inserted: ");
              scanf("%d", &valueToInsert);
              printf("Enter the position to insert the node: ");
              printf("\n\t[1]  Head ");
              printf("\n\t[2]  Middle");
              printf("\n\t[3]  Tail\n");
              scanf("%d", &position);
              insertNode(&head, valueToInsert, position);
              printf("\nLinked List after insertion:\n");
              printLinkedlist(head);
              break;
              
              case 3:
              int valueToDelete;
              printf("Linked List: ");
              printLinkedlist(head);
              printf("\nEnter the value of the node to be deleted: ");
              scanf("%d", &valueToDelete);
              if (deleteNode(&head, valueToDelete) == 0){
                  printf("\nNode with value %d not found\n", valueToDelete);
                  
              } 
              else{
                  printf("\nNode with value %d deleted\n", valueToDelete);
                  printf("\nLinked List after deletion:");
                  printLinkedlist(head);
              }
              break;
              
              case 4:
              int searchValue;
              printf("Linked List: ");
              printLinkedlist(head);
              printf("\nEnter the value to search:");
              scanf("%d", &searchValue);
              struct node *result = searchNode(head, searchValue);
              if (result == NULL) {
                  printf("\033[31mValue not found.\033[0m\n");
                  
              } 
              else {
                  printf("\033[32mValue found.\033[0m\n");
                  
              }
              break;
              
              case 5:
              system("clear");
              printf("\033[36mExiting program...\033[0m");
              exit(0);
              break;
              
              default:
              char y;
              printf("\033[1;31mInvalid option.\n\033[0m");
              option = y;
              break;
              
          }
          
          if (option < 5){
              printf ("\nContinue (Y/N)?: ");
              scanf (" %c", &ch);
              system("clear");
          }
      }while (ch == 'y' || ch == 'Y');
  }
  if(menuDecision==5){
    int arr[SIZE] = {3, 1, 4, 2, 5};
    int i;
    printf ("\t\t\t\t\t   Data Structures: C Edition\n");
    for (int i = 0; i < 57; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
    i = 0;
    printf("\n");
    printf("\n\t     Sorting algorithms are used to arrange elements in a specific order. They take an unsorted");
    printf("\n\tlist as input and produce a sorted list as output. Common sorting algorithms include Bubble ");
    printf("\n\tSort, Insertion Sort, and Selection Sort.\n");
    
    printf("\n\tBubble Sort repeatedly compares adjacent elements and swaps them if they are in the ");
    printf("\n\twrong order until the entire list is sorted. It has a time complexity of O(n^2) in the worst case.\n");
    
    printf("\n\tInsertion Sort works by repeatedly taking an element from the unsorted part of the list and ");
    printf("\n\tinserting it into the correct position in the sorted part. It has a time complexity of O(n^2) in ");
    printf("\n\tthe worst case but performs well on small lists or partially sorted lists.\n");
    
    printf("\n\tSelection Sort finds the minimum element from the unsorted part of the list and swaps it ");
    printf("\n\twith the first unsorted element. It continues this process until the list is sorted. Selection Sort ");
    printf("\n\talso has a time complexity of O(n^2) in the worst case.\n");
    
    printf("\n\t     These algorithms provide different trade-offs in terms of time complexity and performance ");
    printf("\n\tcharacteristics, making them suitable for different scenarios.\n");
    
    printf("\033[36m\n\tConsider this situation:\033[0m you have an unsorted array of numbers {3, 1, 4, 2, 5} that requires sorting.\n");
    
    printf("\n");
    printf("\n");
    for (i = 0; i < 57; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
    printf("\n");
    printf("\nPress 'Enter' to continue...");
    getchar();
    getchar();
    system("clear");
    
    
    
    
    
    
    printf("\033[33mBefore sorting: \033[0m");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    bubbleSort(arr, SIZE);
    printf("\033[32mAfter bubble sort: \033[0m");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int arr2[SIZE] = {3, 1, 4, 2, 5};
    insertionSort(arr2, SIZE);
    printf("\033[32mAfter insertion sort: \033[0m");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    
    int arr3[SIZE] = {3, 1, 4, 2, 5};
    selectionSort(arr3, SIZE);
    printf("\033[32mAfter selection sort: \033[0m");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

  }
  if(menuDecision==6){
    int i, n, arr[MAX_SIZE], x;
    
    printf ("\t\t\t\t\t   Data Structures: C Edition\n");
    for (i = 0; i < 57; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
    i = 0;
    printf("\n");
    printf("\n\t    Searching algorithms are used to find the presence or location of a specific element within a");
    printf("\n\tcollection of data. They allow efficient retrieval of information and are essential in various ");
    printf("\n\tapplications. Common searching algorithms include Linear Search, Binary Search, and");
    printf("\n\tInterpolation Search.\n");
    
    printf("\n\tLinear Search iterates through each element of the data sequentially, comparing it with the");
    printf("\n\ttarget element until a match is found or the end of the data is reached. It has a time");
    printf("\n\tcomplexity of O(n), making it suitable for small or unordered datasets.\n");
    
    printf("\n\tBinary Search operates on sorted data by repeatedly dividing the search space in half, ");
    printf("\n\tcomparing the target element with the middle element, and narrowing down the search ");
    printf("\n\trange until the target is found or determined to be absent. It has a time complexity of O(log n)");
    printf("\n\tand is efficient for large, sorted datasets.\n");
    
    printf("\n\tInterpolation Search is an improvement over binary search for uniformly distributed sorted ");
    printf("\n\tdata. It estimates the position of the target element based on the values of the first and last ");
    printf("\n\telements, allowing it to make more informed guesses and reduce the number of");
    printf("\n\tcomparisons. Its time complexity varies but can be close to O(log log n) for well-distributed data.\n");
    
    printf("\n\t     These searching algorithms offer different trade-offs in terms of time complexity and ");
    printf("\n\tsuitability for different scenarios, allowing for efficient retrieval of data based on specific");
    printf("\n\trequirements.\n");
    
    printf("\n");
    printf("\n");
    for (i = 0; i < 57; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
    printf("\n");
    printf("\nPress 'Enter' to continue...");
    getchar();
    getchar();
    system("clear");
    
    
    
    
    printf("Enter the number of elements in the array (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    printf("Enter the %d elements in the array: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &x);
    int result = linearSearch(arr, n, x);
    if (result == -1) {
        printf("\033[0;31mElement not found using linear search.\n\033[0m");
    } else {
        printf("\033[0;32mElement found at index %d using linear search.\n\033[0m", result);
    }
    result = binarySearch(arr, 0, n - 1, x);
    if (result == -1) {
        printf("\033[0;31mElement not found using binary search.\n\033[0m");
    } else {
        printf("\033[0;32mElement found at index %d using binary search.\n\033[0m", result);
    }
    result = interpolationSearch(arr, n, x);
    if (result == -1) {
        printf("\033[0;31mElement not found using interpolation search.\n\033[0m");
    } else {
        printf("\033[32mElement found at index %d using interpolation search.\n\033[0m", result);
    }
  }
  if(menuDecision==7){
    struct node *root = NULL;
    int choice, data;
    treeIntro();
    printf("\nPress 'Enter' to continue...");
    getchar();
    getchar();
    system("clear");
    treeHeader();
    do {
        printf("\n\t\t\t\t\t     Binary Tree Operations:\n");
        printf("\t\t\t\t\t     [1] Insert element\n");
        printf("\t\t\t\t\t     [2] Inorder traversal\n");
        printf("\t\t\t\t\t     [3] Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                root = insert(root, data);
                getchar();
                system("clear");
                treeHeader();
                break;
            case 2:
                printf("\033[0;32mInorder traversal: \033[0m");
                inorder(root);
                printf("\n");
                getchar();
                getchar();
                system("clear");
                treeHeader();
                break;
            case 3:
                printf("\033[0;36mExiting...\n\033[0m");
                getchar();
                getchar();
                system("clear");
                treeHeader();
                break;
            default:
                printf("\033[0;31mInvalid choice\033[0m\n");
                getchar();
                getchar();
                system("clear");
                treeHeader();
        }
    } while (choice != 3);
  }
  if(menuDecision==8){//Graphing
    graphIntro();
    int numVertices = 5;
    struct Graph* graph = createGraph(numVertices);
    
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Undirected Graph:\n");
    printGraph(graph);

  }
  return 0;
}

//-------------------functions--------------------
int myMenu (){
  int menuChoice = 0;
  int i;
  printf ("\t\tData Structures: C Edition\n");
  for (i = 0; i < 30; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
  i = 0;
  printf ("\n\n\t[1] Array\t\t[5] Sorting Algorithms\n\t[2] Stack\t\t[6] Searching Algorithms\n\t[3] Queues\t\t[7] Trees\n\t[4] Singly-Linked List\t[8] Graph\n");
  printf ("\n");
  for (i = 0; i < 30; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
  printf ("\n\nPlease select an operation: ");
  scanf ("%d", &menuChoice);
  return menuChoice;
}
//------------------------------------------------array---------------------------
void arrayIntro(){
    int i;
    printf ("\t\tData Structures: C Edition\n");
    for (i = 0; i < 30; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
    i = 0;
    printf("\n");
    printf("\n\tAn array is a data structure that stores\n     a fixed-size sequence of elements of the same type."); 
    printf("\n     It provides efficient access to elements through\n     indices and uses contiguous memory allocation."); 
    printf("\n     Arrays are crucial for organizing and\n     manipulating data, forming the foundation\n     for more advanced data structures and algorithms.\n");
    printf("\n");
     for (i = 0; i < 30; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
    printf("\n");
    getchar();
}

void myArray (int arr[]) {
  int size = 5;
  int i = 0;
  printf ("Enter 5 elements for the: ");
  for (i = 0; i < size; i++)
    {
      scanf ("%d", &arr[i]);
      printf("\033[0;32m"); //green
      printf ("Number Stored!\n");
      printf("\033[0m"); // reset color to default
    }
}

void displayArray (int arr[]){
  int i;
  printf ("\t\t\tData Structures: C Edition\n");
    for (i = 0; i < 38; i++){
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
        
    }
  printf("\033[35m\n Your Array: \033[0m");
  for (i = 0; i <= 5 - 1; i++)
    {
      printf ("Arr[%d] = %d", i, arr[i]);
      if (i < 5 - 1)
	{
	  printf (", ");
	}
    }
}

void arrayMenu (){
  int i;
  for (i = 0; i < 38; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }

  printf ("\n\t\t\t     Array Operations:\n");
  printf ("\n\t\t\t[1] Traverse\t[4] Search\n\t\t\t[2] Insert\t[5] Update\n\t\t\t[3] Delete\t[0] Exit\n");
  printf ("\n Please select an operation: ");
}

void traverseArray (int arr[]) {
  int i;
  system ("clear");
  printf ("\t\t\tData Structures: C Edition\n");
    for (i = 0; i < 38; i++){
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
        
    }
  printf("\033[32m\nYour Array: \033[0m");
  for (i = 0; i < 5; i++)
    {
      printf ("Arr[%d] = %d", i, arr[i]);
      if (i < 5-1)
	{
	  printf (", ");
	}
    }
}

void insertionArray (int arr[]) {
  int i, x, pos, n = 0;
  int size = 5;
  system("clear");
  printf ("Enter a number to be contained in an array: ");
  scanf ("%d", &x);
  printf ("\n");
  
  system("clear");
  printf("From what position do you want to put the number in?(Array length is currently 5) ");
  scanf ("%d", &pos);

  n++;
  for (i = n; i >= pos; i--)
    {
      arr[i] = arr[i - 1];
    }
  arr[pos - 1] = x;
  system("clear");
  printf ("\t\t\tData Structures: C Edition\n");
    for (i = 0; i < 38; i++){
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
        
    }
  printf("\033[32m\n\t\t\tYour Array after insertion:\n\t\033[0m");
  
  for (i = 0; i < size; i++)
    {
      printf ("Arr[%d] = %d", i, arr[i]);
      if (i < size - 1)
	{
	  printf (", ");

	}
    }
}

void deletionArray (int arr[]) {
  int k = 30, n = 5;
  int i, j;
  int size = 5;

  j = k;

  while (j < n)
    {
      arr[j - 1] = arr[j];
      j = j + 1;
    }
  n = n - 1;
  system("clear");
  printf ("\t\t\tData Structures: C Edition\n");
    for (i = 0; i < 38; i++){
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
        
    }
  printf ("\033[32m\n\t\t\tYour Array after deletion:\n\t\033[0m");;
  for (i = 0; i < size; i++)
    {
      printf ("Arr[%d] = %d", i, arr[i]);
      if (i < size - 1)
	{
	  printf (", ");
	}
    }

}

void searchArray (int arr[]) {
  int item = 0, j = 0;
  system ("clear");
  printf ("Enter an element to be searched: ");
  scanf ("%d", &item);

  while (j < 5)
    {
      if (arr[j] == item)
	{
	  break;
	}
      j = j + 1;
    }
   
  system ("clear");
  printf ("\t\t\tData Structures: C Edition\n");
  for (int i = 0; i < 38; i++){
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
        
    }
   printf("\x1b[32m\n\t\t     Element %d is found at %d position\x1b[0m", item, j + 1);

}

void updateArray (int arr[]) {
  int i, item = 50, pos = 3;
  int size = 5;
  system ("clear");
  printf ("Enter the position number you want to update: ");
  scanf ("%d", &pos);
  printf ("\n");
  printf ("Enter the number that you want to put in that position: ");
  scanf ("%d", &item);

  arr[pos - 1] = item;
  system ("clear");
  printf ("\t\t\tData Structures: C Edition\n");
    for (int i = 0; i < 38; i++){
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
        
    }
  printf ("\033[32m\n\t\t\tElements after updation:\n\t\033[0m");

  for (i = 0; i < size; i++)
    {
      printf ("Arr[%d] = %d", i, arr[i]);
      if (i < size - 1)
	{
	  printf (", ");
	}
    }
}
//Stack------------------------------------------------------------------------------------------------------------
void stackIntro(){
    getchar();
    system ("clear");
    printf ("\t\tData Structures: C Edition\n");
    for (int i = 0; i < 30; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
}
void push(int item) {
  if (top == MAX_SIZE - 1) {
    printf("Error: Stack overflow\n");
  } else {
    top++;
    stack[top] = item;
  }
}

int pop() {
  int item;
  if (top == -1) {
    printf("Error: Stack underflow\n");
    return -1;
  } else {
    item = stack[top];
    top--;
    return item;
  }
}

int peek() {
  if (top == -1) {
    printf("Error: Stack is empty\n");
    return -1;
  } else {
    return stack[top];
  }
}

void display() {
  int i;
  system("clear");
  if (top == -1) {
    printf("\033[31mStack is empty\033[0m\n");
  } else {
    printf("\033[32mStack elements:\033[0m\n");
    for (i = top; i >= 0; i--) {
      printf("%d\t", stack[i]);
    }
  }
  printf("\n\n");
}

//Queues
void queueIntro(){
    int i;
    printf ("\t\tData Structures: C Edition\n");
    for (i = 0; i < 30; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
    i = 0;
    printf("\n");
    printf("\n\t     A queue is a data structure that follows the\n\t'first-in, first-out' (FIFO) principle");
    printf(" similar to \n\twaiting in line. Elements are added to the \n\tback of the queue and removed from the front.");
    printf("\n\tQueues are useful for managing tasks or data in\n\tthe order they are received,");
    printf(" ensuring that the\n\tfirst item added is the first item processed.");
    printf("\n");

    printf("\n");
    printf("\nPress 'Enter' to continue...");
    getchar();
    
}
int isFull() {
    if (rear == MAX_QUEUE_SIZE - 1) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (front == -1 || front > rear) {
        return 1;
    }
    return 0;
}

void enqueue(int value) {
    if (isFull()) {
        printf("\033[31mQueue is full\033[0m\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("\033[36mEnqueued %d\033[0m\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("\033[31mQueue is empty\033[0m\n");
        return;
    }
    int value = queue[front];
    front++;
    printf("\033[36mDequeued %d\033[0m\n", value);
}

void queueDisplay() {
    if (isEmpty()) {
        printf("\033[31mQueue is empty\033[0m\n");
        return;
    }
    printf("\033[35mQueue:\033[0m  ");
    for (int i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if (i < rear) {
            printf(", ");
        }
    }
}
//singly-linkedList Functions
void insertNode(struct node **head, int value, int position) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;
    
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
    }
    else if (position == 2) {
        struct node *slow = *head;
        struct node *fast = (*head)->next;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        newNode->next = slow->next;
        slow->next = newNode;
    }
    else if (position == 3) {
        struct node *last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
    
}
    
void traverseLinkedList(struct node *p){
    int i = 1;
    while (p != NULL) {
        printf("Node %d: %d\n", i, p->value);
        p = p->next;
        i++;
    }
}
int deleteNode(struct node **head, int value){
    struct node *current = *head;
    struct node *previous = NULL;
    
    if (current != NULL && current->value == value) {
        *head = current->next;
        free(current);
        return 1;
    }
    
    while (current != NULL && current->value != value) {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {
        return 0;
    }
    previous->next = current->next;
    free(current);
    return 1;
    
}
    
struct node *searchNode(struct node *head, int value) {
    struct node *current = head;
    while (current != NULL && current->value != value) {
        current = current->next;
    }
    return current;
}
    
void printLinkedlist(struct node *p) {
    while (p != NULL) {
        printf("%d ", p->value);
        p = p->next;
    }
}
//sorting algo
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
//searching algo
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int interpolationSearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right && x >= arr[left] && x <= arr[right]) {
        int pos = left + ((double)(right - left) / (arr[right] - arr[left])) * (x - arr[left]);
        if (arr[pos] == x) {
            return pos;
        } else if (arr[pos] < x) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    return -1;
}
//Trees
void treeIntro(){
    int i;
    printf ("\t\t\t\t\t   Data Structures: C Edition\n");
    for (i = 0; i < 57; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
    i = 0;
    printf("\n");
    printf("\n\t    A tree is a widely used data structure that represents a hierarchical structure. It consists \n\tof ");
    printf(" nodes connected by edges, forming a branching structure with a root node at the top. Each ");
    printf("\n\tnode can have child nodes below it, creating a parent-child relationship. Trees are commonly ");
    printf("\n\tused to represent hierarchical relationships, such as in file systems, organizational charts, ");
    printf("\n\tand decision trees. They provide efficient operations for searching, insertion, deletion, and ");
    printf("\n\ttraversal.\n\n");
    for (i = 0; i < 57; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
    printf("\n");
    printf("\n");
}
void treeHeader(){
    int i;
    printf ("\t\t\t\t\t   Data Structures: C Edition\n");
    for (i = 0; i < 57; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
}
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

//graphs
void graphIntro(){
    int i;
    printf ("\t\t\t\t\t   Data Structures: C Edition\n");
    for (i = 0; i < 57; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
    i = 0;
    printf("\n");
    printf("\n\t    A tree is a widely used data structure that represents a hierarchical structure. It consists ");
    printf("\n\tvertices or nodes, connected by edges. It is a versatile and powerful data structure used to  ");
    printf("\n\tmodel relationships and connections between entities. Graphs can be used to solve various  ");
    printf("\n\tproblems, such as finding the shortest path, determining connectivity, or analyzing social ");
    printf("\n\tnetworks.\n");
    printf("\033[36m\n\t\tBelow is an example of an undirected graph represented by an adjacency list:\n\n");
    printf("\033[0m");

    for (i = 0; i < 57; i++)
    {
      printf ("\x1b[34m-\x1b[0m");
      printf ("\x1b[33m+\x1b[0m");
    }
    printf("\n");
    printf("\n");
}
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from source to destination
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add edge from destination to source
    newNode = (struct node*) malloc(sizeof(struct node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct node* temp = graph->adjList[i];
        printf("Vertex %d: ", i);

        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}


