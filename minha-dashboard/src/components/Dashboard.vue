<template>
  <v-container fluid class="pa-0">

    <v-row class="ma-0">

      <!-- Coluna à esquerda -->
      <v-col cols="12" sm="6">
        <v-card class="pa-4 bg-grey-darken-1" width="100%">
          <div>
            <v-btn @click="dialog = true" style="margin: 3px; display: flex" variant="outlined"
              >➕ Add Paciente</v-btn
            >
            <v-card-title style="font-size: 30px" class="d-flex justify-center"
              >Em andamento</v-card-title
            >
          </div>
          <v-list class="bg-grey-darken-1">
            <v-list-item v-for="paciente in pacientes.filter((t) => t.status === true)" :key="paciente.id">
                <!-- Card de cada paciente -->
              <v-card
                class="bg-amber-lighten-2"
                style="
                  display: flex;
                  justify-content: space-between;
                  align-items: center;
                  padding: 20px;
                "
              >
                <div>
                  <v-list-item-title style="font-size: 22px">{{ paciente.nome }}</v-list-item-title>
                  <v-list-item-subtitle style="font-size: 15px"
                    >Sexo: {{ paciente.sexo }}</v-list-item-subtitle
                  >
                  <v-list-item-subtitle style="font-size: 15px"
                    >Idade: {{ paciente.idade }}</v-list-item-subtitle
                  >
                  <v-list-item-subtitle style="font-size: 15px"
                    >Contato: {{ paciente.contato }}</v-list-item-subtitle
                  >
                </div>
                <div class="d-flex flex-row">
                  <div>
                    <v-btn
                      size="large"
                      density="compact"
                      icon="$vuetify"
                      style="margin: 3px; padding: 0"
                      @click="deletePatient(paciente.id)"
                      variant="text"
                    >
                      <v-icon left color="error">mdi-delete</v-icon>
                    </v-btn>
                    <v-btn
                      size="large"
                      density="compact"
                      icon="$vuetify"
                      style="margin: 3px"
                      variant="text"
                      @click="viewPatient(paciente)"
                    >
                      <v-icon left>mdi-eye</v-icon>
                    </v-btn>
                  </div>
                  <div>
                    <v-btn color="amber-lighten-3" style="margin: 3px" @click="finalizeStatus(paciente)">
                      <v-icon left color="success" style="margin-right: 10px"
                        >mdi-check-circle-outline</v-icon
                      >
                      Finalizar
                    </v-btn>
                  </div>
                </div>
              </v-card>
            </v-list-item>
          </v-list>
        </v-card>
      </v-col>

      <!-- Coluna à direita -->
      <v-col cols="12" sm="6">
        <v-card class="pa-4 bg-grey-darken-1" width="100%">
          <div>
            <v-btn @click="dialog = true" style="margin: 3px; display: flex" variant="outlined"
              >➕ Add Paciente</v-btn
            >
            <v-card-title style="font-size: 30px" class="d-flex justify-center"
              >Finalizado</v-card-title
            >
          </div>
          <v-list class="bg-grey-darken-1">
            <v-list-item v-for="paciente in pacientes.filter((t) => t.status === false)" :key="paciente.id">
                <!-- Card de cada paciente -->
              <v-card
                class="bg-amber-lighten-2"
                style="
                  display: flex;
                  justify-content: space-between;
                  align-items: center;
                  padding: 20px;
                "
              >
                <div>
                  <v-list-item-title style="font-size: 22px">{{ paciente.nome }}</v-list-item-title>
                  <v-list-item-subtitle style="font-size: 15px"
                    >Sexo: {{ paciente.sexo }}</v-list-item-subtitle
                  >
                  <v-list-item-subtitle style="font-size: 15px"
                    >Idade: {{ paciente.idade }}</v-list-item-subtitle
                  >
                  <v-list-item-subtitle style="font-size: 15px"
                    >Contato: {{ paciente.contato }}</v-list-item-subtitle
                  >
                </div>
                <div class="d-flex flex-row">
                  <div>
                    <v-btn
                      size="large"
                      density="compact"
                      icon="$vuetify"
                      style="margin: 3px"
                      @click="deletePatient(paciente.id)"
                      variant="text"
                    >
                      <v-icon left color="error">mdi-delete</v-icon>
                    </v-btn>
                    <v-btn
                      size="large"
                      density="compact"
                      icon="$vuetify"
                      style="margin: 3px"
                      variant="text"
                      @click="viewPatient(paciente)"
                    >
                      <v-icon left>mdi-eye</v-icon>
                    </v-btn>
                  </div>
                  <div>
                    <v-btn
                      style="margin: 3px"
                      color="amber-lighten-3"
                      @click="revertStatus(paciente)"
                    >
                      <v-icon left color="error" style="margin-right: 10px"
                        >mdi-close-circle-outline</v-icon
                      >
                      Voltar
                    </v-btn>
                  </div>
                </div>
              </v-card>
            </v-list-item>
          </v-list>
        </v-card>
      </v-col>
    </v-row>

    <!-- Modal para add paciente -->
    <v-dialog v-model="dialog" width="500">
      <v-card class="bg-grey-darken-4">
        <v-card-title class="headline">Adicionar Paciente</v-card-title>
        <v-card-text>
          <v-text-field label="Nome" v-model="newPatient.nome" required></v-text-field>
          <v-text-field
            label="Idade"
            type="number"
            v-model="newPatient.idade"
            required
          ></v-text-field>
          <v-select
            label="Sexo"
            :items="['Masculino', 'Feminino', 'Outro']"
            v-model="newPatient.sexo"
            required
          ></v-select>
          <v-text-field label="Contato" v-model="newPatient.contato" required></v-text-field>
        </v-card-text>
        <v-card-actions>
          <v-btn color="red" @click="dialog = false">Cancelar</v-btn>
          <v-btn color="green" @click="addPatient">Salvar</v-btn>
        </v-card-actions>
      </v-card>
    </v-dialog>

    <!-- Modal de ver mais do paciente -->
    <v-dialog v-model="viewDialog" width="500">
      <v-card v-if="selectedPatient" class="bg-grey-darken-4">
        <v-card-title class="headline d-flex justify-center" style="font-size: 25px"
          >Detalhes do Paciente</v-card-title
        >
        <v-card-text>
          <v-list-item>
            <v-list-item-content>
              <v-list-item-title style="font-size: 20px">{{
                selectedPatient.nome
              }}</v-list-item-title>
              <v-list-item-subtitle style="font-size: 15px"
                >Sexo: {{ selectedPatient.sexo }}</v-list-item-subtitle
              >
              <v-list-item-subtitle style="font-size: 15px"
                >Idade: {{ selectedPatient.idade }}</v-list-item-subtitle
              >
              <v-list-item-subtitle style="font-size: 15px"
                >Contato: {{ selectedPatient.contato }}</v-list-item-subtitle
              >
            </v-list-item-content>
          </v-list-item>
        </v-card-text>
        <v-card-actions>
          <v-btn color="blue" @click="viewDialog = false">Fechar</v-btn>
        </v-card-actions>
      </v-card>
    </v-dialog>
  </v-container>
