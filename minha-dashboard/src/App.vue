<script setup>
import { RouterView } from 'vue-router';
import Dashboard from './components/Dashboard.vue';
</script>

<template>
  <v-app>
    <v-main>
      <Dashboard />
    </v-main>
  </v-app>
  <RouterView />
</template>

<style scoped></style>
