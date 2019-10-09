
public class TestaSomadorDeImpostos {
	public static void main(String[] args) {
		SomadorDeImpostos somadorImpostos = new SomadorDeImpostos();
		
		VeiculoDePasseio vPasseio = new VeiculoDePasseio("Ka");
		vPasseio.setAno(2019);
		vPasseio.setValorDeMercado(35000);
		
		VeiculoUtilitario vUtilitario = new VeiculoUtilitario("Hilux");
		vUtilitario.setAno(2018);
		vUtilitario.setValorDeMercado(95000);
		vUtilitario.setCapacidadeDeCarga(100);
		
		VeiculoPesado vPesado = new VeiculoPesado("Scania");
		vPesado.setAno(2016);
		vPesado.setValorDeMercado(200000);
		vPesado.setQuantidadeDeEixos(2);
		
		somadorImpostos.acumulaGastosComImpostos(vPasseio);
		somadorImpostos.acumulaGastosComImpostos(vUtilitario);
		somadorImpostos.acumulaGastosComImpostos(vPesado);
		
		System.out.println("O Total de Impostos é: "  + somadorImpostos.getTotalDeGastosComImpostos());
	}
}
