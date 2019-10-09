
public class Funcionario {
	protected String nome;
	protected String departamento;
	protected double salario;
	protected String cpf;
	protected boolean ativo;
	protected Data dataDeNascimento;//= new Data();
	
	public Funcionario() {
		this.dataDeNascimento = new Data();
	}
	
	public Funcionario(String nome, String dia, String mes, String ano) {
		this.nome = nome;
		
		this.dataDeNascimento = new Data(dia, mes, ano);
	}
	
	private boolean validaCpf(String cpf) {
		return (cpf.length() == 11);
	}

	public String getCpf() {
		return this.cpf;
	}

	public void setCpf(String cpf) {
		if(this.validaCpf(cpf)) {
			this.cpf = cpf;
		}
			
	}
	
	public String getNome() {
		return this.nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public String getDepartamento() {
		return departamento;
	}
	
	public void setDepartamento(String departamento) {
		this.departamento = departamento;
	}
	
	public double getSalario() {
		return salario;
	}
	
	public void setSalario(double salario) {
		this.salario = salario;
	}
	
	public double getBonificacao() {
		return (this.salario * 0.1);
	}
	
	public boolean isAtivo() {
		return ativo;
	}
	
	public void setAtivo(boolean ativo) {
		this.ativo = ativo;
	}
	
	public Data getDataDeNascimento() {
		return dataDeNascimento;
	}
	
	public boolean aumentarSalario(double percentual) {
		if(percentual <= 0)
			return false;
		
		this.salario += this.salario * (percentual/100);
		
		return true;
	}
	
	public boolean demitir() {
		if(this.ativo) {
			this.ativo = false;
			return true;
		}
		
		return false;
	}
	
	public void mostraDados() {
		System.out.println("\n\nNome: " + this.nome);
		System.out.println("Nascimento: "+ this.dataDeNascimento.getDataFormatoBrasileiro());
		System.out.println("Salário: " + this.salario);
		System.out.println("Departamento: " + this.departamento);
		System.out.println("Está na empresa ? " + ((this.ativo) ? "Sim" : "Não" ));
		System.out.println("Bonificação: " + this.getBonificacao());
	}
	
	
}
