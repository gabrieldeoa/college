
public class ControlStructure {
	public static void main(String[] args) {
		int i = 0;
		int max = 10;
		
		while(i < max) {
			System.out.println(i + " ");
			i++;
		}
		
		for(int j = 0; j < max*10; j++) {
			if(j >= 10 && j<= 90)
				continue;
			System.out.println(j);
		}
		
		int month = 2;
		
		switch(month) {
			case 1: System.out.println("JAN"); break;
			case 2: System.out.println("FEV"); break;
			case 3: System.out.println("MAR"); break;
			case 4: System.out.println("APR"); break;
			case 5: System.out.println("MAY"); break;
			case 6: System.out.println("JUN"); break;
		}
		
	}

}
