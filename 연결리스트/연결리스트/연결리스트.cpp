// 연결리스트.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 다시공부하기 연결리스트 만들어보기 시작

#include <iostream>

template <typename T>
class Node { //단순연결리스트 상속시켜서 다중연결리스트등을 만들수 있을듯
    T mydata;
    Node* nextNode = NULL;

public: Node(T data) {
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
          for (;;) {
              if (temp->nextNode == NULL) {
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

      void delete_num(int num) {
          if (num > this->length()) { return; }
          else {
              Node* temp = this;
              for (int i = 1; i < num; i++) {
                  temp = temp->nextNode;
              }
              //delete temp->nextNode;
              //temp->nextNode = temp->nextNode->nextNode; temp->nextNode->nextNode != NULL;
              if (temp->nextNode->nextNode != NULL) {
                  temp->nextNode = temp->nextNode->nextNode;
                  //포인터 딜리트 처리 필요
              }
              else {
                  delete temp->nextNode;
              }
          }
      }

      void print_data() {
          Node* temp = this->nextNode;
          
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

int main()
{
    

    Node<int> k(5);
    k.add(6);
    k.add(7);
    k.add(8);
    k.delete_num(2);
    k.print_data();
    std::cout << k.length();
}
