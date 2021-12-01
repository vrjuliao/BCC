# Laboratório 2
Aluno: Vinicius Julião Ramos\
Matricula: 2018054630

-----

1. **Qual o projeto analisado?**\
  Vuepress, uma ferramenta para geração de páginas de documentação, baseada
  no framework VueJs.\
  [https://github.com/vuejs/vuepress](https://github.com/vuejs/vuepress)

2. **Quais os 5 arquivos mais complexos do projeto?**\
  A seguinte tabela demonstra os arquivos mais complexos ordenados em forma
  decrescente de complexidade:

  Arquivo   | AvgCCN | Avg.NLOC | function_cnt
  --------- | :----: | :------: | :---------:
  ./packages/@vuepress/core/lib/node/plugin-api/util.js | 9.0 | 42.0 | 1
  ./packages/@vuepress/core/lib/node/plugin-api/override/instantiateOption.js | 7.0 | 15.0 | 1
  ./packages/@vuepress/core/lib/node/internal-plugins/frontmatterBlock/loader.js | 7.0 | 18.0 | 1
  ./packages/@vuepress/markdown/lib/component.js | 7.0 | 19.5 | 2
  ./packages/@vuepress/core/lib/node/CacheLoader.js | 7.0 | 20.0 | 1

  Esta tabela considera que os arquivos mais complexos são aqueles que possuem
  uma maior média de CCN (*AvgCCN*), porém levando em consideração também a
  quantidade de funções existentes e a quantidade de linhas de código.
  Observe que a maioria dos arquivos possuem apenas uma função, o que pode
  introduzir uma maior complexidade ao arquivo.


3. **Quais os 5 arquivos mais complexos do projeto?**\
  A seguinte tabela demonstra os cinco métodos mais complexos, ordenados de
  forma decrescente em complexidade:

  Função/método | Arquivo | CCN | NLOC
  ------------- | ------- | :----: | :------:
  htmlBlock | ./packages/@vuepress/markdown/lib/component.js | 13 | 36
  resolveSidebarItems | ./packages/@vuepress/theme-default/util/index.js | 11 | 22
  setActiveHash | ./packages/@vuepress/plugin-active-header-links/clientRootMixin.js | 11 | 48
  ready | ./packages/@vuepress/core/lib/node/internal-plugins/palette/index.js | 11 | 34
  resolveTheme | ./packages/@vuepress/core/lib/node/loadTheme.js | 11 | 39

  A ordem de complexidade dos métodos foi mensurada tomando *CCN* como o
  principal fator, entretanto, também considerou-se o caso da quantidade de
  linhas de código.

4. **Selecione um dos 5 métodos/funções mais complexas**\
   **a.** Apresente o seu código\
   A função escolhida foi `setActiveHash`
   ```js
   setActiveHash () {
      const sidebarLinks = [].slice.call(document.querySelectorAll(AHL_SIDEBAR_LINK_SELECTOR))
      const anchors = [].slice.call(document.querySelectorAll(AHL_HEADER_ANCHOR_SELECTOR))
        .filter(anchor => sidebarLinks.some(sidebarLink => sidebarLink.hash === anchor.hash))

      const scrollTop = Math.max(
        window.pageYOffset,
        document.documentElement.scrollTop,
        document.body.scrollTop
      )

      const scrollHeight = Math.max(
        document.documentElement.scrollHeight,
        document.body.scrollHeight
      )

      const bottomY = window.innerHeight + scrollTop

      for (let i = 0; i < anchors.length; i++) {
        const anchor = anchors[i]
        const nextAnchor = anchors[i + 1]

        const isActive = i === 0 && scrollTop === 0
          || (scrollTop >= anchor.parentElement.offsetTop + 10
            && (!nextAnchor || scrollTop < nextAnchor.parentElement.offsetTop - 10))

        const routeHash = decodeURIComponent(this.$route.hash)
        if (isActive && routeHash !== decodeURIComponent(anchor.hash)) {
          const activeAnchor = anchor
          // check if anchor is at the bottom of the page to keep $route.hash consistent
          if (bottomY === scrollHeight) {
            for (let j = i + 1; j < anchors.length; j++) {
              if (routeHash === decodeURIComponent(anchors[j].hash)) {
                return
              }
            }
          }
          this.$vuepress.$set('disableScrollBehavior', true)
          this.$router.replace(decodeURIComponent(activeAnchor.hash), () => {
            // execute after scrollBehavior handler.
            this.$nextTick(() => {
              this.$vuepress.$set('disableScrollBehavior', false)
            })
          })
          return
        }
      }
    }
   ```

   **b.** Tente entender esse método/função e apresente uma breve descrição:

   Vuepress é uma ferramente de frontend.
   Normalmente, atribuímos um ID para os elementos HTML que é identificado pelo
   caractere `#` (conhecido como hash).
   Como no tema padrão do Vuepress, o menu lateral e o superior são fixos, para
   cada item dos menus, é atribuído um ID unico (um hash).
   A medida em que se navega entre as páginas, os itens do menu lateral são
   coloridos de acordo com a página e a altura do scroll em que se está
   navegando.
   Essa função é responsável por identificar a página e a altura do scroll
   e então colorir os elementos com o hash correto.


   **c.** Sugira alguma refatoração ou prática de clean code para melhorar esse
   código:

   A primeira alteração seria criar uma forma mais legível para o código que
   atribui valor à `const anchors`.
   Pois trata-se de um código carregado de *tricks* próprios da linguagem, e é
   necessário um certo esforço para obter a intenção correta daquele código.
   Provavelmente uma extração de método seria adequada neste cenário.

   Um outro refactoring seria remover alguns valores mágicos que são atribuídos
   na chamada de `this.$vuepress.$set()`.

   A expressão booleana que tem valor atribuído em `const isActive` poderia 
   ser melhor escrita, com a utilização de parentesis, que tornariam a leitura
   do código mais eficaz.

