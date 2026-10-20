# Integrar branches e worktrees em main

## Contexto

O pedido é incorporar todo o trabalho de branches locais e remotas em `main`, branch por branch, rebaseando antes de cada merge e removendo a worktree e a branch somente depois da integração. A intenção é terminar com apenas `main` local e `origin/main` remoto.

A inspeção inicial encontrou 147 branches locais, 9 referências remotas em cache (incluindo `origin/HEAD` e `origin/main`) e 20 entradas de worktree. `main` está 76 commits à frente de `origin/main` e contém 106 caminhos alterados staged ou unstaged. Onze worktrees vinculadas estão sujas, incluindo uma bloqueada por outra sessão ativa; uma worktree detached está marcada como prunable. Há 128 branches locais sem worktree, muitas com commits únicos e histórico bastante divergente. Os refs remotos foram atualizados com `git fetch origin`, sem podar refs.

O usuário decidiu preservar e incluir as alterações atuais de `main`. Não descartar alterações, não forçar desbloqueio de worktree, não fazer force-push e não remover branch antes de confirmar que seus commits estão alcançáveis por `main`. Não inventar resolução para conflitos quando o comportamento pretendido não estiver comprovado.

## Sequência

1. **Atualizar e registrar o inventário.** Fazer `git fetch origin` sem podar refs. Confirmar branch padrão, refs remotos atuais, worktrees, status de cada worktree, commits únicos, upstreams e relações de ancestralidade. Agrupar branches relacionadas e ordenar a integração de modo que bases/ancestrais sejam tratadas antes das branches derivadas. Identificar branches já incorporadas para evitar reaplicar trabalho equivalente. Registrar o inventário antes de qualquer exclusão.

2. **Proteger e validar alterações existentes.** Revisar as alterações staged, unstaged e untracked em `main` e em cada worktree suja. Preservar os arquivos de usuário. Não adicionar arquivos gerados, binários de jogo, ISOs, compiladores ou outros artefatos ignorados. Para alterações de código, seguir o TDD e os gates de [docs/testing.md](../testing.md); para alterações documentais, executar as verificações estáticas. Criar commits lógicos nas branches proprietárias depois de validar escopo e testes. Se a propriedade ou intenção de um arquivo não puder ser determinada, parar antes de rebase ou remoção.

3. **Sincronizar `main`.** Integrar as alterações escolhidas de `main` em commits preserváveis. Após atualizar refs, confirmar a relação de ancestralidade entre `main` e `origin/main`; avançar por fast-forward apenas se `main` estiver atrás. Não rebasear nem reescrever os 76 commits locais já publicados ou ainda não sincronizados. Se `main` e `origin/main` divergirem ou a sincronização exigir reescrita, parar e relatar a divergência antes de prosseguir.

4. **Integrar branches locais, uma por vez.** Para cada branch local diferente de `main`, confirmar seu conteúdo único e seu estado limpo. No worktree existente, ou em um worktree temporário para branches sem worktree, rebasear a branch sobre o `main` atualizado. Resolver conflitos usando implementação, testes, documentação e evidência do binário; se houver mais de uma resolução plausível, parar naquela branch e manter worktree e branch intactas. Executar os testes afetados, revisar o diff e então fazer merge em `main`. Confirmar que o tip/commits únicos da branch estão alcançáveis por `main` antes de remover a worktree e apagar a branch local. Repetir até não restar branch local além de `main`.

5. **Integrar branches remotas, uma por vez.** Para cada branch `origin/*` diferente de `origin/main`, criar uma branch local temporária a partir do ref remoto atualizado. Rebasear essa cópia sobre `main`, resolver e testar como na etapa anterior, e fazer merge em `main`. Confirmar que os commits únicos remotos estão alcançáveis por `main`; só então apagar a branch remota com exclusão normal, sem force-push. Apagar também a branch temporária e atualizar refs de rastreamento após a confirmação do servidor. Nunca apagar `origin/main`.

6. **Validação e limpeza final.** Executar os testes dos subsistemas afetados e a suíte completa disponível conforme [docs/testing.md](../testing.md), registrando falhas, skips e pré-requisitos ausentes. Fazer push normal de `main` e confirmar que `origin/main` aponta para o resultado integrado. Não usar `git worktree unlock` numa sessão ainda ativa. Remover worktrees já incorporadas pela sequência normal. Só limpar a entrada detached prunable após verificar que seu gitdir não existe e que não contém dados recuperáveis. Confirmar que `git branch` lista somente `main`, que `git branch -r` lista apenas `origin/HEAD` e `origin/main`, e que `git worktree list` lista somente o checkout principal.

## Bloqueios obrigatórios

- A worktree bloqueada `worktree-render-manager-status` permanece intacta até a sessão proprietária terminá-la e o lock desaparecer naturalmente.
- Alterações untracked ou ignoradas em qualquer worktree exigem inspeção. Arquivos `build` e `orig` não devem ser adicionados ou apagados sem confirmação de conteúdo e propriedade.
- A contagem e o conjunto de refs remotos podem mudar após `fetch`; usar o inventário atualizado como fonte de verdade.
- Rebase ou merge com conflitos de intenção incerta, testes novos falhando, commits sem origem clara, branch protegida, recusa do servidor ou necessidade de force-push interrompem o processamento daquela branch. Preservar branch e worktree e relatar evidência; não declarar que só `main` restou enquanto houver bloqueios.
- O comando `git worktree prune` não substitui a verificação de conteúdo; usar apenas para metadados comprovadamente prunable.
