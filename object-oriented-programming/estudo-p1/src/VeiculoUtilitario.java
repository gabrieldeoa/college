
public class VeiculoUtilitario extends Veiculo{
	private int capacidadeDeCarga;
	
	//construtor
	public VeiculoUtilitario(String modelo) {
		super(modelo);
	}
	
	//setters
	public void setCapacidadeDeCarga(int capacidadeDeCarga) { this.capacidadeDeCarga = capacidadeDeCarga; }
	
	//getters
	public int getCapacidadeDeCarga() { return this.capacidadeDeCarga; }
	
	//reescrita - no caso o da super classe nao tem implementação e delegou pras filhas implementarem
	public double getGastosComImpostos() {
		return (this.valorDeMercado * 0.15);
	}
}
