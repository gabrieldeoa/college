
public class TestaFuncionario {
	public static void main(String[] args) {
		Funcionario func1,func2;
		func1 = new Funcionario();
		func1.setNome("William");
		func1.setSalario(4000);
		func1.setDepartamento("vendas");
		System.out.println("O salário do "+func1.getNome()+" é "
		+func1.getSalario());
		func1.aumentarSalario(30);
		System.out.println("O salário do "+func1.getNome()
		+" depois do aumento ficou em "
				+func1.getSalario());
		func1.demite();
		String mensagem = (func1.isAtivo()?"Está na empresa":"Foi demitido!!");
		System.out.println("Status de "+func1.getNome()+": "+mensagem);
		
		int idade = 18;
		String status = (idade>=18)?"Já é um homenzinho":"Ainda é garoto";
		System.out.println(status);
		
		int mes = 2;
		int semestre = (mes<=6)?1:2;
		
		
		
		func2 = new Funcionario();
		func2.setNome("Breno");
		func2.setSalario(3000);
		func2.setDepartamento("Recursos humanos");
		System.out.println("O salário do "+func2.getNome()+" é "
				+func2.getSalario());
		
		System.out.println("Hora do macete!!!!\n\n");
		func1.mostraDados();
		System.out.println("################################");
		func2.mostraDados();
		
		
	}
}
