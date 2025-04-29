# Configurando o vcpkg no seu projeto C++

Este guia mostra como configurar o [vcpkg](https://github.com/microsoft/vcpkg), o gerenciador de pacotes da Microsoft para C++, e instalar dependências no seu projeto.

---

## ✅ Passo 1: Acesse a pasta do seu projeto

```bash
cd /caminho/para/seu/projeto
```

---

## ✅ Passo 2: Clone o repositório do `vcpkg`

Na raiz do seu projeto, clone o repositório oficial do `vcpkg`:

```bash
git clone https://github.com/microsoft/vcpkg.git
```

---

## ✅ Passo 3: Execute o script de bootstrap do vcpkg

Entre na pasta do `vcpkg` e execute o script de inicialização:

```bash
cd vcpkg
./bootstrap-vcpkg.sh
```

> 💡 Para usuários Windows, o script equivalente é `bootstrap-vcpkg.bat`.

---

## ✅ Passo 4: Instale as dependências do seu projeto

Agora que o `vcpkg` está pronto, você pode instalar as bibliotecas externas que seu projeto utiliza.  
Por exemplo, para instalar o Google Test:

```bash
./vcpkg/vcpkg install gtest
```

> 📦 Substitua `gtest` pelo nome da biblioteca que você deseja instalar.

---

## 🔗 Links úteis

- Repositório oficial do vcpkg: [https://github.com/microsoft/vcpkg](https://github.com/microsoft/vcpkg)
- Lista de pacotes disponíveis: [vcpkg packages](https://vcpkg.io/en/packages.html)
