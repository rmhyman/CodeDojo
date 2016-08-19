/*Given a string, find the longest substring that contains only two unique characters. 
 * For example, given "abcbbbbcccbdddadacb" the longest substring that contains 2 unique
 * characters is "bcbbbbcccb".
 */

package longestSub;

import java.util.Scanner;

public class LongestString {
	
	static String longestSub(String s, int len){
		
		/* c1 and c2 - 1st and 2nd unique char
		 * sp1 and sp2 - 1st and 2nd position of c1 and c2
		 * ep1 and ep2 - last position of c1 and c2
		 * ans_sp and ans_ep - starting and ending point of overall
		 * cur_ans_sp and cur_ans_ep - starting and ending point of current required substring at an instant 
		*/
		
		char c1, c2;
		int sp1, sp2;
		int ep1, ep2;
		
		int ans_sp, ans_ep;
		int cur_ans_sp, cur_ans_ep;
		
		sp2 = ep2 = -1;
		c2 = (char) -1;
		
		c1 = s.charAt(0);
		sp1 = ep1 = 0;
		
		ans_sp = ans_ep = 0;
		cur_ans_sp = cur_ans_ep = 0;
		
		for(int i = 1; i < len; i++){
			if(s.charAt(i) != c1 && c2 == -1){
				c2 = s.charAt(i);
				sp2 = ep2 = i;
				cur_ans_ep++;
			}else if(s.charAt(i) == c1){
				c1 = c2;
				sp1 = sp2;
				ep1 = ep2;
				c2 = s.charAt(i);
				sp2 = ep1 + 1;
				ep2 = i;
			}else if(s.charAt(i) == c2){
				ep2 = i;
				cur_ans_ep++;
			}else if(s.charAt(i) != c1 && s.charAt(i) != c2){
				c1 = c2;
				sp1 = ep1 + 1;
				ep1 = ep2;
				c2 = s.charAt(i);
				sp2 = ep2 = i;
				cur_ans_sp = sp1;
				cur_ans_ep = ep2;
			}
			if(cur_ans_ep - cur_ans_sp + 1 > ans_ep - ans_sp + 1){
				ans_sp = cur_ans_sp;
				ans_ep = cur_ans_ep;
			}
		}
		char[] temp = s.toCharArray();
		for(int i = 0; i < ans_ep - ans_sp + 1; i++){
			temp[i] = s.charAt(ans_sp + i);
		}
		String subString = new String(temp);
		
		return subString;
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Enter String.");
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		
		String result = longestSub(s, s.length());
		System.out.println(result);
	}

}
