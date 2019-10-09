
public class TestaFuncionario2 {
	public static void main(String[] args) {
		Funcionario funcionario1 = new Funcionario();
		Funcionario funcionario2 = new Funcionario();
		
		funcionario1.setNome("Gabriel");
		funcionario1.setSalario(10000);
		
		funcionario2.setNome("Gabriel");
		funcionario2.setSalario(10000);
		
		// 5) diferentes
		System.out.println("Os funcionários são: "+ ((funcionario1 == funcionario2) ? "Iguais" : "Diferentes"));
		
		funcionario1 = funcionario2;
		
		// 6) iguais, dois, dois.
		System.out.println("Os funcionários são: "+ ((funcionario1 == funcionario2) ? "Iguais" : "Diferentes"));
		
		
	}
}
