
public class ContaPoupanca extends Conta{
	protected void atualiza(double taxa) {
		this.saldo -= (taxa*3);
	}
}