</template>

<script setup>
import { ref, onMounted } from 'vue';

// Armazena a lista de tarefas carregadas da API
const pacientes = ref([]);

// Controla a visibilidade do modal de adição de paciente
const dialog = ref(false);

// Controla a visibilidade do modal de visualização de paciente
const viewDialog = ref(false);

// Armazena os detalhes do paciente selecionado para exibição
const selectedPatient = ref(null);

// Objeto que armazena os dados do novo paciente a ser cadastrado
const newPatient = ref({
    nome: '',
    idade: '',
    sexo: '',
    contato: '',
    status: true
});

// Busca os dados da API quando o componente é montado
onMounted(async () => {
    try {
        const res = await axios.get('http://localhost:3000/tarefas');
        pacientes.value = res.data;
    } catch (error) {
        console.error("Erro ao buscar tarefas:", error);
    }
});

// Adiciona um novo paciente 
const addPatient = async () => {
    try {
        const res = await axios.post('http://localhost:3000/tarefas', newPatient.value);
        pacientes.value.push(res.data);
        dialog.value = false;
        newPatient.value = { nome: '', idade: '', sexo: '', contato: '', status: true };
    } catch (error) {
        console.error("Erro ao adicionar paciente:", error);
    }
};

// Define o paciente selecionado e exibe o modal de detalhes
const viewPatient = (patient) => {
    selectedPatient.value = patient;
    viewDialog.value = true;
};

// Solicita uma confirmação e exclui um paciente da lista e da API
const deletePatient = async (id) => {
    if (confirm("Tem certeza que deseja excluir este paciente?")) {
        try {
            await axios.delete(`http://localhost:3000/tarefas/${id}`);
            pacientes.value = pacientes.value.filter(paciente => paciente.id !== id);
        } catch (error) {
            console.error("Erro ao excluir tarefa:", error);
        }
    }
};

// Altera o status do paciente para 'finalizado' e atualiza a API
const finalizeStatus = async (paciente) => {
    try {
        paciente.status = false;
        await axios.put(`http://localhost:3000/tarefas/${paciente.id}`, paciente);
    } catch (error) {
        console.error("Erro ao finalizar tarefa:", error);
    }
};

// Reverte o status do card
const revertStatus = async (paciente) => {
    try {
        paciente.status = true;
        await axios.put(`http://localhost:3000/tarefas/${paciente.id}`, paciente);
    } catch (error) {
        console.error("Erro ao reverter tarefa:", error);
    }
};
</script>

<style scoped>
.v-card {
  margin-bottom: 20px;
}

.wrapper {
  background-color: antiquewhite;
}

.visualizer-container {
  background-color: rgb(150, 85, 0);
}

.form-container {
  background-color: rgb(224, 12, 129);
}
</style>
