public abstract class Funcionario {
	protected String nome;
	protected String departamento;
	protected String cpf;
	protected double salario;
	protected boolean ativo=true;
	protected Data dataDeNascimento;// = new Data();// só get
	
	public Funcionario() {
		//Cria um objeto Data e faz com que dataDeNascimento aponte p/ ele!!
		this.dataDeNascimento = new Data();
	}
	
	public Funcionario(String nome,String dia, String mes, String ano) {
		this.nome = nome; 
		this.dataDeNascimento = new Data(dia, mes, ano);
		/*this.dataDeNascimento.setDia(dia);
		this.dataDeNascimento.setMes(mes);
		this.dataDeNascimento.setAno(ano);*/
	}
	
	abstract double getBonificacao();
	
	private boolean validaCpf(String cpf){
		if(cpf.length()==11)
			return true;
		return false;
	}
	
	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		if(this.validaCpf(cpf)==true)
			this.cpf = cpf;
	}
	

	
	public Data getDataDeNascimento() {
		return this.dataDeNascimento;
	}
	
	public String getNome() {
		return this.nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getDepartamento() {
		return this.departamento;
	}

	public void setDepartamento(String departamento) {
		this.departamento = departamento;
	}

	public double getSalario() {
		return this.salario;
	}

	public void setSalario(double salario) {
		this.salario = salario;
	}

	public boolean isAtivo() {
		return this.ativo;
	}

	public void demite(){
		this.ativo=false;
	}
	
	public void aumentarSalario(double percentual){
		this.salario = this.salario + ( (this.salario * percentual)/100 );
	}

	public void mostraDados() {
		System.out.println("Nome: "+this.nome);
		System.out.println("Departamento: "+this.departamento);
		System.out.println("Salário: "+this.salario);
		System.out.println((this.ativo)?"Está na empresa":"Não está mais na empresa");
		System.out.println("Data de nascimento: "+this.dataDeNascimento.getDataCompletaBr());
		System.out.println("Bonificação: "+this.getBonificacao());
	}
	
	@Override
	public boolean equals(Object outroFuncionario) {
		Funcionario f1 = (Funcionario) this;
		Funcionario f2 = (Funcionario) outroFuncionario;
		if(f1.nome==f2.nome && f1.departamento ==f2.departamento 
				&& f1.salario == f2.salario && f1.ativo==f2.ativo)
			return true;
		else
			return false;
	}
}
