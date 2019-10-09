
public class ProfessorMestre extends Professor {
	private String temaDaDissertacao;

	public String getTemaDaDissertacao() {
		return this.temaDaDissertacao;
	}

	public void setTemaDaDissertacao(String temaDaDissertacao) {
		this.temaDaDissertacao = temaDaDissertacao;
	}
	
	protected void calcularSalario() {
		this.salario =  ((this.valorHoraAula * 0.2) * this.horasDeAulaMes );
	}
}
