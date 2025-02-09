# Minha Dashboard

Este é um projeto de dashboard desenvolvido com Vue 3, Vuetify e Vite, utilizando um backend simples com `db.json`.

## Requisitos

Antes de iniciar, certifique-se de ter instalado:
- [Node.js](https://nodejs.org/) (versão recomendada: 18 ou superior)
- [npm](https://www.npmjs.com/) (gerenciador de pacotes do Node.js)

2. Acesse a pasta do projeto:
   ```sh
   cd minha-dashboard
   ```
3. Instale as dependências:
   ```sh
   npm install
   ```

## Rodando o projeto

### Frontend

Para iniciar o frontend em ambiente de desenvolvimento, utilize:
```sh
npm run dev
```

O projeto será iniciado em `http://localhost:5173/` (ou outra porta disponível).

### Backend (JSON Server)

Se o projeto utilizar `db.json` como backend, instale o JSON Server globalmente (se ainda não tiver):
```sh
npm install -g json-server
```

Então, inicie o servidor JSON:
```sh
json-server --watch db.json --port 3000
```

O backend estará rodando em `http://localhost:3000/`.


