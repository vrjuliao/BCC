# Laboratório 1
Aluno: Vinicius Julião Ramos\
Matricula: 2018054630

---

## 1.

a) **Correção de documentação**: Um problema típico é o de correção de
documentação.
Muitos usuários buscam informações na documentação do das ferramentas e se
deparam com textos ambíguos, ou até mesmo com a ausência de detalhes que são
importantes para a plena utilização de determinado recurso.
Então, no mundo *open-source*, estes mesmos usuários que necessitam daquele
recurso, descobrem a maneira correta de utilizar (mesmo diante da falta de
documentação) e após garantirem que conhecem o comportamento do recurso, estes
usuários submetem uma proposta de adição ou alteração.

- Facebook/react\
Neste repositório podemos encontrar um exemplo de modificação na documentação
dada pela abertura da [Issue 1883](https://github.com/facebook/react/issues/1883)
a qual foi resolvida pelo [pull request 2635 ](https://github.com/facebook/react/pull/2635).
Issue aborda a necessidade de tornar mais claro a utilização de um *helper*
da propriedade `setTextContent`.
Para isso propôs-se que mudasse a explicação de como e porque utilizar tal
propriedade.

- ReactiveX/RxJava\
Em Java, é possível gerar documentação de código através da utilização de tags
que atribuem descrições a atributos, métodos e classes.
A notação para tal feito é dada pela utilização da notação JavaDoc.
Em suma, esse tipo de notação traz uma documentação mais direta em que
é possível realizar o parsing dos arquivos e gerar diversos tipos de visualização.
Há ainda IDEs que permitem pesquisar o que se procura através das descrições do
JavaDoc.
Então neste ponto, há um tipo diferente de modificação de documentação (se
comparado ao repositório do React), uma vez que JavaDoc é escrito diretamente
nos arquivos de código de Java, e não em um parte separada do sistema.
Logo as alterações desses pontos serão atribuídas ao próprio código.
No seguinte exemplo concreto, os comentários do código que anteriormente usavam
notação markdown, ou então uma notação não padronizada para demonstrar pedaços
de código, agora foram atualizados para utilizarem a *tag* `@code`.
O [Pull request 6943](https://github.com/ReactiveX/RxJava/pull/6943) demonstra
quais foram as alterações desse changeset.

b) **Renaming**: Outra issue constantemente abordada e resolvida nos sistemas
apresentados nessa tarefa é o renaming.
Nomes, são muito importantes para a tarefa de leitura do código, pois o
entendimento do funcionamento de determinada parte do código é facilitado desde
que os símbolos atribuídos a variáveis, métodos, atributos e classes expressem
a real funcionalidade do código.
Então nestes sistemas, muitas vezes a atribuição de nomes pode ser melhorada
uma vez que os nomes atribuídos num primeiro momento podem não soar tão claro
para outros leitores (senão o próprio autor).
Por isso, a alteração de nomenclatura, em sistemas *open source*, geralmente é
acompanhada por discussões (para que haja concordância entre a comunidade) e
só então há a modificação.
Entretanto, nem sempre isso é verdade, pois há casos em que o nome pode ser
proposto inicialmente e já aceito pelos responsáveis por aprovarem a mudança.

- Facebook/react\
Muitas vezes, grandes pacotes ou módulos ganham melhoria que os tornam mais
amplos, ou então de maneira contrária, um módulo muito grande pode ser dividido
em módulos menores e independentes.
Quando há a divisão de um módulo em pacotes menores, necessita-se de criar
novos nomes que sejam capazes de denotar a função daquele componente.
Muitas vezes, esse particionamento necessita mudar a estrutura do projeto (em
nível) de diretórios, e possivelmente a forma como é feita a importação
daqueles pacotes nas demais partes do código.
Algo parecido ocorre quando módulo se torna maior, e mais amplo, entretanto
neste caso o que ocorre é a mudança do nome do módulo, que naquele momento
deverá ser capaz de expressar a generalidade que aquele pacote possui.
No caso do [Pull request 22691](https://github.com/facebook/react/pull/22691)
o que ocorre é que o pacote `scheduling-profiler` mudou para `timeline` uma vez
que com o passar do tempo esse módulo se tornou mais genérico e agora possui
funcionalidades não existentes anteriormente.
Por conta dessa mudança de nome, além da necessidade da mudança de diretórios,
houve também a necessidade de modificar as partes de código que anteriormente
importavam de `scheduling-profiler`.

- ReactiveX/RxJava\
Assim como abordado anteriormente
[Pull request 6853](https://github.com/ReactiveX/RxJava/pull/6853)