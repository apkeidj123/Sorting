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

void bubbleSort(int *a, int length){//����A�j�����k��
    int i, j;
    for(i=0;i<length-1;i++){//��length ��
        for(j=0 ; j<length-1-i ; j++){//�C�ӱ��@�M
            if(a[j] > a[j+1]){
                int temp;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void selectionSort(int *a,int length){//��̤p�����̥���
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

void quickSort(int *a,int length){//����X�@�ӼзǭȦb�����k�ӧO��зǭȪ���Ƨǧ���
    int mid;//�зǭ�
    int temp,i,j;
    int left=0;//������
    int right=length-1;//�k����
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
        if(a[left]>a[j]){//swap a[j]���зǭ�
            temp = a[left];
            a[left] = a[j];
            a[j] = temp;
        }
        quickSort(a,j-left);//�qa�}�l �Aj-left = ���q����
        quickSort(a+j-left+1,right-j);//�qa+ ���q����+1 �}�l�Aright-j=�k�q����
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
            if(leftChild < length && (a[leftChild] > a[root]))//���`�I�٨S�]�쩳�A���l����>�ڸ`�I
                maxNode = leftChild; //�̤j�Ȫ� =���l����
            else
                maxNode = root;//�_�h=�ڸ`�I
            if(rightChild < length && (a[rightChild] > a[maxNode]))//�k�`�I�٨S�]�쩳�A�k�l����>�ڸ`�I
                maxNode = rightChild; //�̤j�Ȫ� =�k�l����

            if(maxNode != root){//�p�G�̤j�Ȫ̤��O�ڸ`�I
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

    for(int i = 1; i < length; i *= 2){//�}�C�G������Ѥ@�өΨ�Ӥ���
        for(leftMin = 0; leftMin < length - i; leftMin = rightMax){
            rightMin = leftMax = leftMin + i;
            rightMax = leftMax + i;
            if(rightMax > length)
                rightMax = length;
            next = 0;
            //�X��
            while(leftMin < leftMax && rightMin < rightMax)//���k�}�C���Ӥp�N����i�j�}�C
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

