/*
 * 155.cpp
 *
 *  Created on: Sep 12, 2018
 *      Author: frank
 */
#include <stack>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

// 用multiset来排序的实现方法

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
    	stack_.push(x);
    	sorted_.insert(x);
    }

    void pop() {
    	sorted_.erase(sorted_.find(stack_.top()));
    	stack_.pop();
    }

    int top() {
    	return stack_.top();
    }

    int getMin() {
    	return *sorted_.begin();
    }
private:
    stack<int> stack_;
    std::multiset<int> sorted_; // 用来排序
};



