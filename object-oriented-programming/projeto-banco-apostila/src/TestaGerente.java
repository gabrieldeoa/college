
public class TestaGerente {
	public static void main(String[] args) {
		Gerente gerente = new Gerente();
		
		gerente.setNome("Gabriel");
		gerente.setSalario(10000);
		gerente.setCpf("16494155758");
		gerente.setAtivo(true);
		gerente.setDepartamento("Desenvolvimento");
		gerente.getDataDeNascimento().setDia("05");
		gerente.getDataDeNascimento().setMes("09");
		gerente.getDataDeNascimento().setAno("1994");
		gerente.setSenha(123456);
		gerente.setNumeroFuncionariosGerenciados(10);
		
		if(gerente.autentica(123456)) {
			gerente.mostraDados();
		}
		
		Funcionario funcionario = new Funcionario();
		funcionario.setNome("Malu");
		funcionario.setSalario(10000);
		funcionario.setAtivo(true);
		funcionario.setCpf("16494155758");
		funcionario.setDepartamento("Suporte");
		funcionario.getDataDeNascimento().setDia("03");
		funcionario.getDataDeNascimento().setMes("06");
		funcionario.getDataDeNascimento().setAno("1999");
		funcionario.mostraDados();
		
	}
}
