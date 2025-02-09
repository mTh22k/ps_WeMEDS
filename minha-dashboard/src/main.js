import { createApp } from 'vue';
import App from './App.vue';
import { createVuetify } from 'vuetify';
import 'vuetify/styles';
import '@mdi/font/css/materialdesignicons.css'; // Adicione esta linha para garantir que os ícones sejam carregados

const vuetify = createVuetify({
  icons: {
    iconfont: 'mdi', // Aqui você configura para usar o MDI como ícone
  },
});

createApp(App).use(vuetify).mount('#app');
