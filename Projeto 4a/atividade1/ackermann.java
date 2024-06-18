// Discente Maria Eduarda Guedes Alves

package atividade1;

public class Ackermann {
    public static void main(String[] args) {
        int i=3, m, n, p, R;
        boolean ok=false;
        double tEmMilSeg=0, tGasto;
        long t;

        for (m=0; m<i && ok!=true; m++) {
            for (n=0; n<i && ok!=true; n++) {
                for (p=0; p<i && ok!=true; p++) {
                    t = System.currentTimeMillis();
                    R = ack(m, n, p);
                    t = System.currentTimeMillis()-t;

                    tGasto = (double)t / 1000;  // Tempo gasto em milissegundos
                    tEmMilSeg += tGasto;

                    System.out.printf("\nTempo gasto nesta chamada: %.6f ms", tGasto);
                    System.out.printf("\nTempo acumulado: %.6f ms", tEmMilSeg);
                    System.out.printf("\nack(%d, %d, %d): %d\n", m, n, p, R);

                    if (tEmMilSeg >= 60000) ok = true;  // Se passar de menos de 1 minuto
                }
            }
        }
    }

    public static int ack(int m, int n, int p) {
        if (m>=0 && n>=0 && p>=0) {
            if (p==0) return m + n;
            else if (n==0 && p==1) return 0;
            else if (n==0 && p==2) return 1;
            else if (n==0 && p>2) return p;
            else if (n>0 && p>0) return ack(m, ack(m, n-1, p), p-1);
        } else {
            System.out.println("Foi informado algum valor invalido!\n\n");
            System.exit(-1);
        }
        return -1;  
    }
}
