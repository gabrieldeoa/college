
abstract class Veiculo {
	protected String modelo;
	protected int ano;
	protected double valorDeMercado;
	private final double VALOR_MINIMO_DE_MERCADO = 10000.0;
	
	//construtor
	public Veiculo(String modelo){
		this.modelo = modelo;
	}
	
	//setters
	public void setModelo(String modelo) { this.modelo = modelo; }
	
	public void setAno(int ano) { this.ano = ano; }
	
	public void setValorDeMercado(double valorDeMercado) {
		this.valorDeMercado = (valorDeMercado < VALOR_MINIMO_DE_MERCADO)
			? VALOR_MINIMO_DE_MERCADO
			: valorDeMercado;
	}
	
	//getters
	public String getModelo() { return this.modelo; }
	
	public int getAno() { return this.ano; }
	
	public double valorDeMercado() { return this.valorDeMercado; }
	
	//outros
	abstract double getGastosComImpostos();
}
