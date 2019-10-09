
public class VeiculoDePasseio extends Veiculo{
	
	//construtor
	public VeiculoDePasseio(String modelo) {
		super(modelo);
	}
	
	//reescrita - no caso o da super classe nao tem implementação e delegou pras filhas implementarem
	public double getGastosComImpostos() {
		return (this.valorDeMercado * 0.10);
	}
}
