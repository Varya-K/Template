#pragma once
#include <stdexcept>
#include <memory>


template <typename T> class List 
{
public:

	List() :count(0){}
	~List() {}
	void push_front(const T& value) {
		head = std::make_shared<node>(value, std::move(head));
		count++;
	}

	void push_back(const T& value){//Добавить элемент в конец списка
		insert(count, value);
	}
	void insert(int index, const T& value) {//Добавить элемент на место i
		if (index == 0) {
			push_front(value);
			return;
		}
		auto curr_node = head;
		while (index > 1 && curr_node != nullptr) {
			curr_node = curr_node->next;
			index--;
		}
		if (curr_node != nullptr) {
			curr_node->next = std::make_shared<node>(value, std::move(curr_node->next));
			count++;
		}
	}
	T& front() {
		return head->data;
	}
	T& get_elem(int index) {
		auto curr_node = head;
		while (index > 0 && curr_node != nullptr) {
			index--;
			curr_node = curr_node->next;
		}
		if (curr_node != nullptr) return curr_node->data;
		throw std::out_of_range("index is out of range");
	}
	T& operator[](int index) {
		return get_elem(index);
	}
	T& back() {
		return get_elem(count);
	}
	void pop_front() {
		head = std::move(head->next);
		count--;
	}
	void delete_elem(int index) {
		if (index == 0) {
			pop_front();
		}
		auto curr_node = head;
		auto prev_node = head;
		while (index > 0 && curr_node != nullptr) {
			index--;
			prev_node = curr_node;
			curr_node = curr_node->next;
		}
		if (curr_node != nullptr) {
			prev_node->next = std::move(curr_node->next);
			count--;
		}
		
	}
	void pop_back() {
		delete_elem(count);
	}
	int get_count() const {
		return count;
	}
	void clear() {
		head = nullptr;
		count = 0;
	}
private:
	struct node
	{
		std::shared_ptr<node> next;
		T data;
		node(const T& data, std::shared_ptr<node> next) : data(data), next(next) {}
	};
	std::shared_ptr<node> head;
	int count;
};


