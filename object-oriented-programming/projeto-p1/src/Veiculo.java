abstract class Veiculo{
	protected String modelo;
	protected int ano;
	protected double valorDeMercado;
	protected Motor motor; //= new Motor();
	
	//construtor
	public Veiculo(String modelo, int ano, double vMercado) {
		this.modelo=modelo;
		this.ano=ano;
		this.valorDeMercado=vMercado;
		this.motor=new Motor();
	}
	
	abstract double getGastosComImpostos();
	
	public int getAno() {
		return ano;
	}

	public void setAno(int ano) {
		this.ano = ano;
	}

	public double getValorDeMercado() {
		return valorDeMercado;
	}

	public void setValorDeMercado(double valorDeMercado) {
		this.valorDeMercado = valorDeMercado;
	}

	public Motor getMotor() {
		return motor;
	}
	
	public void setModelo(String modelo){
		this.modelo=modelo;
	}
	
	public String getModelo(){
		return this.modelo;
	}
}
