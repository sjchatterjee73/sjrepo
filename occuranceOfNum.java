import java.util.*;

class occuranceOfNum{
  public static void main(String[] args) {
    Scanner inp = new Scanner(System.in);
    System.out.println("enter size of array:");
    int size = inp.nextInt();
    int [] array = new int[size];
    System.out.println("enter array elements:");
    for(int i=0; i<array.length; i++){
      array[i] = inp.nextInt();
    }
    System.out.println("enter test cases:");
    int tc = inp.nextInt();

    call(array, tc);
  }

  public static void call(int [] array, int tc){
    Scanner inp = new Scanner(System.in);
    int count = 0;
    while(tc != 0){
      System.out.println("enter number to check:");
      int num = inp.nextInt();
      for(int i=0; i<array.length; i++){
        if(num == array[i]){
          count++;
        }
      }
      if(count == 0){
        System.out.println("NOT PRESENT");
      }else{
        System.out.println(count);
        count = 0;
      }
      tc--;
    }
  }
}
