
public class VeiculoUtilitario extends Veiculo{
	private int capacidadeDeCarga;
	
	//construtor
	public VeiculoUtilitario(String modelo, int ano, double vMercado) {
		super(modelo, ano, vMercado);
	}

	public int getCapacidadeDeCarga() {
		return capacidadeDeCarga;
	}

	public void setCapacidadeDeCarga(int capacidadeDeCarga) {
		this.capacidadeDeCarga = capacidadeDeCarga;
	}
	
	public double getGastosComImpostos(){
		return this.valorDeMercado*0.16;
	}

}
