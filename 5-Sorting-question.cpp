#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

void bubbleSort(int *a,int length);     //Performing bubble sorting method with ascending order
void selectionSort(int *a,int length);  //Performing selection sorting method with ascending order
void quickSort(int *a,int length);      //Performing quick sorting method with ascending order
void heapSort(int *a,int length);       //Performing heap sorting method with ascending order
void mergeSort(int *a,int length);      //Performing merge sorting method with ascending order


int main()
{
    srand(time(NULL));
    int length = 200;
    int *ori= (int*)malloc(sizeof(int)*length);
    int *a= (int*)malloc(sizeof(int)*length);

    cout << "Prior : " << endl;
    for(int i=0; i<length; i++) {
        ori[i]=rand()%500+1;
        a[i]=ori[i];
        cout << ori[i] << " ";
    }
    cout << endl << endl;

    //bubbleSort
    cout << "bubbleSort:" << endl;
    bubbleSort(a,length);
    for(int i= 0 ; i <length; i++) {
        cout << a[i] << " ";
        a[i]=ori[i];
    }
    cout << endl << endl;

    //selectionSort
    cout << "selectionSort:" << endl;
    selectionSort(a,length);
    for(int i= 0 ; i <length; i++) {
        cout << a[i] << " ";
        a[i]=ori[i];
    }
    cout << endl << endl;

    //quickSort
    cout << "quickSort:" << endl;
    quickSort(a,length);
    for(int i= 0 ; i <length; i++) {
        cout << a[i] << " ";
        a[i]=ori[i];
    }
    cout << endl << endl;

    //heapSort
    cout << "heapSort:" << endl;
    heapSort(a,length);
    for(int i= 0 ; i <length; i++) {
        cout << a[i] << " ";
        a[i]=ori[i];
    }
    cout << endl << endl;

    //mergeSort
    cout << "mergeSort:" << endl;
    mergeSort(a,length);
    for(int i= 0 ; i <length; i++) {
        cout << a[i] << " ";
        a[i]=ori[i];
    }
    cout << endl << endl;

    return 0;
}

void bubbleSort(int *a, int length){//兩兩找，大的往右放
    int i, j;
    for(i=0;i<length-1;i++){//換length 次
        for(j=0 ; j<length-1-i ; j++){//每個掃一遍
            if(a[j] > a[j+1]){
                int temp;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void selectionSort(int *a,int length){//找最小的放到最左邊
    for(int i=0 ; i<length ; i++){
        int min_Index = i;
        for(int j = i+1; j < length ; j++){
            if(a[j]<a[min_Index]){
                min_Index = j;
            }
        }
        int temp;
        temp = a[i];
        a[i] = a[min_Index];
        a[min_Index] = temp;
    }
}

void quickSort(int *a,int length){//先找出一個標準值在分左右個別找標準值直到排序完成
    int mid;//標準值
    int temp,i,j;
    int left=0;//左指標
    int right=length-1;//右指標
    if(left < right){
        i = left+1;
        j = right;
        mid = a[left];
        while(i<j){
            while(a[i] <= mid)i++;
            while(a[j] > mid)j--;
            if(i < j){//swap
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        if(a[left]>a[j]){//swap a[j]為標準值
            temp = a[left];
            a[left] = a[j];
            a[j] = temp;
        }
        quickSort(a,j-left);//從a開始 ，j-left = 左段長度
        quickSort(a+j-left+1,right-j);//從a+ 左段長度+1 開始，right-j=右段長度
    }
}

void heapSort(int *a,int length){
    int root,maxNode ;
    int leftChild,rightChild;
    int temp;
    for(int i =  length/2 -1 ; i >=0 ; i--){//Max Heap
        root=i;
        maxNode=-1;
        while(1){
            leftChild=root*2+1;
            rightChild=root*2+2;
            if(leftChild < length && (a[leftChild] > a[root]))//左節點還沒跑到底，左子元素>根節點
                maxNode = leftChild; //最大值者 =左子元素
            else
                maxNode = root;//否則=根節點
            if(rightChild < length && (a[rightChild] > a[maxNode]))//右節點還沒跑到底，右子元素>根節點
                maxNode = rightChild; //最大值者 =右子元素

            if(maxNode != root){//如果最大值者不是根節點
                //swap
                temp = a[root];
                a[root] = a[maxNode];
                a[maxNode] = temp;
                root = maxNode;
            }
            else
                break;
        }
    }
    for(int i = length -1 ; i >0 ; i--){//sort
        root=0;
        maxNode=-1;
        //swap
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
            while(1){
                leftChild=root*2+1;
                rightChild=root*2+2;
                if(leftChild < i && (a[leftChild] > a[root]))
                    maxNode = leftChild;
                else
                    maxNode = root;
                if(rightChild < i && (a[rightChild] > a[maxNode]))
                    maxNode = rightChild;

                if(maxNode != root){
                    temp = a[root];
                    a[root] = a[maxNode];
                    a[maxNode] = temp;
                    root = maxNode;
                }
                else
                    break;
            }
    }
}
void mergeSort(int *a,int length){
    int i, leftMin, leftMax, rightMin, rightMax, next;
    int temp[length];
    for(int i = 0;i < length;++i) temp[i] = 0;

    for(int i = 1; i < length; i *= 2){//陣列二分直到剩一個或兩個元素
        for(leftMin = 0; leftMin < length - i; leftMin = rightMax){
            rightMin = leftMax = leftMin + i;
            rightMax = leftMax + i;
            if(rightMax > length)
                rightMax = length;
            next = 0;
            //合併
            while(leftMin < leftMax && rightMin < rightMax)//左右陣列哪個小就先放進大陣列
                temp[next++] = a[leftMin] > a[rightMin]
                              ? a[rightMin++]
                              : a[leftMin++];
            while(leftMin < leftMax)
                a[--rightMin] = a[--leftMax];
            while(next > 0 )
                a[--rightMin] = temp[--next];
		}
	}
}

