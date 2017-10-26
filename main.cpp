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
/************************************code to inser an elemnt in a heap*/////////////////
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
/*********************code to print the heap*//////////////////////////////
void printHeapArray(Heap* h)
{

    for(int i=0;i<h->size_;i++)
    {
        cout<<h->arr[i]<< " ";
    }
}
int main()
{
    Heap* h=NULL;
    insertIntoMaxHeap(h,3);
    insertIntoMaxHeap(h,2);
    insertIntoMaxHeap(h,4);
    insertIntoMaxHeap(h,1);
    insertIntoMaxHeap(h,6);
    insertIntoMaxHeap(h,13);
    insertIntoMaxHeap(h,17);
    printHeapArray(h);

    return 0;
}
