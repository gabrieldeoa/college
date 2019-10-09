
public class SomadorDeImpostos {
	private double totalDeGastosComImpostos = 0;
	
	//setters
	public void acumulaGastosComImpostos(Veiculo veiculo) {
		this.totalDeGastosComImpostos += veiculo.getGastosComImpostos();
	}
	
	//getters
	public double getTotalDeGastosComImpostos() {
		return this.totalDeGastosComImpostos;
	}
}
