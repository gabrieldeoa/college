
public class ProfessorMestre extends Professor {
	private String temaDaDissertacao;

	public String getTemaDaDissertacao() {
		return temaDaDissertacao;
	}

	public void setTemaDaDissertacao(String temaDaDissertacao) {
		this.temaDaDissertacao = temaDaDissertacao;
	}
	
	@Override
	protected void calcularSalario() {
		this.salario = (this.valorHoraAula * 1.2) * this.horasDeAulaMes;
	}
}
