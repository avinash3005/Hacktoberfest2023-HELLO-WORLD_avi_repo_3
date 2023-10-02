import java.util.ArrayList;
import java.util.Scanner;

public class SubarrayIndex {
	static void countSetBit(int[] arr, int n)
	  {
	    int c = 0, i;
	 
	    for (i = 0; i < n; i++) {
	 
	      int x = arr[i];
	      while (x > 0) {
	        int l = x % 10;
	        if ((x & 1) == 1)
	          c++;
	        x /= 2;
	      }
	      arr[i] = c;
	      c = 0;
	    }
	  }
	static void PrintIndex(int[] arr, int N, int X,
            ArrayList<Integer> v)
	{

		int i = 0, j = 0, currSum = arr[0];
		while (j < N && i < N) {
			if (currSum == X) {

				v.add(i + 1);
				v.add(j + 1);

				j++;
				if (j < N)
					currSum += arr[j];
			}

			else if (currSum < X) {
				j++;
		if (j < N)
			currSum += arr[j];
			}

			else {
				currSum -= arr[i];
				i++;
			}
		}
		}

		// Main Driver
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int v[] = new int[n];
		int N = v.length;
		for(int i = 0; i<N; i++) {
			v[i]=sc.nextInt();
		}
		
		int X = sc.nextInt();
	 
	    countSetBit(v, N);
	 
	    ArrayList<Integer> ans = new  ArrayList<Integer>();
	 
	    PrintIndex(v, N, X, ans);
	 
	    for (int i = 0; i < ans.size() - 1; i += 2)
	      System.out.print("(" + ans.get(i) + " " + ans.get(i + 1)
	                       + ")"
	                       + " ");


	}

}
