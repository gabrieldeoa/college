import java.util.ArrayDeque;

public class TestaArray {

	public static void main(String[] args) {
		int[] arrayDeIdades = new int[5];
		
		arrayDeIdades[0]=25;
		arrayDeIdades[1]=35;
		arrayDeIdades[2]=15;
		arrayDeIdades[3]=45;
		arrayDeIdades[4]=12;
		
		for (int i = 0; i < arrayDeIdades.length; i++) {
			System.out.println(i);
			System.out.println("Nessa posição tem o valor "+arrayDeIdades[i]);
		}
		
		//Foreach
		for(int i:arrayDeIdades){
			System.out.println(i);
		}
	}

}
