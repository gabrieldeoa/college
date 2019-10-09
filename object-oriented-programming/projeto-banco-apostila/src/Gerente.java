
public class Gerente extends Funcionario {
	private int senha;
	private int numeroFuncionariosGerenciados;
	
	public Gerente () {
		super();
	}
	
	public Gerente(String nome, String dia, String mes, String ano, int senha) {
		super(nome, dia, mes, ano);
		this.senha = senha;
	}
	
	public int getSenha() {
		return this.senha;
	}
	
	public void setSenha(int senha) {
		this.senha = senha;
	}
	
	public int getNumeroFuncionariosGerenciados() {
		return this.numeroFuncionariosGerenciados;
	}
	
	public void setNumeroFuncionariosGerenciados(int numeroFuncionariosGerenciados) {
		this.numeroFuncionariosGerenciados = numeroFuncionariosGerenciados;
	}
	
	public boolean autentica(int senha) {
		return (this.senha == senha);
	}
	
	public double getBonificacao() {
		return (this.salario * 0.2);
	}
	
	public void mostraDados() {
		super.mostraDados();
		System.out.println("Senha: " + this.senha);
		System.out.println("Numero de funcionarios gerenciados: " + this.numeroFuncionariosGerenciados);
	}
	
	
}
