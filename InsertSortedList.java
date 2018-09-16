import java.util.*;
class Nodes{
	Nodes next;
	int item;
}

class List{
	Nodes head;
	void insert(int data){
		Nodes newItem = new Nodes();
		newItem.item = data;
		newItem.next = null;

		if(head== null){
			newItem.next = head;
			head = newItem;
			return;
		}

		Nodes temp = head;
		Nodes current = null;
		boolean first=false, middle=false, last = false;
		while(temp != null){
			if(temp.next == null && temp != null){
				last = true;
				break;
			}

			current = temp;
			if(temp.item == data){
				middle = true;
				break;
			}
			if(temp.item < data && temp.next.item > data){
				middle = true;
				break;
			}
			if(temp.item > data){
				first =true;
				break;
			}
			temp = temp.next;
		}

		if(first){
			newItem.next = head;
			head = newItem;
			return;
		}

		if(middle){
			newItem.next = current.next;
			current.next = newItem;
			return;
		}

		if(last){
			if(temp.item > data){
				newItem.next = head;
				head = newItem;
				return;
			}
			temp.next = newItem;
			return;
		}
	}
	void display(){
		Nodes temp = head;
		while(temp!=null){
			System.out.print(temp.item+"->");
			temp = temp.next;
		}
		System.out.println();
	}
}
class InsertSortedList{
	public static void main(String[] args) {
		Scanner inp = new Scanner(System.in);
		List obj = new List();
		while(true){
			System.out.println("insert item:");
			int item = inp.nextInt();
			obj.insert(item);
			obj.display();
		}
	}
}
