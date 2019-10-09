
public class TestaContas {
	public static void main(String[] args) {
		Conta c = new Conta();
		Conta cc = new ContaCorrente();
		ContaPoupanca cp = new ContaPoupanca();
		
		c.deposita(1000);
		cc.deposita(1000);
		cp.deposita(1000);
		
		System.out.println("Conta - saldo: "+c.getSaldo());
		System.out.println("ContaCorrenta - saldo: "+cc.getSaldo());
		System.out.println("ContaPoupan�a - saldo: "+cp.getSaldo());
		cp.mostraSaldo();
		
		c.atualiza(0.10);
		cc.atualiza(0.10);
		cp.atualiza(0.10);
		
		System.out.println("Depois da atualiza��o. \n\n\n");
		System.out.println("Conta - saldo: "+c.getSaldo());
		System.out.println("ContaCorrenta - saldo: "+cc.getSaldo());
		System.out.println("ContaPoupan�a - saldo: "+cp.getSaldo());
		
		
	}
}
