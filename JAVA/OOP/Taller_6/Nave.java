class Nave {

    protected int precioPorDia = 50;
    private String matriculaNave;

    Nave(String matricula){

        this.matriculaNave = matricula;
    }

    public double precioAlquiler(int dias){
        
        return dias * precioPorDia;
    }

    public String getMatricula() {
        return matriculaNave;
    }
}