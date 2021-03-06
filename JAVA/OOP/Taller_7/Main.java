import java.io.IOException;
import java.util.*;

public class Main {
  public static void main(String[] args){

    ArrayList<Animal> animales = new ArrayList<Animal>(); 

    while(true){

      System.out.println("Bienvenido al Zoologico de Javed City, a continuacion digite la opcion que desea realizar: ");

      System.out.println("1. Obtener informacion de un animal");
      System.out.println("2. Registrar un nuevo animal");
      System.out.println("99. Salir del programa");

      Scanner sc = new Scanner(System.in);
      int option = Integer.parseInt(sc.nextLine());

      clearScreen();
    
      if(option == 1){ //Obtiene informacion de un animal

        Animal animalSeleccionado = selectFromArrayList(animales);
        
        System.out.println("Has elegido a " + animalSeleccionado.nombre);
        System.out.println("La informacion se mostrara a continuacion: ");
        animalSeleccionado.completeInfo();

        sc.nextLine();

      }
      
      clearScreen();

      if (option == 2) { //Registra un nuevo animal
        
        System.out.print("Inserte el nombre del animal: ");
        String nombre = sc.nextLine();

        System.out.print("Inserte el tamanio del animal: ");
        String tamanio = sc.nextLine();

        System.out.print("Inserte la cantidad de ojos del animal: ");
        int ojos = Integer.parseInt(sc.nextLine());

        System.out.print("Inserte la edad del animal: ");
        int edad = Integer.parseInt(sc.nextLine());

        System.out.print("Inserte la raza del animal: ");
        String raza = sc.nextLine();

        clearScreen();

        System.out.println("Seleccione el tipo de animal que desea registrar: ");

        System.out.println("1. Mamifero");
        System.out.println("2. Anfibio");
        System.out.println("3. Ave");
        System.out.println("4. Reptil");
        System.out.println("5. Pez");

        int opt = Integer.parseInt(sc.nextLine());

        clearScreen();

        if(opt == 1){
          System.out.println("Seleccione el tipo de mamifero que desea registrar: ");

          System.out.println("1. Canino");
          System.out.println("2. Felino");

          int op = Integer.parseInt(sc.nextLine());

          clearScreen();

          System.out.println("Toma leche? 1 = SI, otro numero = NO");
          int opLeche = Integer.parseInt(sc.nextLine());

          Boolean tomaLeche;

          if (opLeche == 1) {
            tomaLeche = true;
          } else { tomaLeche = false; }

            if(op == 1){
              
              Canino fido = new Canino(tamanio, ojos, raza, nombre, edad, tomaLeche);
              animales.add(fido);

            }

            if(op == 2){
              
              clearScreen();

              System.out.println("Tiene pelo? 1 = SI, Resto de numeros = NO");
              int alPelo = Integer.parseInt(sc.nextLine());

              Boolean pelo;

              if (alPelo == 1) {
                pelo = true;
              } else { pelo = false; }

              clearScreen();

              Felino michi = new Felino(tamanio, ojos, edad, raza, nombre, pelo, tomaLeche);
              animales.add(michi);

            }
        }

        if (opt == 2) {

          Anfibio sop = new Anfibio(tamanio, ojos, edad, raza, nombre);
          animales.add(sop);

        }

        if (opt == 3) {

          Ave fufu = new Ave(tamanio, ojos, edad, raza, nombre);
          animales.add(fufu);
          
        }

        if (opt == 4) {

          Reptil sis = new Reptil(tamanio, ojos, edad, raza, nombre);   
          animales.add(sis);       
          
        }

        if (opt == 5) {
          
          Pez pip = new Pez(tamanio, ojos, edad, raza, nombre);
          animales.add(pip);

        }

      }


      if (option == 99) {
        System.exit(0);
      }

      clearScreen();


    }

    
    
  }

  public static <Obj> Obj selectFromArrayList(ArrayList<Obj> list){

    if (list.isEmpty()) {
      System.out.println("Lista vacia, saliendo . . .");
      return null;
    }

    Scanner tmpsc = new Scanner(System.in);

    for (Obj var : list) {
      System.out.println((list.indexOf(var)+1) +". "+ var.toString());
    }

    System.out.println();
    System.out.print("Inserte su opcion: ");
    int opt = Integer.parseInt(tmpsc.nextLine());
    
    return list.get(opt-1);
  }
  
  public static void clearScreen(){

    try {
      if (System.getProperty("os.name").contains("Windows"))
        new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
      else
        Runtime.getRuntime().exec("clear");
    } catch (IOException | InterruptedException ex) {}
  }

}