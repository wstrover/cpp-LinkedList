#include <iostream>
#include "LinkedList.h"
using std::cout;
using std::endl;

LinkedList::LinkedList() {
	head_ = nullptr;
}

LinkedList::~LinkedList() {
	while (head_ != nullptr) {
		LNode* tmp = head_;
		head_ = head_->next_;
		free(tmp);
		tmp = nullptr;
	} 
	head_ = nullptr;
}

void LinkedList::print() const {
	LNode* tmp = head_;
	while(tmp != nullptr) {
		cout << (tmp->data_) << " ";
		tmp = tmp->next_;
	}
	cout << endl;
}

LNode* LinkedList::find(int t) const {
	LNode* tmp = head_;
	while (tmp != nullptr) {
		if (tmp->data_ == t) return tmp;
		tmp = tmp->next_;
		
	}
	return nullptr; // stub
}

void LinkedList::insert_head(int t) {
	LNode* tmp = new LNode;
	
	tmp->data_ = t;
	tmp->next_ = head_;
	tmp->prev_ = nullptr;
	if (head_ != nullptr) head_->prev_ = tmp;
	head_ = tmp;
	
}

void LinkedList::insert_after(LNode* location, int t) {
	if (location->next_ == nullptr){
		LNode* newN = new LNode;
		newN->prev_ = location;
		newN->data_ = t;
		newN->next_ = nullptr;
		location->next_ = newN;
	} else {
		LNode* afloctmp = location->next_;
		LNode* newN = new LNode;
		newN->prev_ = location;
		newN->data_ = t;
		newN->next_ = afloctmp;
		afloctmp->prev_ = newN;
		location->next_ = newN;
	}
}

void LinkedList::remove(LNode* location) {
	if (head_ == nullptr || location == nullptr){
		return;
	} 
	if (head_ == location) {
		head_ = location->next_;
		
	} 
	if (location->next_ != nullptr) {
		location->next_->prev_ = location->prev_;
	} 
	if (location->prev_ != nullptr) {
		location->prev_->next_ = location->next_;
	}
	free(location);
}
