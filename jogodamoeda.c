#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gtk/gtk.h>

// Função para gerar o resultado do lançamento da moeda
const char* lancarMoeda() {
    int resultado = rand() % 2; // Gera um número aleatório 0 ou 1
    
    if (resultado == 0) {
        return "Cara";
    } else {
        return "Coroa";
    }
}

// Função de callback para o clique do botão
void on_button_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *label = GTK_WIDGET(data);
    
    const char* resultado = lancarMoeda(); // Obter o resultado do lançamento
    
    // Atualizar o texto do rótulo com o resultado do lançamento
    gtk_label_set_text(GTK_LABEL(label), resultado);
}

int main(int argc, char *argv[]) {
    // Inicializar o GTK
    gtk_init(&argc, &argv);

    // Criar uma janela
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Jogo da Moeda");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Criar um layout vertical e adicionar à janela
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Criar um rótulo para exibir o resultado do lançamento da moeda
    GtkWidget *label = gtk_label_new("Resultado");
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);

    // Criar um botão para lançar a moeda
    GtkWidget *button = gtk_button_new_with_label("Lançar Moeda");
    gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 0);
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), label);

    // Exibir todos os widgets
    gtk_widget_show_all(window);

    // Inicializar o gerador de números aleatórios
    srand(time(NULL));

    // Entrar no loop principal do GTK
    gtk_main();

    return 0;
}
