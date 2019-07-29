package graph;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Graph{
	List<Integer> [] list;
	int node;
	
	@SuppressWarnings("unchecked")
	void initialize(int size) {
		list = new ArrayList[size];
		for(int i=0; i<list.length; i++) {
			list[i] = new ArrayList<Integer>();
		}
	}
	
	void printNodesWithTheirEdges() {
		for(int i=1; i<list.length; i++) {			
			System.out.println(i+": "+list[i]);
		}
	}
}
public class AdjacencyList {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Graph object = new Graph();		
		
		
		int nodes = scanner.nextInt();
		int edges = scanner.nextInt();

		object.initialize(nodes+1);
		System.out.println("Size of Adjancency List: "+object.list.length);
		
		for(int i=0; i<edges; i += 1) {
			int x = scanner.nextInt();
			int y = scanner.nextInt();
			
			List<Integer> temp = object.list[x];
			temp.add(y);
			object.list[x] = temp;
		}
		
		object.printNodesWithTheirEdges();
		scanner.close();
		
	}
}
