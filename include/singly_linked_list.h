#pragma once

#include <cstddef>
#include <stdexcept>
#include <utility>
#include <vector>

template <typename T>
struct SNode {
    T value;
    SNode* next;

    explicit SNode(const T& v, SNode* n = nullptr) : value(v), next(n) {}
};

template <typename T>
class SLinkedList {
public:
    SLinkedList();
    ~SLinkedList();
    SLinkedList(const SLinkedList& other);
    SLinkedList& operator=(const SLinkedList& other);

    void push_front(const T& value);
    void push_back(const T& value);
    bool pop_front();
    bool pop_back();

    T& front();
    const T& front() const;
    std::size_t size() const noexcept;
    bool empty() const noexcept;
    bool contains(const T& value) const;
    std::vector<T> to_vector() const;
    void clear();

private:
    SNode<T>* head_;
    std::size_t size_;
};

template <typename T>
SLinkedList<T>::SLinkedList() : head_(nullptr), size_(0) {}

template <typename T>
SLinkedList<T>::~SLinkedList() {
//TODO: Implement the destructor for the SLinkedList class
    //delete[] newNode;
    delete[] head_;
}

template <typename T>
SLinkedList<T>::SLinkedList(const SLinkedList& other) : head_(nullptr), size_(0) {
//TODO: Implement the copy constructor for the SLinkedList class
    SNode<T>* tempNode = other.head_;
    while(tempNode != nullptr) {
        push_back(tempNode->value);
        tempNode = tempNode->next;
    }
}

template <typename T>
SLinkedList<T>& SLinkedList<T>::operator=(const SLinkedList& other) {
//TODO: Implement the assignment operator for the SLinkedList class
    if (this != &other) {
        while(!empty()) {
            pop_front();
        }
        SNode<T>* tempNode = other.head_;
        while (tempNode != nullptr) {
            push_back(tempNode->value);
            tempNode = tempNode->next;
        }
    }

    return *this;
}

template <typename T>
void SLinkedList<T>::push_front(const T& value) {
// TODO: Implement the push_front function for the SLinkedList class
    SNode<T>* newNode = new SNode<T>(value);
    newNode->value = value;
    newNode->next = head_;
    head_ = newNode;
    
}

template <typename T>
void SLinkedList<T>::push_back(const T& value) {
// TODO: Implement the push_back function for the SLinkedList class
    SNode<T>* newNode = new SNode<T>(value);
    SNode<T>* tempNode;
    newNode->value = value;
    tempNode = head_;
    if(tempNode != nullptr) {
        while(tempNode->next != nullptr) {
            std::cout << "VALUE: " << tempNode->value << std::endl;
            tempNode = tempNode->next;
        }
        tempNode->next = newNode;
    }
    else {
        head_ = newNode;
        //tempNode = newNode;
    }

}

template <typename T>
bool SLinkedList<T>::pop_front() {
// TODO: Implement the pop_front function for the SLinkedList class
    if(empty()) { return false;}
    else {
        SNode<T>* tempNode;
        tempNode = head_;
        head_ = head_->next;
        delete tempNode;
        return true;
    }
}

template <typename T>
bool SLinkedList<T>::pop_back() {
// TODO: Implement the pop_back function for the SLinkedList class
    if(empty()) { return false;}
    else {    
        SNode<T>* tempNode;
        SNode<T>* remNode;

        tempNode = head_;
        while(tempNode->next->next != nullptr) {
            tempNode = tempNode->next;
        }
        remNode = tempNode->next;
        delete remNode;
        tempNode->next = nullptr;
        return true;
        
    }
    
}

template <typename T>
T& SLinkedList<T>::front() {
// TODO: Implement the front function for the SLinkedList class
    if (empty()) {
        throw std::out_of_range("SLinkedList is empty");
    }
    return head_->value;
}

template <typename T>
const T& SLinkedList<T>::front() const {
    if (empty()) {
        throw std::out_of_range("SLinkedList is empty");
    }
    return head_->value;
}

template <typename T>
std::size_t SLinkedList<T>::size() const noexcept {
// TODO: Implement the size function for the SLinkedList class
    SNode<T>* tempNode;
    tempNode = head_;
    int counter = 1;
    if(empty()) {
        return 0;
    }
    else {
        while(tempNode->next != nullptr) {
            counter++;
            tempNode = tempNode->next;
        }
    }
    return counter;
}

template <typename T>
bool SLinkedList<T>::empty() const noexcept {
// TODO: Implement the empty function for the SLinkedList class
    if(head_ == nullptr) { return true; }
    return false;
}

template <typename T>
bool SLinkedList<T>::contains(const T& value) const {
// TODO: Implement the contains function for the SLinkedList class
    SNode<T>* tempNode;
    tempNode = head_;
    int counter = 0;
    while(counter < 25) {
        if(tempNode == nullptr) {
            //delete[] tempNode;
            return false;
        }
        if(tempNode->value == value) {
            //delete[] tempNode;
            return true;
        }
        std::cout << "TEMPVALUE: " << value << ", " << tempNode->value << std::endl;
        tempNode = tempNode->next;
        counter++;
    }
    return false;
}
// 20 -> 10 -> 30 -> nullptr

template <typename T>
std::vector<T> SLinkedList<T>::to_vector() const {
    std::vector<T> values;
    values.reserve(size_);
    for (SNode<T>* current = head_; current != nullptr; current = current->next) {
        values.push_back(current->value);
    }
    return values;
}

template <typename T>
void SLinkedList<T>::clear() {
//TODO: Implement the clear function for the SLinkedList class
}
