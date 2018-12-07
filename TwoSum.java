/*
	TwoSum:
	array: [1,2,3,4,5,6];
	target: 7.

algorithm:
	1. store all array elements, in stack, in reverse order, except the first index
		such that, stack will become: 2,3,4,5,6;
	
	2. iterate a loop, 0 to upto the length of array..
		2.1 peek top elements from stack, check whether (i-th elemnt + peeked elemnt) == target, or not
			2.1.2 if it is equal to target, store the value of i and (array.length - stack.size()), into a list/map;
			2.1.2 pop the top elements from stack, and push it in the last of stack
	3. pop the first element.
	
	4. repeat, step-2 and step-3, until stack becomes empty.

tag: Medium
Asked In: Amazon
*/

import java.util.*;

class Stack{
	Stack next;
	int data;
	
	public Stack(int data){
		this.data = data;
		next = null;
	}
}

class Driver{
	Stack head = null;
	ArrayList<String> list = new ArrayList<String>();
	
	void push(int data){
		Stack newitem = new Stack(data);
		if(head == null){
			head = newitem;
		}else{
			newitem.next = head;
			head = newitem;
		}
		return;
	}
	
	int getStackSize(){
		Stack temp = head;
		int count=0;
		while(temp != null){
			count++;
			temp = temp.next;
		}
		return count;
	}
	void pushAtEnd(int data){
		Stack newitem = new Stack(data);
		if(head == null){
			head = newitem;
		}else if(head.next == null){
			head.next = newitem;
		}else{
			Stack temp = head;
			while(temp.next != null){
				temp = temp.next;
			}
			temp.next = newitem;
		}
		return;
	}
	boolean isEmpty(){
		return (head == null);
	}
	int peek(){
		return head.data;
	}
	int pop(){
		int temp = head.data;
		head = head.next;
		return temp;
	}
	void getPairs(int in, int elem, int len, int k){
		int size = getStackSize();
		while(size-- > 0){
			if(!isEmpty()){
				if((elem + peek()) == k){
					String str = "";
					str += in+" - ";
					str += (len - size);
					list.add(str);
				}
			}
			if(!isEmpty()){
				pushAtEnd(pop());
			}
		}
		if(!isEmpty()){
			pop();
		}
	}
	void function(int [] array, int k){
		for(int i=array.length-1; i>=1; i--){
			push(array[i]);
		}
		
		for(int i=0; i<array.length-1; i++){
			getPairs(i, array[i], array.length-1, k);
		}
	}
	void print(){
		System.out.println(list);
	}
}

class TwoSum{
	public static void main(String [] args){
		int [] array = {1,2,3,4,5,6,7,8,9,10};
		int k = 15;
		
		Driver obj = new Driver();
		obj.function(array, k);
		
		obj.print();
	}
}