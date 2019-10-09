
public class Cliente {
	private String nome;
	private String cpf;
	private String email;

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getCpf() {
		return cpf;
	}
	
	private boolean validaCpf(String cpf){
		if(cpf.length()==11)
			return true;
		else
			return false;
	}

	public void setCpf(String cpf) {
		if(this.validaCpf(cpf)==true)
			this.cpf = cpf;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}
}
