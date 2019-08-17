Token reconocerToken(void){
    estado=INICIAL;
    while !pararSegun(estado){
        char caracter = leerCaracter();
        estado = matEstados[estado][caracter];
    }
    if elEstadoEsAceptor(estado){
        if charCentinela(caracter, estado);
            unput(caracter);
        Token tok charCentinela= retornarToken(estado);
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

bool charCentinela(caracter){
    if (estado == (...))
        return caracter == (...);
    if (estado == (...))
        return caracter == (...);
    return false;
}

Token retornarToken(estado){
    switch estado{
    case 1,2,3,4:
        return ID;
        break;
    case 5,6,7,8:
        return CTE;
        break;
    default:
        return BUG;
    }
}

void imprimirDatos(void){
    printf("%d", "La cantidad de identificadores fue: " +cantidadIdentificadores +
           "\nLa cantidad de errores fue: " + cantidadErrores + "\nLa cantidad de constantes fue: " + cantidadConstantes);
}

