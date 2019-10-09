public class SomadorDeImpostos {
	
	private double totalDeGastosComImpostos;
	
	public double getTotalDeGastosComImpostos() {
		return totalDeGastosComImpostos;
	}

	public void acumularGastosComImpostos(Veiculo v){//polimorfismo
		//O m�todo abaixo precisa existir na classe Veiculo
		this.totalDeGastosComImpostos+=v.getGastosComImpostos();
	}
}
