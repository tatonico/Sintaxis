
enum Token{ID, BUG, CTE};

Token reconocerToken(void){
    estado=INICIAL;
    while !pararSegun(estado){
        char caracter = leerCaracter();
        estado = matEstados[estado][caracter];
    }
    if elEstadoEsAceptor(estado){
        if charCentinela(caracter);
            unput(caracter);
        Token tok = retornarToken(estado);
        switch tok{
            case ID:
                cantidadIdentificadores++;
                break;
            case CTE:
                cantidadConstantes++;
                break;
        }
    } else {
        error(estado, caracter);
        Token tok = BUG;
        cantidadErrores++;
    }
    return tok;
}

void imprimirDatos(void){
    printf("%d", "La cantidad de identificadores fue: " +cantidadIdentificadores +
           "\nLa cantidad de errores fue: " + cantidadErrores + "\nLa cantidad de constantes fue: " + cantidadConstantes);
}

