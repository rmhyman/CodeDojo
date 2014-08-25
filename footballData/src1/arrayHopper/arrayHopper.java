package arrayHopper;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class arrayHopper {	
	/*
	 * Array Hopper using Greedy Approach
	 */
	public void minHopsGreedy(List<Integer> array){
		ArrayList<Integer> result = new ArrayList<>();
		int start = 0;
		int end = array.size();
		
		if(end == 0 || array.get(0) == 0){
			System.out.println("failure");
			return;
		}
		
		result.add(0);
		
		while(start + array.get(start) < end){
			int nextElem = -1;
			int max = Integer.MIN_VALUE;
			for(int i = start + 1; i <= start+ array.get(start); i++){
				int maxPossible = i + array.get(i);
				
				if(maxPossible > max){
					max = maxPossible;
					nextElem = i;
				}
				
			}
			
			if(nextElem == -1 || array.get(nextElem) == 0){
				System.out.println("failure");
				return;
			}
			
			result.add(nextElem);
			start = nextElem;			
		}
		
		for(int i: result){
			System.out.print(i +", ");
		}
		
		System.out.println("out");
		
	}
	
	//@Test
	public void testArrayHopper(){
		// int[] arr = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};

		int[] arr = {5, 6, 0, 4, 2, 4, 1, 0, 0, 4}; 

		// Convert integer array to arraylist
		List<Integer> inp = new ArrayList<>();
		for(int i: arr){
			inp.add(i);
		}
		
		minHopsGreedy(inp);
	}
	
	/*
	 * Naive approach using recursion
	 */
	public int minHops(int[] arr, int start, int end){
	
		// Base case when source and destination are same
		if(start == end){
			return 0;
		}
		
		// When nothing is reachable from the given source 
		if(arr[start] == 0){
			return Integer.MAX_VALUE;
		}
		
		int min = Integer.MAX_VALUE;
		
		for(int i = start+1; i <= end && i <= start + arr[start]; i++){
			int jumps = minHops(arr,i , end);
			if(jumps != Integer.MAX_VALUE && jumps +1 < min){
				min = jumps+1;
			}
		}
		
		return min;
	}
	
	public static void main (String[] args){
		arrayHopper a = new arrayHopper();
		a.testArrayHopper();
	}
	 
}