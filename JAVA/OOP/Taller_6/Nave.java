class Nave {

    protected int precioPorDia = 50;
    private String matriculaNave;
    protected String modeloNave;

    Nave(String matricula){

        this.matriculaNave = matricula;
    }

    public double precioAlquiler(int dias){
        
        return dias * precioPorDia;
    }

    public String getMatricula() {
        return matriculaNave;
    }

    public String getModeloNave(){
        return modeloNave;
    }
}