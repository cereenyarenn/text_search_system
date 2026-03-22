#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Büyük harfleri küçültüyoruz.
void kucukHarfeCevir(char *hedef, const char *kaynak) {
    int i = 0;
    // Kelimenin sonuna \0 gelene kadar harf harf ilerliyoruz. Bu sembol kelimenin bitiğini belirtiyor.
    while (kaynak[i] != '\0') {
        hedef[i] = tolower((unsigned char)kaynak[i]); 
        i++;
    }
    hedef[i] = '\0'; // Yeni kelimenin bittiğini belirtiyoruz.
}

// Dosya işlemleri kısmı
void dosyadaKelimeAra(const char* girdiDosyaAdi, const char* ciktiDosyaAdi, const char* aranacakKelime) {
    // Dosyaları açıyoruz (r: read/okuma, w: write/yazma)
    FILE *girdiDosya = fopen(girdiDosyaAdi, "r");
    FILE *ciktiDosya = fopen(ciktiDosyaAdi, "w");

    if (girdiDosya == NULL) {
        printf("HATA: %s dosyasi acilamadi. Klasoru kontrol edin.\n", girdiDosyaAdi);
        return;
    }
    if (ciktiDosya == NULL) {
        printf("HATA: %s sonuc dosyasi olusturulamadi.\n", ciktiDosyaAdi);
        fclose(girdiDosya);
        return;
    }

    fprintf(ciktiDosya, "METIN ARAMA MOTORU RAPORU\n\n");
    fprintf(ciktiDosya, "Aranan Kelime: %s \n", aranacakKelime);
    fprintf(ciktiDosya, "Taranan Dosya: %s \n", girdiDosyaAdi);
    fprintf(ciktiDosya, "----------------------------------\n\n");

    int toplamEslesme = 0;
    int satirNumarasi = 0;
    char satir[1024]; 
    char kucukSatir[1024]; 
    char kucukAranan[1024];

    kucukHarfeCevir(kucukAranan, aranacakKelime);

    // Dosyayı satır satır okuyan döngü
    while (fgets(satir, sizeof(satir), girdiDosya) != NULL) {
        satirNumarasi++;
        kucukHarfeCevir(kucukSatir, satir);

        // Satırın içinde kelimeyi arıyoruz.
        char *bulunanYer = strstr(kucukSatir, kucukAranan);

        // Eğer kelime bulunursa (NULL değilse) bu döngüye giriyor.
        while (bulunanYer != NULL) {
            toplamEslesme++;
            fprintf(ciktiDosya, "%d. Eslesme: Satir %d'de bulundu.\n", toplamEslesme, satirNumarasi);

            // Kelimeyi bulduğumuz yerden, kelimenin uzunluğu kadar ileri atlıyoruz.
            bulunanYer = strstr(bulunanYer + strlen(kucukAranan), kucukAranan);
        }
    }

    fprintf(ciktiDosya, "\n---------------------\n");
    fprintf(ciktiDosya, "Toplam bulunan eslesme sayisi: %d \n", toplamEslesme);

    printf("Arama tamamlandi. Sonuclar %s dosyasina kaydedildi.\n", ciktiDosyaAdi);

    fclose(girdiDosya);    
    fclose(ciktiDosya); 
}

// Main fonksiyon
int main() {
    char arananKelime[1024];
    char girdiDosyaAdi[1024];
    char ciktiDosyaAdi[] = "arama_raporu.txt"; 

    printf("Metin Arama Motoruna Hos Geldiniz!\n\n");

    printf("Lutfen aramak istediginiz kelimeyi girin: ");
    scanf("%1023s", arananKelime);

    printf("Lutfen taranacak metin dosyasinin adini girin (Ornek: metin.txt): ");
    scanf("%1023s", girdiDosyaAdi);

    printf("\nArama baslatiliyor...\n");

    dosyadaKelimeAra(girdiDosyaAdi, ciktiDosyaAdi, arananKelime);

    return 0;
}
