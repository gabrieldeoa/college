
public class VeiculoDePasseio extends Veiculo{

	public VeiculoDePasseio(String modelo, int ano, double valorDeMercado) {
		super(modelo,ano,valorDeMercado);// Invocando o construtor da superclasse (Veiculo)
	}
	
	public double getGastosComImpostos(){
		return this.valorDeMercado*0.10;
	}
}
