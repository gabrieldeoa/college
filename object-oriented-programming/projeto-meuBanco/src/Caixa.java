
public class Caixa extends Funcionario{
	private int numeroDoGuiche=0;

	public int getNumeroDoGuiche() {
		return numeroDoGuiche;
	}

	public void setNumeroDoGuiche(int numeroDoGuiche) {
		this.numeroDoGuiche = numeroDoGuiche;
	}

	@Override
	double getBonificacao() {
		return this.salario * 0.15;
	}
}
