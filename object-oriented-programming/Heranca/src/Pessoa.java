
public class Pessoa {
	protected String nome;
	protected String cpf;
	protected String telefone;
	
	public String getNome() {
		return this.nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public String getCpf() {
		return this.cpf;
	}
	
	public void setCpf(String cpf) {
		if(this.validaCpf(cpf))
			this.cpf = cpf;
	}
	
	public String getTelefone() {
		return this.telefone;
	}
	
	public void setTelefone(String telefone) {
		if(this.validaTelefone(telefone))
			this.telefone = telefone;
	}
	
	private boolean validaCpf(String cpf) {
		return (this.cpf.length() == 11);
	}
	
	private boolean validaTelefone(String telefone) {
		return (this.telefone.length() == 11);
	}
	
	
}
