#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int left(int i) {return 2*i + 1;}
int right(int i) {return 2*i + 2;}
int parent(int i) {return (i-1)/2;}

void sift_down(vector<int>& a, int i,int n)     // shifts down a[i] to its correct position in the heap.
{
    while(left(i) < n)
    {
        int least = left(i);
        if(right(i) < n && a[right(i)] < a[least]) least = right(i);

        if(a[least] >= a[i]) break;
        
        swap(a[i],a[least]);
        i = least;
    }
}

void sift_up(vector<int>& a, int i)     // shifts up a[i] to its correct position in the heap.
{
    while(i>0)
    {
        if(a[i] < a[parent(i)]) swap(a[i],a[parent(i)]);
        i = parent(i);
    }
}

void insert(vector<int>& a, int k)
{
    a.push_back(k);
    sift_up(a,a.size()-1);
}

void extract_min(vector<int>& a)
{
    cout << a[0] << endl;
    swap(a[0],a[a.size()-1]);
    a.pop_back(); 
    sift_down(a,0,a.size());
}

void heap_sort(vector<int>& a)
{
    int n = a.size();
    for(int i=(n/2)-1;i>=0;i--)     //  OR  for(int i=0;i<n;i++)    // converting array into binary heap
    sift_down(a,i,n);                 //      sift_up(a,i);
    // but in sift_down, we can't move the large number of leaves (2^H, H=height of tree) any lower because they're already at the bottom.
    // so, the operations taken for sifting down the leaf nodes = 0. therefore, apply sift_down only on the non-leaf nodes, which are
    // 2^H - 1 = floor((n-1)/2) = n/2;

    for(int i=n-1;i>=1;i--)
    {
        swap(a[i],a[0]);    // place all the root nodes(min elements) at the last of array // sorted in descending order.
        sift_down(a,0,i);     // heapify the new tree with last element as the root node // call sift_down on the new sized heap
                                // (excluding the swapped min element)
    }
}

void display(vector<int>& a)
{
    for(auto element : a)
    cout << element << " ";
    cout << endl;
}

int main()
{
    vector<int> a = {3,5,7,2};

    for(int i=0;i<a.size();i++)
    sift_up(a,i);
    display(a);

    insert(a,11);
    display(a);
    
    extract_min(a);
    display(a);

    heap_sort(a);
    display(a);


    // priority_queue<int,vector<int>,greater<int>> q;
    // q.push(2);
    // q.push(5);
    // q.push(10);
    // q.push(17);

    // cout << q.top() << '\n';
    // q.pop();
    // cout << q.top() << '\n';


}
