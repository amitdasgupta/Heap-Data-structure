#include <iostream>
#include<tuple>
#define MAX_HEAP 1
#define MIN_HEAP 0;
using namespace std;
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
/************************maximum elemnt of amx heap*/////////////////////
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
void resizeHeap(Heap* h)
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
    }
    h->size_++;
    int i=h->size_-1;
    while(parentOfAnyNode(h,i)!=-1&&h->arr[parentOfAnyNode()>data])
    {
        h->arr[i]=h->arr[parentOfAnyNode(i)];
        i=parentOfAnyNode(h,i);
    }
    h->arr[i]=data;

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
        tie(x,y)=ChildsOfAnyNode(i);
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
            h->arr[i]=temp;
            temp=h->arr[min_];
            h->arr[min_]=temp
            heapifyAnElementMinHeap(h,min_)
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
    h->arr[0]=h->arr[h->size_-];
    h->size_--;
    heapifyAnElementMinHeap(h,i)
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
    while(parentOfAnyNode(h,i)!=-1)
    {
        i=parentOfAnyNode(h,i);
        heapifyAnElement(h,i);
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
    while(parentOfAnyNode(i)!=-1)
    {
        i=parentOfAnyNode(i);
        heapifyAnElementMinHeap(h,i);
    }
}
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
}
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
}
int main()
{/************
    Heap* h=NULL;
    insertIntoMaxHeap(h,3);
    insertIntoMaxHeap(h,2);
    insertIntoMaxHeap(h,4);
    insertIntoMaxHeap(h,1);
    insertIntoMaxHeap(h,6);
    insertIntoMaxHeap(h,13);
    insertIntoMaxHeap(h,17);*//////////////////////////
 //   cout<<h->capacity<<" "<<h->size_;
   // printHeapArray(h);
   // heapDeleteMaxHeap(h);
   /**** cout<<"\nafter deletion elements are";
    printHeapArray(h);*/
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

    return 0;
}
