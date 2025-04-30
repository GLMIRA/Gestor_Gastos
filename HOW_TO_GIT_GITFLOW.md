
# 📚 HOW TO: Git & Git Flow no Projeto

Este projeto segue o fluxo de trabalho **Git Flow** para organizar o desenvolvimento. Abaixo está um guia completo de como clonar, iniciar e contribuir corretamente com o repositório.

---

## 🚀 1. Clonar o Repositório

```bash
git clone git@github.com:SEU_USUARIO/SEU_REPOSITORIO.git
cd SEU_REPOSITORIO
```

---

## 🔧 2. Instalar o Git Flow

### Ubuntu/Debian
```bash
sudo apt install git-flow
```

### Arch/Manjaro
```bash
sudo pacman -S git-flow
```

### macOS
```bash
brew install git-flow-avh
```

---

## 🧭 3. Inicializar o Git Flow (apenas uma vez)

```bash
git flow init
```

### Configurações recomendadas:
- **Branch principal (production releases):** `main`
- **Branch de desenvolvimento:** `developer`
- Prefixos de branch:
  - Feature branches: `feature/`
  - Bugfix branches: `bugfix/`
  - Release branches: `release/`
  - Hotfix branches: `hotfix/`
  - Support branches: `support/`
- Prefixo de versão (version tag): deixar em branco
- Hooks directory: deixe o padrão

---

## ✏️ 4. Criar uma Nova Feature

```bash
git flow feature start nome-da-feature
```

Exemplo:
```bash
git flow feature start editar-validacao-cpf
```

Isso cria e muda automaticamente para a branch `feature/editar-validacao-cpf`.

---

## 💻 5. Trabalhar normalmente

Faça alterações no código, commits e adicione mensagens descritivas:

```bash
git add .
git commit -m "feat: adiciona validação extra para CPF"
```

---

## ☁️ 6. Subir a branch para o GitHub

```bash
git push --set-upstream origin feature/editar-validacao-cpf
```

---

## 🔁 7. Criar Pull Request (PR)

Acesse o GitHub e abra um PR de:

```
feature/editar-validacao-cpf → developer
```

---

## ✅ 8. Finalizar a feature (opcional)

Após o merge ser aceito:

```bash
git flow feature finish editar-validacao-cpf
```

⚠️ Isso **remove a branch localmente**. Se quiser manter, pule esse passo.

---

## 🧽 9. Manter o projeto atualizado

Antes de criar novas features ou trabalhar:

```bash
git checkout developer
git pull origin developer
```

---

## 🧪 10. Rodar os testes (se aplicável)

```bash
cmake -B build
cmake --build build
ctest --test-dir build
```

(ajuste conforme sua estrutura de testes)
