/* 
 * File:   vetor.h
 * Author: gregorio
 *
 * Created on 20 de Junho de 2019, 15:18
 */

#ifndef VETOR_H
#define	VETOR_H

class vetor{
    public :
        vetor(int t, int tipo);
        ~vetor();
        void show();
        
        
    private:
        int *v;
        int tamanho;
        int NAleatorio(int maxi);
        void preencher(int *p,int t,int tipo);
};

#endif	/* VETOR_H */

