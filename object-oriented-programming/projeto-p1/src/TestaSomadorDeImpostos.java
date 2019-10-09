public class TestaSomadorDeImpostos {
	public static void main(String[] args) {
		SomadorDeImpostos somador = new SomadorDeImpostos();
		VeiculoDePasseio vp = new VeiculoDePasseio("Corsa", 2000, 12.000);
		VeiculoUtilitario vu = new VeiculoUtilitario("Saveiro", 2005, 20.000);

		vp.getMotor().setPotencia(1.6);
		vu.getMotor().setPotencia(2.0);

		somador.acumularGastosComImpostos(vp);
		somador.acumularGastosComImpostos(vu);

		System.out.println("O total de gastos com impostos é : "
				+ somador.getTotalDeGastosComImpostos());
	}
}
