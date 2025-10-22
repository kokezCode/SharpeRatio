#include <stdio.h>
#include <stdlib.h>

// Sharpe Orani'ni hesaplayan fonksiyon
double sharpe_oran_hesapla(double getiri, double risksiz_faiz, double standart_sapma) {
    if (standart_sapma == 0.0) {
        fprintf(stderr, "Hata: Standart Sapma sifir olamaz!\n");
        return -1.0; // Negatif deger, matematiksel hata olustugunu ifade eder
    }
    
    // Sharpe Oran formulu
    return (getiri - risksiz_faiz) / standart_sapma;
}

int main() {
    double yatirim_getirisi;
    double risksiz_faiz_orani;
    double standart_sapma;
    double sharpe_oran;
    
    printf("--- Sharpe Orani Hesaplama ---\n");
    printf("Nicel Analizin Temel Olcutu: Risk Basina Fazla Getiri\n\n");
    
    printf("1- Yatirim Getirisi (%% olarak): ");
    if(scanf("%lf", &yatirim_getirisi) != 1) {
        printf("Geçersiz giris.\n");
        return 1;
    }
    
    printf("2- Risksiz Faiz Orani (%% olarak): "); 
    if(scanf("%lf", &risksiz_faiz_orani) != 1) {
        printf("Geçersiz giris.\n");
        return 1;
    }
    
    printf("3- Standart Sapma (%% olarak): ");
    if(scanf("%lf", &standart_sapma) != 1) {
        printf("Geçersiz giris.\n");
        return 1;
    }
    
    // Ondalik formata dönüstürme
    double R_p = yatirim_getirisi / 100.0;
    double R_f = risksiz_faiz_orani / 100.0;
    double Sigma_p = standart_sapma / 100.0;
    
    // Sharpe Orani'ni hesaplama
    sharpe_oran = sharpe_oran_hesapla(R_p, R_f, Sigma_p);
    
    printf("\n---Sonuc---\n");
    
    // Hata kontrolü
    if(sharpe_oran == -1.0) {
        printf("Sharpe Orani hesaplanamadi. Lutfen standart sapmayi 0'dan farkli giriniz.\n"); 
    }
    else {
        printf("Sharpe Orani : %.4f\n", sharpe_oran);
        
        printf("\n---Degerlendirme---\n");
        
        if (sharpe_oran >= 3.0) {
            printf("Sonuc: MUKEMMEL - Birim risk basina getirisi yuksek.\n");
        }
        else if(sharpe_oran >= 2.0) {
            printf("Sonuc: ÇOK IYI - Yatirim performansi riskine göre ust düzeyde.\n");
        }
        else if(sharpe_oran>= 1.0){
            printf("Sonuc: IYI - Yatirim, riskine gore kabul edilebilirin ustunde getiri saglamis.\n");
        }
        else if(sharpe_oran >= 0.0) {
            printf("Sonuc: KABUL EDILEBILIR - Risksiz faiz oranindan daha iyi performans sergilenmis.\n");
        }
        else {
            printf("Sonuc: KOTU - Yatirim risksiz faiz oraninin bile altinda getiri saglamis (Negatif Ek Getiri).\n");
        }
        printf("\nBu deger, aldiginiz her birim risk için elde ettiginiz %.4f birim fazla (risksizden fazla) getiriyi gosterir.\n", sharpe_oran);
    }
    
    return 0;
}





