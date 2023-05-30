
/* Trabalho Prático 1 - Disciplina AEDS 2 - UFV CAF
 * Integrantes:
 * Ana Carolina Fernandes - 5094
 * Bárbara Pagnocca - 5061
 * Jéssica Cristina Carvalho - 4686
 * Layon Fonseca Martins - 4220
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#include "../Tratamento_Arquivos/TratamentoDeArquivos.h"
#include "../Patricia/Patricia.h"


GtkTreeIter *iter;
GtkListStore *modelo;

GtkBuilder *builder;
GtkWidget  *window;
GtkStack   *stack;
GtkListStore *modelo;
GtkListStore *modelo2;
GtkTextView *view;
GtkDialog *mensagem_dialogo;

Aptd_Pat A = NULL;

void botao_construir_indice_invertido_clicked_cb (GtkWidget *widget, gpointer data){ 
    gtk_stack_set_visible_child_name(stack, "view_construir_indice");
}  

 void on_tela_principal_destroy(GtkWidget *window, gpointer data){
    gtk_main_quit();
  }

void botao_inserir_arquivo_clicked_cb (GtkWidget *widget, gpointer data){
     char *arquivo_entrada = gtk_entry_get_text(gtk_builder_get_object(builder, "entry_nome_arquivo"));
     lerPalavras(&A);
    gtk_stack_set_visible_child_name(stack, "view_construir_indice");
}  

void botao_imprimir_indice_clicked_cb(GtkWidget *widget, gpointer data){
    gtk_stack_set_visible_child_name(stack, "view_imprimir_indice");
}

void botao_imprimir_clicked_cb(GtkWidget *widget, gpointer data){
    ImprimeEmOrdem(A);
    gtk_stack_set_visible_child_name(stack, "view_imprimir_indice");
}

void botao_buscar_na_patricia_clicked_cb(GtkWidget *widget, gpointer data){ 
    gtk_stack_set_visible_child_name(stack, "view_buscar_patricia");
}  



void botao_voltar_indice_clicked_cb(GtkWidget *widget, gpointer data){ //voltar para o menu
   gtk_stack_set_visible_child_name(stack, "view_menu");
}  


void botao_voltar_imprimir_indice_clicked_cb(GtkWidget *widget, gpointer data){ //voltar para o menu
    gtk_stack_set_visible_child_name(stack, "view_menu");
} 

void botao_voltar_patricia_clicked_cb(GtkWidget *widget, gpointer data){ //voltar para o menu
   gtk_stack_set_visible_child_name(stack, "view_menu");
}  

void botao_pesquisar_clicked_cb(GtkWidget *widget, gpointer data){ // pesquisar na patricia
   gtk_list_store_clear(modelo);
   modelo = GTK_LIST_STORE(gtk_builder_get_object(builder, "lista_patricia"));
   char *palavra = gtk_entry_get_text(gtk_builder_get_object(builder, "pesquisar_palavra"));
   if(Pesquisa(*palavra, A)!= NULL){
        gtk_list_store_append(modelo, &iter);
   }
   
   gtk_stack_set_visible_child_name(stack, "view_buscar_patricia");
} 
void botao_imprimir_indice_invertido_clicked_cb(GtkWidget *widget, gpointer data){
  gtk_list_store_clear(modelo);
  modelo = GTK_LIST_STORE(gtk_builder_get_object(builder, "list_indice_imprimir"));
  gtk_stack_set_visible_child_name(stack, "view_imprimir_indice");
}


int main(int argc, char *argv[]){

    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("interface_grafica.glade");

    gtk_builder_add_callback_symbols(
        builder,
        "on_tela_principal_destroy",                  G_CALLBACK(on_tela_principal_destroy),
        "botao_construir_indice_invertido_clicked_cb",G_CALLBACK(botao_construir_indice_invertido_clicked_cb),
        "botao_inserir_arquivo_clicked_cb",           G_CALLBACK(botao_inserir_arquivo_clicked_cb),
        "botao_imprimir_indice_invertido_clicked_cb", G_CALLBACK(botao_imprimir_indice_invertido_clicked_cb),
        "botao_imprimir_clicked_cb",                  G_CALLBACK(botao_imprimir_clicked_cb),
        "botao_buscar_na_patricia_clicked_cb",        G_CALLBACK(botao_buscar_na_patricia_clicked_cb),
        "botao_pesquisar_clicked_cb",                 G_CALLBACK(botao_pesquisar_clicked_cb),
        "botao_voltar_patricia_clicked_cb",           G_CALLBACK(botao_voltar_patricia_clicked_cb),
        "botao_voltar_indice_clicked_cb",             G_CALLBACK(botao_voltar_indice_clicked_cb),
        "botao_voltar_imprimir_indice_clicked_cb",    G_CALLBACK(botao_voltar_imprimir_indice_clicked_cb),
        "botao_imprimir_indice_clicked_cb",           G_CALLBACK(botao_imprimir_indice_clicked_cb),
         NULL);



    gtk_builder_connect_signals(builder, NULL);
    stack = GTK_STACK(gtk_builder_get_object(builder, "stack"));
    window = GTK_WIDGET(gtk_builder_get_object(builder, "tela_principal"));
    gtk_widget_show_all(window);

    gtk_main();


    //ImprimeEmOrdem(A);
    
    return 0;
}