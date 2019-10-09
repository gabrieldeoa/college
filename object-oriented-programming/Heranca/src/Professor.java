
public class Professor  extends Pessoa {
	protected int horasDeAulaMes;
	protected int valorHoraAula;
	protected double salario;
	
	public int getHorasDeAulaMes() {
		return horasDeAulaMes;
	}
	
	public void setHorasDeAulaMes(int horasDeAulaMes) {
		this.horasDeAulaMes = horasDeAulaMes;
		
		if(this.valorHoraAula > 0)
				this.calcularSalario();
	}
	
	public int getValorHoraAula() {
		return valorHoraAula;
	}
	
	public void setValorHoraAula(int valorHoraAula) {
		this.valorHoraAula = valorHoraAula;
		
		if(this.horasDeAulaMes > 0)
			this.calcularSalario();
	}
	
	public double getSalario() {
		return salario;
	}
	
	protected void calcularSalario() {
		this.salario =  (this.horasDeAulaMes * this.valorHoraAula);
	}
	
	
	
}
