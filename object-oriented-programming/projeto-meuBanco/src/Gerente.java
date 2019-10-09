
public class Gerente extends Funcionario{
	private int senha;
	private int numeroDeFuncionariosGerenciados;
	
	//reescrita do método getBonificação
	public double getBonificacao() {
		return this.salario*0.2;
	}
	
	public Gerente() {
		super();
	}
	
	public Gerente(String nome,String dia, String mes, String ano, int senha) {
		//Tem que ser a 1ª linha de código
		super(nome, dia, mes, ano);
		this.senha = senha;
	}
	
	public boolean autentica(int senha){
		if(this.senha == senha)
			return true;
		return false;
	}
	
	public int getSenha() {
		return senha;
	}
	public void setSenha(int senha) {
		this.senha = senha;
	}
	
	public void imprimeNome(){
		System.out.println(this.nome);
	}
	public int getNumeroDeFuncionariosGerenciados() {
		return numeroDeFuncionariosGerenciados;
	}
	public void setNumeroDeFuncionariosGerenciados(int numeroDeFuncionariosGerenciados) {
		this.numeroDeFuncionariosGerenciados = numeroDeFuncionariosGerenciados;
	}
	
	public void mostraDados(){
		super.mostraDados();
		System.out.println("Senha: "+this.senha);
		System.out.println("Gerencia "+this.numeroDeFuncionariosGerenciados+" funcionários");
	}
}
