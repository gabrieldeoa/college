import java.util.Arrays;

public class TestaFuncionario2 {
	public static void main(String[] args) {
		Funcionario func1,func2;
		func1 = new Funcionario();
		func1.setNome("Wiliam");
		func1.setSalario(4000);
		func1.setDepartamento("vendas");
		func1.aumentarSalario(50);
		func1.getDataDeNascimento().setDia("02");
		func1.getDataDeNascimento().setMes("02");
		func1.getDataDeNascimento().setAno("1994");
		
		func2 = new Funcionario();
		func2.setNome("Raine");
		func2.setSalario(6000);
		func2.setDepartamento("Recursos humanos");
		func2.getDataDeNascimento().setDia("30");
		func2.getDataDeNascimento().setMes("04");
		func2.getDataDeNascimento().setAno("1999");
		func2.demite();
		
		Funcionario func3 = new Funcionario();
		func3.setNome("Luan");
		func3.setSalario(8000);
		func3.setDepartamento("Consultoria gramatical");
		func3.getDataDeNascimento().setDia("26");
		func3.getDataDeNascimento().setMes("06");
		func3.getDataDeNascimento().setAno("1995");
		
		Funcionario[] funcionarios = new Funcionario[5];
		funcionarios[0] = func1;
		funcionarios[1] = func2;
		funcionarios[2] = func3;
		funcionarios[3] = new Funcionario("Rafael", "06", "11", "1974");
		
		Funcionario func5 = new Funcionario("Chuverinho", "17", "04", "1996");
		funcionarios[4] = func5;
		func5.setSalario(9000);
		
		
		
		/*for (int i = 0; i < funcionarios.length; i++) {
			if(funcionarios[i]!=null){
				System.out.println("##############");
				funcionarios[i].mostraDados();
			}
		}*/
		
		//Funcionario[] funcionarios2 = new Funcionario[funcionarios.length+1];
		/*for (int i = 0; i < funcionarios.length; i++) {
			funcionarios2[i] = funcionarios[i];
		}
		funcionarios = funcionarios2;*/ //estrutura, novoTamanho
		//funcionarios = Arrays.copyOf(funcionarios, funcionarios.length+1);
		funcionarios = Arrays.copyOf(funcionarios, 6);
		funcionarios[5] = new Funcionario("Heloíse", "19", "04", "1994");
		
		
		for(Funcionario func:funcionarios){
			System.out.println("###################");
			func.mostraDados();
		}
		
		/*func1.mostraDados();
		//System.out.println(func1.getDataDeNascimento().getDataCompletaBr());
		System.out.println("########################");
		func2.mostraDados();
		//System.out.println(func2.getDataDeNascimento().getDataCompletaBr());
		System.out.println("########################");
		func3.mostraDados();
		//System.out.println(func3.getDataDeNascimento().getDataCompletaBr());
		*/
		
		
		/*if(func1==func2)
			System.out.println("Iguais");
		else
			System.out.println("Diferentes");
		
		if(func1.equals(func2))
			System.out.println("Iguais");
		else
			System.out.println("Diferentes");*/
		
	}
}
