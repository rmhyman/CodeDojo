package turboSort;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Iterator;
import java.util.Scanner;
import java.util.TreeSet;

import footballData.footballLeague;

public class turboSort {
	
	 public turboSort(String file) throws FileNotFoundException{
			
			Scanner sc = new Scanner(new File(file));
			//Integer data;
			TreeSet<Integer> tree = new TreeSet<Integer>();
			while(sc.hasNext()){
				tree.add(sc.nextInt());
			}
			Iterator<Integer> iterator = tree.iterator();
			System.out.println("Tree set sorted data: ");
			while(iterator.hasNext()){
				System.out.println(iterator.next() + " ");
			}
			
	 }

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		
			Scanner sc = new Scanner(System.in);
			System.out.println("Enter input file name: ");
			String file = sc.nextLine();
			turboSort data = new turboSort(file);
		}

	}


