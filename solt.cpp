#include <iostream>

using namespace std;

//상속과 템플릿 개념을 정렬 알고리즘과 쉽게 배울수 있게 하는 코드 작성.

class sort_main
{
public:
    virtual void sort() = 0;
    virtual void print_array() = 0;
};

template<typename T>
class General_sort:public sort_main{ 
    public:
};

template<typename T>
class Selection_sort:public General_sort<T>{ 
    public:
    static void sort(T* array,int size){
        int i,j;
        T min;
        for(i = 0; i < size; i++){
            min = array[i];
            for(j = 0; j < size; j++){
                if(min < array[j]){
                    min = array[j];
                    array[j] = array[i];
                    array[i] = min;
                }
            }
        }
    }
    static void print_array(T* array,int size){
        sort(array,size);
        for(int i = 0; i < size; i++){
            cout << array[i];
        }
        cout << endl;
    }
};

template<typename T>
class Bubble_sort:public General_sort<T>{ 
    public:
    static void sort(T* array,int size){
        int i;
        bool sort_check = false;
        while(!sort_check){
            sort_check = true;
            for(i = 1; i < size; i++){
                if(array[i]<array[i-1]){
                    sort_check = false;
                    T temp = array[i];
                    array[i] = array[i-1];
                    array[i -1] = temp;
                }
            }
        }
    }
    static void print_array(T* array,int size){
        sort(array,size);
        for(int i = 0; i < size; i++){
            cout << array[i];
        }
        cout << endl;
    }
};

template<typename T>
class InterSection_sort:public General_sort<T>{ 
    public:
    static void sort(T* array,int size){
        int i,j;
        T value;
        for(int i = 2; i < size;i++){
            value = array[i];
            j = i;
            for(;array[j-1] > value; j--){
                array[j] = array[j-1];
            }
            array[j] = value;
        }   
    }
    static void print_array(T* array,int size){
        sort(array,size);
        for(int i = 0; i < size; i++){
            cout << array[i];
        }
        cout << endl;
    }
};

template<typename T>
class Quick_sort:public General_sort<T>{ 
    public:

    static int quick_choose(T* array,int size){
        //여기에 따라 코드 의 성능이 바뀜.
        //근데 난 대충 할거임
        return 0;
    }
    static void sort(T* array,int size){
       int mid = quick_choose(array,size);
       if(size <= 0){return;}
       else{
            int low = 1;
            int high = size - 1;
            while(1){

                while(1){
                    if(array[low] > array[mid]){
                        break;
                    }
                    else if (low >= size-1){break;}
                    else{low++;}
                }
                while(1){
                    if(array[high] < array[mid]){
                        break;
                    }
                    else if (high <= 0 ){break;}
                    else{high--;}
                }
                if(high > low){
                    //swap funtion 필요.
                    T temp = array[low];
                    array[low] = array[high];
                    array[high] = temp;
                }
                else{
                    T temp = array[high];
                    array[high] = array[mid];
                    array[mid] = temp;
                    break;
                }
            }
            sort(array,high-1);
            sort(&array[low],size - low);
            return;
        }
    }

    static void print_array(T* array,int size){
        sort(array,size);
        for(int i = 0; i < size; i++){
            cout << array[i];
        }
        cout << endl;
    }
};

int main(){
    int array[10] = {3,2,4,3,5,4,7,4,2,1};
    //Selection_sort<int>::print_array(array,6);
    //Bubble_sort<int>::print_array(array,6);
    //InterSection_sort<int>::print_array(array,6);
    Quick_sort<int>::print_array(array,10);
}