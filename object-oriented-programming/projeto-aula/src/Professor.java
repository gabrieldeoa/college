
public class Professor extends Pessoa{

	protected double salario, valorHoraAula, horasDeAulaMes;

	public double getSalario() {
		return this.salario;
	}

/*	public void setSalario(double salario) {
		this.salario = salario;
	}*/

	public double getValorHoraAula() {
		return this.valorHoraAula;
	}
	
	protected void calcularSalario() {
		this.salario = this.valorHoraAula * this.horasDeAulaMes;
	}

	public void setValorHoraAula(double valorHoraAula) {
		this.valorHoraAula = valorHoraAula;
		if(this.horasDeAulaMes>0)
			this.calcularSalario();
	}

	public double getHorasDeAulaMes() {
		return this.horasDeAulaMes;
	}

	public void setHorasDeAulaMes(double horasDeAulaMes) {
		this.horasDeAulaMes = horasDeAulaMes;
		if(this.valorHoraAula>0)
			this.calcularSalario();
	}

}
