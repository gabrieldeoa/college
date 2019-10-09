public class SomadorDeImpostos {
	
	private double totalDeGastosComImpostos;
	
	public double getTotalDeGastosComImpostos() {
		return totalDeGastosComImpostos;
	}

	public void acumularGastosComImpostos(Veiculo v){//polimorfismo
		//O método abaixo precisa existir na classe Veiculo
		this.totalDeGastosComImpostos+=v.getGastosComImpostos();
	}
}
