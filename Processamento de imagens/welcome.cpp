/*
 * Copyright (c) 2009-2010, Oracle and/or its affiliates. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Oracle nor the names of its contributors
 *   may be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <iostream>
#include <string.h>
#include "Imagens_Funções.h"
using namespace std;


int main(int argc, char**argv) {
    int **mat, **mat_aux, lin , col, limit;
    char path[30];
    mat = LEIMAGEM(argv[1], &lin, &col, &limit);
    mat_aux = ICONIZAR(mat, lin, col, limit);
    strncpy(path, "ICONE.pgm", 15);
    PASSAIMAGEM(mat_aux, 64, 64, limit, path);
    mat_aux = ELIMINAR_RUIDOS(mat, lin, col, limit);
    strncpy(path, "ELIMINAR_RUIDOS.pgm", 19);
    PASSAIMAGEM(mat_aux, lin, col, limit, path);
    mat_aux = ESCURECER_BORDAS(mat, lin, col, limit);
    strncpy(path, "ESCURECER_BORDAS.pgm", 20);
    PASSAIMAGEM(mat_aux, lin, col, limit, path);
    DESALOCAR(mat, lin);
    cout << endl << "Imagens geradas com sucesso!" << endl;

    return 0;
}
