
public class TestaConta3 {
	public static void main(String[] args) {
		Conta umaConta = new Conta(555, 888, 20000);
		umaConta.getTitular().setNome("Raine");
		umaConta.getTitular().setCpf("555555555679");
		System.out.println(umaConta.getTitular().getNome());
		System.out.println(umaConta.getTitular().getCpf());
	}
}
