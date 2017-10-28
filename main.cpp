#include <iostream>
#include<tuple>
#include<vector>
#include<queue>
#define MAX_HEAP 1
#define MIN_HEAP 0;
#define pp pair<int,int>
using namespace std;
/***********************************stack implementation using priority queue*////////////////
class Stack{
    priority_queue<pp> pq;
    int count=0;
public:
    void push(int data)
    {
        pq.push(pp(count++,data));
    }
    void pop()
    {
        pq.pop();
    }
    void top()
    {
        pp pd;
        pd=pq.top();
        cout<<pd.second<<" ";
    }
    bool isEmpty()
    {
        return pq.empty();
    }

};
/***********************implementation of queue using min heap*////////////////////////
class MyComparator{
public:
    bool operator()(pp &a,pp &b)
    {
        return a.first>b.first;
    }
};
class Queue{
    priority_queue<pp,vector<pp>,MyComparator> pq;
int count=0;
public:
    void enQueue(int data)
    {
        pq.push(pp(++count,data));
    }
    void deQueue()
    {
        pp pd=pq.top();
        pq.pop();
        cout<<pd.second<<" ";
    }
    bool isEmpty()
    {
        return pq.empty();
    }

};
/******************defination of heap*/////////////////////////////
class Heap{
public:
    int *arr;
    int capacity;
    int size_;
    int type;
    Heap(int capacity,int type)
    {
        this->capacity=capacity;
        this->type=type;
        this->arr=new int[capacity];
        this->size_=0;
    }
};
/************parent of any node*///////////////////////////////////
int parentOfAnyNode(Heap* heap,int i)
{
    if(i<=0||i>=heap->size_)
        return -1;
    else
        return (i-1)/2;
}
/*********************childs of any node*//////////////////////
pair<int,int> ChildsOfAnyNode(Heap* heap,int i)
{
   int left=2*i+1;
   int right=2*i+2;
   if(left>=heap->size_&&right>=heap->size_)
    return make_pair(-1,-1);
   if(left>=heap->size_)
   return make_pair(-1,right);
   else
    if(right>=heap->size_)
    return make_pair(left,-1);
   else
    return make_pair(left,right);
}
/************************maximum elemnt of max heap*/////////////////////
int maximumElementOfMaxHeap(Heap* h)
{
    if(!h)
        return -1;
    else
        return h->arr[0];
}
/*****************************minimum element of minheap*///////////////
int minimumElemntOfMinHeap(Heap* h)
{
    if(!h)
        return -1;
    else
        return h->arr[0];
}
/******************code to resize a heap*////////////////
void resizeHeap(Heap* &h)
{
    int *new_array=new int[h->capacity*2];
    for(int i=0;i<h->capacity;i++)
    {
        new_array[i]=h->arr[i];
    }
    delete[] h->arr;
    h->capacity=2*h->capacity;
    h->arr=new_array;
}
/************************************code to insert an elemnet in a Max-heap*/////////////////
void insertIntoMaxHeap(Heap* &h,int data)
{
    if(!h)
    {
        h=new Heap(1,1);
        h->size_=1;
        h->arr[0]=data;

    }
    else
    {
        if(h->size_==h->capacity)
        {
            resizeHeap(h);
        }
        h->size_++;
        int i=h->size_-1;
   //     h->arr[i]=data;
        while(parentOfAnyNode(h,i)!=-1&&data>h->arr[parentOfAnyNode(h,i)])
        {
            h->arr[i]=h->arr[parentOfAnyNode(h,i)];
            i=parentOfAnyNode(h,i);
        }
        h->arr[i]=data;
    }
}
/*******************code to insert data into min heap*///////////////////////////
void insertIntoMinHeap(Heap* &h,int data)
{
    if(!h)
    {
        h=new Heap(1,0);
        h->size_=1;
        h->arr[0]=data;
        return;
    }
    else

    {
      //   cout<<"c";
    h->size_++;
    int i=h->size_-1;
  //  cout<<h->size_<<"C";
    while(parentOfAnyNode(h,i)!=-1&&h->arr[parentOfAnyNode(h,i)]>data)
    {
        h->arr[i]=h->arr[parentOfAnyNode(h,i)];
        i=parentOfAnyNode(h,i);
    }
    h->arr[i]=data;
    }

}
/*********************code to print the heap*//////////////////////////////
void printHeapArray(Heap* h)
{
    cout<<"\n";
    for(int i=0;i<h->size_;i++)
    {
        cout<<h->arr[i]<< " ";
    }
}
/*************************hepifying an element in max heap*////////////////
void heapifyAnElement(Heap* h,int i)
{
    int left,right,temp,max_;
    tie(left,right)=ChildsOfAnyNode(h,i);
   // cout<<left<<" "<<right;
    //return;
   // cout<<"amit";
    if(left==-1&&right==-1)
        return;
    else
    if(left!=-1&&right!=-1)
   {
        max_=h->arr[left]>h->arr[right]?left:right;
    max_=h->arr[i]>h->arr[max_]?i:max_;
   // cout<<max_;
    //return;
   }
   else if(left!=-1)
   {
       max_=h->arr[left]>h->arr[i]?left:i;
   }
   else if(right!=-1)
   {
    max_=h->arr[right]>h->arr[i]?right:i;
   }
    if(i!=max_)
    {  // cout<<max_<<" ";
        temp=h->arr[i];
        h->arr[i]=h->arr[max_];
        h->arr[max_]=temp;
        heapifyAnElement(h,max_);
    }
    else
        return;
}
/**********************code to heapify an min heap*////////////////////
void heapifyAnElementMinHeap(Heap* h,int i)
{
    if(i==-1)
        return;
    else
    {    int x,y,min_,temp;
        tie(x,y)=ChildsOfAnyNode(h,i);
        if(x!=-1&&y!=-1)
        {
            min_=h->arr[x]<h->arr[y]?x:y;
            min_=h->arr[i]<h->arr[min_]?i:min_;
        }
        else
            if(x==-1&&y!=-1)
        {

            min_=h->arr[i]<h->arr[y]?i:y;
        }
        else
            if(x!=-1&&y==-1)
        {
            min_=h->arr[x]<h->arr[i]?x:i;
        }
        else
            return;
        if(min_!=i)
        {
            temp=h->arr[i];
           h->arr[i]=h->arr[min_];
            h->arr[min_]=temp;
            heapifyAnElementMinHeap(h,min_);
        }
        else
            return;
    }
}
/*******************code to delete an element in in heap*////////////////
void heapDeleteMaxHeap(Heap* h)
{
    h->arr[0]=h->arr[h->size_-1];
    h->size_--;
    //cout<<"C";
    heapifyAnElement(h,0);

}
/******************code to delete an elemnt in amx heap*/////////////////
void heapDeleteMinHeap(Heap* h)
{
    h->arr[0]=h->arr[h->size_];
    h->size_--;
    heapifyAnElementMinHeap(h,0);
}
/***************code to build an heap from an array*///////////////////////////
void buildHeap(Heap* &h,int arr_[],int n)
{
    h=new Heap(n,1);
    h->size_=n;
    int i;
    for(i=0;i<n;i++)
    {
        h->arr[i]=arr_[i];
    }
    i=n-1;
    i=parentOfAnyNode(h,i);
    while(i>=0)
    {
        heapifyAnElement(h,i);
        i--;
    }
}
/*****************************build min heap*/////////////////////
void buildHeapMin(Heap* &h,int arr[],int n)
{
    h=new Heap(n,0);
    h->size_=n;
    for(int i=0;i<n;i++)
    {
        h->arr[i]=arr[i];
    }
    int i=n-1;
    while(parentOfAnyNode(h,i)!=-1)
    {
        i=parentOfAnyNode(h,i);
        heapifyAnElementMinHeap(h,i);
    }
}
/********************function to do heap sort of an array
void heapSort(Heap* h)
{
    int temp;
    while(h->size_>0)
    {
       temp= h->arr[h->size_-1];
       h->arr[h->size_-1]=h->arr[0];
       h->arr[0]=temp;
        h->size_--;
        heapifyAnElement(h,0);
    }
}*////////////////
/*********************
bool isHeap(Heap* h,int node)
{
if(!h)
    return false;
else
{
int x,y;
tie(x,y)=ChildsOfAnyNode(h,node);
cout<<x<<" "<<y<<endl;
if(x!=-1&&y!=-1)
return h->arr[x]<h->arr[node]&&h->arr[y]<h->arr[node]&&isHeap(h,x)&&isHeap(h,y);
if(x!=-1&&y==-1)
return h->arr[x]<h->arr[node]&&isHeap(h,x);
else
if(y!=-1&&x==-1)
return h->arr[y]<h->arr[node]&&isHeap(h,y);
else
    return true;

}
}*/////////////////////
/***************code to give maimum element in min heap*///////////////////
int giveMaxElementInMinHeap(Heap* h)
{
    int i=parentOfAnyNode(h,h->size_-1)+1;
    int max_=0;
  //  cout<<"i:"<<i;
    for(int j=i;j<h->size_;j++)
        if(h->arr[j]>max_)
        max_=h->arr[j];
    return max_;

}
/**********************code to delete an arbitrary element from the min heap*///////////////////
void deleteArbitraryElementFromMinHeap(Heap* h,int data)
{
    int x,y,child;
    int i=0;
    while(1)
    {
        tie(x,y)=ChildsOfAnyNode(h,i);
        if(h->arr[x]==data||h->arr[y]==data)
            break;
        i++;
        if(i==(h->size_-1));
    }
    child=h->arr[x]==data?x:y;
    h->arr[child]=h->arr[h->size_-1];
    h->size_--;
    heapifyAnElementMinHeap(h,child);

}
/*************code to print all the elements less than given element*/////////////////////
void printSmallerThan(Heap* h,int data,int i,vector<int> &vec)
{
    if(h->arr[i]>data)
        return;
    else
        {
            if(h->arr[i]<data)
        vec.push_back(h->arr[i]);
        int x,y;
        tie(x,y)=ChildsOfAnyNode(h,i);
        if(x==-1&&y==-1)
            return;
        if(x!=-1)
        printSmallerThan(h,data,x,vec);
        if(y!=-1)
        printSmallerThan(h,data,y,vec);
        }
}
/***************code to delete an heap*////////////=
void delheap(Heap* h)
{
    if(h)
        if(h->arr)
        delete[] h->arr;
    delete h;
}
/********************code to merge two heaps*/////////////////////////////
void mergeMaxHeaps(Heap* &h1,Heap* &h2)
{
    int i=0;
    int *arr_=new int[h1->size_+h2->size_];
    for(;i<h1->size_;i++)
        arr_[i]=h1->arr[i];
    for(;i<(h2->size_+h1->size_);i++)
        arr_[i]=h2->arr[i-h1->size_];
    delheap(h1);
    delheap(h2);
    cout<<i<<"c";
    h1=NULL;
    buildHeap(h1,arr_,i);
}
/**********************
int deleteKElement(Heap* h,int k)
{
    if(!h)
        return 0;
    else
    {
        Heap* h_min=NULL;
        int x,y;
        int i=0,j=0,temp;
        insertIntoMinHeap(h_min,h->arr[j]);
        while(1)
        {
         temp=minimumElemntOfMinHeap(h_min);
       //  cout<<i<<":"<<temp<<" ";
          heapDeleteMinHeap(h_min);
         if(++i==k)
            return temp;
         else
         {

             tie(x,y)=ChildsOfAnyNode(h,j);
             j++;
             if(x!=-1)
             insertIntoMinHeap(h_min,h->arr[x]);
             if(y!=-1)
             insertIntoMinHeap(h_min,h->arr[y]);


         }
        }


    }
}*///////////////
/*************code to print k elements of max heap
void printKMaxElementsmaxHeap(Heap* h,int k)
{
    if(!h)
        return;
    else
    {
      int temp;
      while(k--)
      {
          temp=maximumElementOfMaxHeap(h);
          heapDeleteMaxHeap(h);
          cout<<temp<<" ";
      }
    }
}*////////////////////////////
/***************************code to find k max elements in max heap*///////////////////////////////
void printKMaxElementsmaxHeap(Heap* h,int k)
{
    if(!h)
        return;
    else
    {
        Heap* h_max=NULL;
        int x,y,temp;
        int i=0;
        insertIntoMaxHeap(h_max,h->arr[0]);
        while(i<k)
        {
            tie(x,y)=ChildsOfAnyNode(h,i);
            insertIntoMaxHeap(h_max,h->arr[x]);
            insertIntoMaxHeap(h_max,h->arr[y]);
            i++;
        }
        while(k--)
        {
            temp=maximumElementOfMaxHeap(h_max);
            heapDeleteMaxHeap(h_max);
            cout<<temp<<" ";
        }

    }
}
int main()
{   /********
    Heap* h=NULL;
    insertIntoMaxHeap(h,3);
    insertIntoMaxHeap(h,2);
    insertIntoMaxHeap(h,4);
    insertIntoMaxHeap(h,1);
    insertIntoMaxHeap(h,6);
    insertIntoMaxHeap(h,13);
    insertIntoMaxHeap(h,17);
*****/

    //   cout<<h->capacity<<" "<<h->size_;
   // printHeapArray(h);
   /**** int k;
    cin>>k;
    printKMaxElementsmaxHeap(h,k);*///////////////
    // heapDeleteMaxHeap(h);
    /**** cout<<"\nafter deletion elements are";*/
    //printHeapArray(h);
    /********* int arr[10000],n,temp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        arr[i]=temp;
    }
    buildHeap(h,arr,n);
    printHeapArray(h);
    heapSort(h);
    h->size_=n;
    cout<<"\nsorted array";
    printHeapArray(h);*///////////////
    /*****if(isHeap(h,0))
    cout<<"yes it is a heap";
    else
        cout<<"it is not an heap";*/////////////
    /**********************this section is related to min heaps algorithms*//////////////
  /**********  Heap* h=NULL;
    insertIntoMinHeap(h,3);
    insertIntoMinHeap(h,2);
    insertIntoMinHeap(h,4);
    insertIntoMinHeap(h,1);
    insertIntoMinHeap(h,6);
    insertIntoMinHeap(h,13);
    printHeapArray(h);
    int k;
    cin>>k;
    cout<<deleteKElement(h,k);*////////
    /*** cout<<"\n maximum element in min heap is";
    cout<<giveMaxElementInMinHeap(h);*///
    /****   int data;
    cin>>data;
    deleteArbitraryElementFromMinHeap(h,data);*///
    // printHeapArray(h);
    /******** vector<int>  vec;
    int data;
    cin>>data;
    printSmallerThan(h,data,0,vec);
    cout<<"\nsmaller elements are";
    for(auto it:vec)
        cout<<it<<" ";
    return 0;*//////////////////////////
   /*****************
    code for merging heaps
    Heap* h1=NULL,*h2=NULL;
    insertIntoMaxHeap(h1,3);
    insertIntoMaxHeap(h1,2);
    insertIntoMaxHeap(h1,4);
    insertIntoMaxHeap(h1,1);
    insertIntoMaxHeap(h1,6);
    insertIntoMaxHeap(h1,13);
    printHeapArray(h1);
    insertIntoMaxHeap(h2,5);
    insertIntoMaxHeap(h2,9);
    insertIntoMaxHeap(h2,13);
    insertIntoMaxHeap(h2,8);
    insertIntoMaxHeap(h2,10);
    insertIntoMaxHeap(h2,20);
    printHeapArray(h2);
    mergeMaxHeaps(h1,h2);
    printHeapArray(h1);

*///////////////////////////
Queue s;
int n,temp;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>temp;
    s.enQueue(temp);
}
while(!s.isEmpty())
{

    s.deQueue();
}

}
