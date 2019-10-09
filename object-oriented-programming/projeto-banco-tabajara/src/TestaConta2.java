
public class TestaConta2 {
	public static void main(String[] args) {
		Cliente cliente1 = new Cliente();
		cliente1.setNome("Luan");
		cliente1.setCpf("12345678920");
		cliente1.setEmail("luan.anuda@gmail.com");
		
		/*Conta umaConta;
		umaConta = new Conta("Heloíse");
		//System.out.println("Tenho "+Conta.getContador()+" contas em memória!");
		umaConta.setNumero(123);
		umaConta.setAgencia(456);
		umaConta.deposita(5000);
		//Conta do MestreDosMagos*/
		Conta outraConta = new Conta(456,789,50);
		outraConta.deposita(200);
		outraConta.setTitular(cliente1);//xpto
		outraConta.getTitular().setEmail("luan@gmail.com");
		//System.out.println("Tenho "+Conta.getContador()+" contas em memória!");
		//Conta maisUmaConta = new Conta();
		System.out.println("A conta do "+outraConta.getTitular().getNome()
				+ "possui um saldo de "+outraConta.getSaldo());
		
		System.out.println("Tenho "+Conta.getContador()+" contas em memória!");
	}
}
