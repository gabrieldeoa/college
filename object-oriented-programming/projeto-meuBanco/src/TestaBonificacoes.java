
public class TestaBonificacoes {
	public static void main(String[] args) {
		ControleDeBonificacoes controle = new ControleDeBonificacoes();
		
		Gerente g = new Gerente();
		g.setNome("Raine");
		g.setSalario(10000);
		g.setCpf("12345678900");
		g.getDataDeNascimento().setDia("30");
		g.getDataDeNascimento().setMes("04");
		g.getDataDeNascimento().setAno("1999");
		g.setSenha(123456);
		g.setNumeroDeFuncionariosGerenciados(20);
		if(g.autentica(123456)==true){
			System.out.println("Autenticado");
			g.mostraDados();
		}
		
		Caixa f = new Caixa();
		f.setNome("Malu");
		f.setSalario(8000);
		f.setCpf("12345678955");
		f.getDataDeNascimento().setDia("03");
		f.getDataDeNascimento().setMes("07");
		f.getDataDeNascimento().setAno("1999");
		f.mostraDados();
		
		controle.acumula(g);
		controle.acumula(f);
		System.out.println("O total de bonificações é: "+controle.getTotalDeBonificacoes());
			
	}
}
