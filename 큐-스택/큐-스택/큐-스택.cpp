#include <iostream>

template <typename T>
class Node { //단순연결리스트 상속시켜서 다중연결리스트등을 만들수 있을듯
public:
    T mydata;
    Node* nextNode = NULL;

    Node(T data) {
    this->nextNode = new Node;
    this->nextNode->mydata = data;
    //std::cout << data;
}
      Node() {
      }

      void add(T data) {
          Node* temp = this;
          for (;;) {
              if (temp->nextNode == NULL) {
                  temp->nextNode = new Node;
                  temp->nextNode->mydata = data;
                  break;
              }
              else {
                  temp = temp->nextNode;
              }
          }
      }

      int length() { //리스트크기 반환
          int size = 0;
          Node* temp = this->nextNode;
          if (temp == NULL) { return NULL; }
          for (;;) {
              if (temp->nextNode == NULL) { //메모리 문제 발생
                  size++;
                  break;
              }
              else {
                  size++;
                  temp = temp->nextNode;
              }
          }
          return size;
      }

      T out(int num) {

          Node* temp = this;

          if (temp->nextNode == NULL) { return NULL; }
          
          for (int i = 0; i < num; i++) {
              temp = temp->nextNode;
          }
          
          return temp->mydata;


      }

      void delete_num(int num) {
          if (num > this->length()) { return; }
          else {
              Node* temp = this;
              for (int i = 1; i < num; i++) {
                  temp = temp->nextNode;
              }
              //delete temp->nextNode;
              //temp->nextNode = temp->nextNode->nextNode; temp->nextNode->nextNode != NULL;
              if (num == this->length()) {
                  delete temp->nextNode;
                  temp->nextNode = NULL;
              }
              else if (temp->nextNode->nextNode != NULL) {
                  Node* A = temp->nextNode->nextNode;
                  delete temp->nextNode;
                  temp->nextNode = A;
                  //포인터 딜리트 처리 필요 완료
              }
              
          }
      }

      void print_data() {
          Node* temp = this->nextNode;
          if (temp == NULL) {
              return;
          }

          for (;;) {
              if (temp->nextNode == NULL) {
                  std::cout << temp->mydata;
                  break;
              }
              else {
                  std::cout << temp->mydata;
                  temp = temp->nextNode;
              }
          }
      }

};

template <typename T>
class  queue : public Node<T>
{

public:
    queue(T num) : Node<T>(num){
       
    }

    T out() {
        int temp_length = Node<T>::length();
        T temp_data = Node<T>::out(temp_length);
        Node<T>::delete_num(temp_length);
        return temp_data;
        
    }

};

template <typename T>
class  stack : public Node<T>
{

public:
    stack(T num) : Node<T>(num) {

    }

    T out() {
        
        T temp_data = Node<T>::out(1);
        Node<T>::delete_num(1);
        return temp_data;

    }

};

int main()
{

    stack<int> k(5);
    k.add(6);
    k.add(7);
    k.add(8);
    k.print_data();
   
}