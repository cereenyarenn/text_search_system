#include <stdio.h>
#include <stdlib.h>

int main() {
    char arananKelime[1024];
    char girdiDosyaAdi[1024];
    char ciktiDosyaAdi[] = "arama_raporu.txt"; 
    printf("Metin Arama Motoruna Hos Geldiniz!\n\n");

    printf("Lutfen aramak istediginiz kelimeyi girin: ");
    scanf("%1023s", arananKelime);

    printf("Lutfen taranacak metin dosyasinin adini girin (metin.txt): ");
    scanf("%1023s", girdiDosyaAdi);

    printf("\nArama baslatiliyor...\n");
    
    dosyadaKelimeAra(girdiDosyaAdi, ciktiDosyaAdi, arananKelime);

    printf("\nIslem tamamlandi! Klasordeki '%s' dosyasina bakiniz.\n", ciktiDosyaAdi);

    return 0;
}
